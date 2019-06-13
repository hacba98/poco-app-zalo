/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubKC.h
 * Author: cpu10855
 *
 * Created on May 21, 2019, 11:21 AM
 */



#ifndef SUBKC_H
#define SUBKC_H

#include "kchashdb.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/Subsystem.h"
#include "Poco/Util/Option.h"
#include "Poco/Logger.h"
#include "Poco/Exception.h"
#include "Poco/Notification.h"
#include "Poco/NotificationQueue.h"
#include "Poco/ThreadPool.h"
#include "Poco/Runnable.h"
#include "Poco/AutoPtr.h"
#include "Poco/Mutex.h"

#include <thrift/TToString.h>

#include <string.h>
#include <iostream>
#include <vector>

#include "./MyDB.h"
//#include "./Worker.h"


class SubKC : public Poco::Util::Subsystem {	
public:
enum DB_TYPE {
	USER = 0,
	COUNTER,
	FRIEND,
	PENDING,
	REQUEST,
	REMOVE_PENDING,
	SIZE_OF_MVEC,
};
	SubKC();
	~SubKC();
	void run();

	// API - using as switcher for all methods
	void store (const std::string& key, const std::string& value, DB_TYPE type);
	void load (const std::string&key, std::string& value, DB_TYPE type);
	
	// Use to generate auto increment key for DB 
	int32_t generateUserId();
	std::string generateRequestId();
	
	// store - load user data - TODO: Need to change key to char* type for less disk storage
	bool checkUserExisted(const std::string& key);
	void storeUser(const std::string& key, const std::string& value);
	void loadUser(const std::string& key, std::string& value);
	
	// store - load friend request data 
	void storeRequest(const std::string& key, const std::string& value);
	void loadRequest(const std::string& key, std::string& value);
	
	// method to work with pending and friend database
	void addPending (const std::string& key, const std::string& value);
	void loadPending (const std::string& key, std::set<int32_t>& ret);
	void removePending (const std::string& key, const std::string& value);
	void addFriend (const std::string& key, const std::string& value);
	void removeFriend (const std::string& key, const std::string& value);
	void loadFriendList (const std::string& key, std::set<int32_t>& ret, std::int32_t start_index, std::int32_t range); // remember paging
	bool checkRequestExisted (const std::string& key);
	
	void acceptFriend(const std::string& key, const std::string& request_id);
	void declineFriend(const std::string& key, const std::string& request_id);
	
protected:
	virtual void initialize(Poco::Util::Application& mainApp);
	//virtual void reinitialize(Poco::Util::Application& mainApp);
	virtual void uninitialize();
		
	virtual void defineOptions(Poco::Util::OptionSet& options);
	virtual const char* name() const;
private:
	// Notification queue
	Poco::NotificationQueue _queue;
	Poco::Mutex _mQueue;
	
	// TODO change runnable objects into array of objects
	Poco::Runnable* worker1;
	Poco::Runnable* worker2;

	
	// db object	
	MyDB _dbUser;
	MyDB _dbCounter;
	MyDB _dbFriend;
	MyDB _dbPending;
	MyDB _dbRequest;
	
	// current in-mem key generate
	uint32_t _k_user;
	uint32_t _kMAX_user;
	Poco::Mutex _k_user_m;
	uint32_t _k_req;
	uint32_t _kMAX_req;
	Poco::Mutex _k_req_m;
};

class WorkNotification: public Poco::Notification{
public:
	WorkNotification(bool isRead, const std::string& key, const std::string& value, SubKC::DB_TYPE w_type):
		_isRead(isRead), _key(key), _value(value), _type(w_type) {};
	
	inline bool isRead() const { return _isRead; }
	inline std::string key() const {return _key;}
	inline std::string value() const { return _value;}
	inline void setValue(std::string& value) { _value = value; }
	inline SubKC::DB_TYPE type() const {return _type;}
	
private:
	bool _isRead;
	std::string _key;
	mutable std::string _value;
	SubKC::DB_TYPE _type;
};

class Worker: public Poco::Runnable {
public:
	Worker(Poco::NotificationQueue& queue, SubKC* db): _queue(queue), _db(db){};
	void run ();
		
private:
	Poco::NotificationQueue& _queue;
	SubKC* _db;
	Poco::FastMutex _mutex;
};

#endif /* SUBKC_H */

