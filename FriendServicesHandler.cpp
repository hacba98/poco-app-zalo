/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FriendServicesHandler.cpp
 * Author: cpu10855
 * 
 * Created on May 22, 2019, 5:18 PM
 */

#include "FriendServicesHandler.h"

using namespace std;
using namespace Poco;
using namespace Poco::Util;

using apache::thrift::to_string;

FriendServicesHandler::FriendServicesHandler(): _convert_user() {
	// get current application instance and it's subsystems
	// _app = Application::instance();
	// _kc = Application::instance().getSubsystem<SubKC>();
}

FriendServicesHandler::FriendServicesHandler(const FriendServicesHandler& orig) {
}

FriendServicesHandler::~FriendServicesHandler() {
	//_app.release();
	//_kc.release();
}

// Implements basic API
int32_t FriendServicesHandler::CreateUser(const InputProfileData& profile){
	Application::instance().logger().information("Incoming register request.");
	
	// check data
	if (!profile.__isset.name || !profile.__isset.isMale || !profile.__isset.birthDate || !profile.__isset.phoneNumber)
		return -1;

	// initialize some variables
	User newUser;
	int32_t id = _kc.generateUserId();
	string id_str = to_string(id);
	
	newUser.id = id;
	newUser.isMale = profile.isMale;
	newUser.birthDate = profile.birthDate;
	newUser.name = profile.name;
	newUser.phoneNumber = profile.phoneNumber;
	newUser.lastActive = 0;
	
	// serialize
	std::string value;
	_convert_user.serialize(newUser, value);
		
	// store to DB - TODO: Improvement 
	// should implement notification queue
	// then only call store and put notifications to the queue
	// let workers in SubKC subsystem do the rest
	// that also meet the async API requirements
	// old version - w/o notification queue
	//_kc.storeUser(id_str, value);
	// new version - implemented notification queue
	_kc.store(id_str, value, SubKC::DB_TYPE::USER);
	
	// also store in cache
	_cache.putAsync<string, User>("friend.cache.user", id_str, newUser);
	
	// log 
	Application::instance().logger().information(Logger::format("User register successfully. User's id: $0", id_str));
	
	return id;
}

void FriendServicesHandler::GetUserInformation(GetUserResult& _return, const int32_t id){
	Application::instance().logger().information("Incoming get data request.");
	
	// initialize
	User user_;
	string id_str = to_string(id);
	string value;
	
	// check in cache
	if (_cache.get<string, User>("friend.cache.user", id_str, user_)){
		// found in cache
	} else {
		// not found in cache
		// get from DB
		_kc.loadUser(id_str, value);

		// check if user existed or not
		if(value.length() == 0){
			_return.__isset.data = false;
			_return.code = ErrorCode::USER_NOT_FOUND;
			return;
		}
		
		// convert from string to object
		_convert_user.deserialize(value, user_);
		
		// put to cache
		_cache.put<string, User>("friend.cache.user", id_str, user_);
	}
	
	_return.__isset.data = true;
	_return.data = user_;
	_return.code = ErrorCode::SUCCESS;
}

void FriendServicesHandler::checkRequest(pingResult& _return, const int32_t id){
	Application::instance().logger().information("Checking friend pending request.");
	
	// check user existed
	string uid = to_string(id);
	if (!_kc.checkUserExisted(uid)){
		_return.haveData = false;
		return;
	}
	
	// get
	try {
		std::set<int32_t> tmp;
		_kc.loadPending(uid, tmp);
		
		// case that don't have any data
		if (tmp.empty()) {
			_return.haveData = false;
			return;
		}
		
		for (std::set<int32_t>::iterator it=tmp.begin(); it!=tmp.end(); it++){
			FriendRequest req;
			int32_t reqid = *it;
			// load in cache first
			if (_cache.get<int32_t, FriendRequest>("friend.cache.friendRequest", reqid, req)){
				// found in cache
			} else {
				// not found
				string value;
				_kc.loadRequest(to_string(*it), value);
				_convert_req.deserialize(value, req);
			}
			_return.data.push_back(req);
			// TODO change set<i32> to list<Request> - DONE
		}
					
		_return.haveData = true;
	} catch (...) {
		Application::instance().logger().error("Something went wrong");
	}
	
	return;
}

