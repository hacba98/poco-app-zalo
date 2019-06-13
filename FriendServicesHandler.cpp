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
		
	// cache
	
	// store to DB - TODO: Improvement 
	// should implement notification queue
	// then only call store and put notifications to the queue
	// let workers in SubKC subsystem do the rest
	// that also meet the async API requirements
	// old version - w/o notification queue
	//_kc.storeUser(id_str, value);
	// new version - implemented notification queue
	_kc.store(id_str, value, SubKC::DB_TYPE::USER);
	
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
	
	// get from DB
	_kc.loadUser(id_str, value);
	
	// check if user existed or not
	if(value.length() == 0){
		_return.__isset.data = false;
		_return.code = ErrorCode::USER_NOT_FOUND;
		return;
	}
	_convert_user.deserialize(value, user_);
	
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
	
	// cache module goes here
	
	// get
	try {
		std::set<int32_t> tmp;
		_kc.loadPending(uid, tmp);
		
		// case that don't have any data
		if (tmp.empty()) {
			_return.haveData = false;
			return;
		}
		
		_return.haveData = true;
		_return.pendingData = tmp;
	} catch (...) {
		Application::instance().logger().error("Some thing went wrong");
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
	
	// store request in request DB
	string key_request = _kc.generateRequestId();
	string value;
	_convert_req.serialize(request, value);
	// cache
	// store in DB
	_kc.store(key_request, value, SubKC::DB_TYPE::REQUEST);
	
	// store request key in pending DB
	_kc.store(p_recv_id, key_request, SubKC::DB_TYPE::PENDING);
	
	return ErrorCode::type::SUCCESS;
}

ErrorCode::type FriendServicesHandler::acceptRequest(const int32_t curId, const int32_t requestId){
	Application::instance().logger().information("Add friend request");
	
	// check user existed
	string uid = to_string(curId);
	string reqid = to_string(requestId);
	if (!_kc.checkUserExisted(uid) && !_kc.checkRequestExisted(reqid)){
		return ErrorCode::USER_NOT_FOUND;
	}
	
	// using request id to retrieve sender and receiver
	// cache
	// db
	string value;
	FriendRequest tmp;
	_kc.loadRequest(reqid, value);
	
	if (value.size() == 0) return ErrorCode::INVALID_PARAMETER;
	
	_convert_req.deserialize(value, tmp);
	
	if (to_string(tmp.p_recv_req) != uid) return ErrorCode::INVALID_PARAMETER;
	
	// async call
	_kc.store(uid, reqid, SubKC::DB_TYPE::REMOVE_PENDING);
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