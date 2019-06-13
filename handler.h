/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   handler.h
 * Author: cpu10855
 *
 * Created on May 14, 2019, 3:53 PM
 */

#ifndef HANDLER_H
#define HANDLER_H

#include <kchashdb.h>
#include <thrift/TToString.h>

#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <thrift/TToString.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>

#include "gen-cpp/FriendServices.h"
#include "gen-cpp/friend_service_types.h"
#include "gen-cpp/friend_service_constants.h"

#include "Poco/Thread.h"
#include "Poco/Runnable.h"

class FriendServicesHandler: virtual public FriendServicesIf {
public:
	FriendServicesHandler();
	
	// friend class
	// friend AddFriendRunnable;
	
	// Basic API
	int32_t CreateUser(const InputProfileData& profile);
	void GetUserInformation(GetUserResult& _return, const int32_t id);
	
	// Friend function API
	void checkRequest(pingResult& _return, const int32_t id);
	ErrorCode::type addFriend(const int32_t curId, const int32_t friendId);
	ErrorCode::type acceptRequest(const int32_t curId, const int32_t friendId){};
	ErrorCode::type declineRequest(const int32_t curId, const int32_t friendId){};
	ErrorCode::type removeFriend(const int32_t curId, const int32_t friendId){};
	void viewFriendList(listFriendResult& _return, const int32_t id, const int32_t index, const int32_t size){};
	
	void dispatchAddFriend(const int32_t curId, const int32_t friendId);
	
private:
	kyotocabinet::HashDB db;
	std::string counterPath;
	std::string dbPath;
	std::string friendLstPath;
	std::string pendingPath;
	
	// protocol to serialize data structure to disk
	boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> buffer_;
	boost::shared_ptr<apache::thrift::protocol::TProtocol> iprot_;
	boost::shared_ptr<apache::thrift::protocol::TProtocol> oprot_;
}; 

typedef FriendServicesHandler FHandler;

class AddFriendRunnable: public Poco::Runnable {
public:
	AddFriendRunnable(int32_t curId, int32_t frId, FHandler* obj){
		curId_ = curId;
		frId_ = frId;
		obj_ = obj;
	}
	
	inline void run (){
		// write to DB
		obj_->dispatchAddFriend(curId_, frId_);
	}
	
private:
	int32_t curId_;
	int32_t frId_;
	FHandler* obj_;
};

#endif /* HANDLER_H */