ErrorCode::type FriendServicesHandler::addFriend(const FriendRequest& request){
	Application::instance().logger().information("Incoming add friend request");
	
	// check user existed
	string p_send_id = to_string(request.p_send_req);
	string p_recv_id = to_string(request.p_recv_req);
	if (!_kc.checkUserExisted(p_send_id) || !_kc.checkUserExisted(p_recv_id)){
		return ErrorCode::USER_NOT_FOUND;
	}
	
	// check request already send
	{
		set<int32_t> cachePending;
		int32_t key = request.p_recv_req;
	
		if (_cache.get<int32_t, set<int32_t>>("friend.cache.pendingUserId", key, cachePending)){
			// in cache
			if (cachePending.find(request.p_send_req) != cachePending.end())
				return ErrorCode::DUPLICATED_REQUEST;
		} else {
			// not found in cache
			_kc.loadPendingUser(p_recv_id, cachePending);
			if (cachePending.find(request.p_send_req) != cachePending.end())
				return ErrorCode::DUPLICATED_REQUEST;
		}
	}
	
	// check user not friend 
	{
		std::set<int32_t> tmp;
		_kc.loadFriendList(p_recv_id, tmp, 0, 0); // get all friend list
		if (tmp.find(request.p_send_req) != tmp.end())
			return ErrorCode::DUPLICATED_REQUEST;
	}
	
	// store request in request DB
	FriendRequest new_request(request);
	int32_t key_request = _kc.generateRequestId();
	string skey_request = to_string(key_request);
	string value;
	new_request.id = key_request;
	
	// get current time
	Poco::Timestamp now;
	new_request.time = static_cast<int32_t>(now.epochTime());
	
	// serialize object into string
	_convert_req.serialize(new_request, value);
	
	// store in DB
	_kc.store(skey_request, value, SubKC::DB_TYPE::REQUEST);
	
	// store request key in pending DB
	_kc.store(p_recv_id, skey_request, SubKC::DB_TYPE::PENDING);
	_kc.store(p_recv_id, p_send_id, SubKC::DB_TYPE::PENDING_USER);
	
	// cache 1-request cache. 2-pending cache
	std::set<int32_t> tmp;
	_kc.loadPendingUser(p_recv_id, tmp);
	tmp.insert(request.p_send_req);
	_cache.put<int32_t, FriendRequest>("friend.cache.friendRequest", key_request, new_request);
	_cache.put<int32_t, set<int32_t>>("friend.cache.pendingUserId", request.p_recv_req, tmp);
	
	return ErrorCode::type::SUCCESS;
}

ErrorCode::type FriendServicesHandler::acceptRequest(const int32_t curId, const int32_t requestId){
	Application::instance().logger().information("Add friend request");
	
	// check user existed
	string uid = to_string(curId);
	string reqid = to_string(requestId);
	bool userInCache = _cache.check<string, User>("friend.cache.user", uid);
	bool requestInCache = _cache.check<string, FriendRequest>("friend.cache.friendRequest", reqid);
	
	if (!((userInCache || _kc.checkUserExisted(uid)) && (requestInCache || _kc.checkRequestExisted(reqid))))
		return ErrorCode::USER_NOT_FOUND;
	
	// using request id to retrieve sender and receiver
	string value;
	FriendRequest tmp;
	
	// cache
	if (_cache.get<string, FriendRequest>("friend.cache.friendRequest", reqid, tmp)){
		// found in cache
	} else {
		// not found in cache
		// db
		_kc.loadRequest(reqid, value);
		
		if (value.size() == 0) return ErrorCode::INVALID_PARAMETER;
	
		// convert from string to instance
		_convert_req.deserialize(value, tmp);
	}
	
	if (to_string(tmp.p_recv_req) != uid) return ErrorCode::INVALID_PARAMETER;
	
	// async call
	_kc.store(uid, reqid, SubKC::DB_TYPE::REMOVE_PENDING);
	_kc.store(uid, to_string(tmp.p_send_req), SubKC::DB_TYPE::REMOVE_PENDING_USER);
	_kc.store(uid, to_string(tmp.p_send_req), SubKC::DB_TYPE::FRIEND);
	
	return ErrorCode::SUCCESS;
}

ErrorCode::type FriendServicesHandler::declineRequest(const int32_t curId, const int32_t friendId){
	return ErrorCode::SUCCESS;
}

ErrorCode::type FriendServicesHandler::removeFriend(const int32_t curId, const int32_t friendId){
	return ErrorCode::SUCCESS;
}

void FriendServicesHandler::viewFriendList(listFriendResult& _return, const int32_t id, const int32_t index, const int32_t size){
	Application::instance().logger().information("Incoming view friend list request");
	
	// check user existed
	string uid = to_string(id);
	if (!_kc.checkUserExisted(uid)){
		return;
	}
	
	// get data
	std::set<int32_t> tmp;
	_kc.loadFriendList(uid, tmp, index, size);
	
	_return.idx = index;
	_return.size = tmp.size();
	_return.friendList = tmp;
	return;
}