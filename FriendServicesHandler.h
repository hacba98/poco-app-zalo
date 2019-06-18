/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FriendServicesHandler.h
 * Author: cpu10855
 *
 * Created on May 22, 2019, 5:18 PM
 */

#ifndef FRIENDSERVICESHANDLER_H
#define FRIENDSERVICESHANDLER_H

#include "Poco/Util/Application.h"
#include "Poco/Logger.h"
#include "Poco/Timestamp.h"

#include "gen-cpp/FriendServices.h"
#include "SubKC.h"
#include "SubCache.h"
#include "Converter.h"

#include <vector>
#include <thrift/TToString.h>

class FriendServicesHandler : public FriendServicesIf {
public:
	FriendServicesHandler();
	FriendServicesHandler(const FriendServicesHandler& orig);
	~FriendServicesHandler();
	
	// basic API
	virtual int32_t CreateUser(const InputProfileData& profile);
	virtual void GetUserInformation(GetUserResult& _return, const int32_t id);
	
	// Friend function API
	virtual void checkRequest(pingResult& _return, const int32_t id);
	virtual ErrorCode::type addFriend(const FriendRequest& request);
	virtual ErrorCode::type acceptRequest(const int32_t curId, const int32_t requestId);
	virtual ErrorCode::type declineRequest(const int32_t curId, const int32_t friendId);
	virtual ErrorCode::type removeFriend(const int32_t curId, const int32_t friendId);
	virtual void viewFriendList(listFriendResult& _return, const int32_t id, const int32_t index, const int32_t size);

private:
	//Poco::Util::Application& _app;
	SubKC& _kc = Poco::Util::Application::instance().getSubsystem<SubKC>();
	SubCache& _cache = Poco::Util::Application::instance().getSubsystem<SubCache>();
	Converter<User> _convert_user;
	Converter<FriendRequest> _convert_req;
};

#endif /* FRIENDSERVICESHANDLER_H */