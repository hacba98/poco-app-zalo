/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Worker.h
 * Author: cpu10855
 *
 * Created on June 11, 2019, 10:25 AM
 */

#ifndef WORKER_H
#define WORKER_H

#include "Poco/Notification.h"
#include "Poco/Runnable.h"
#include "Poco/NotificationQueue.h"
#include "Poco/Mutex.h"

#include <string>

#include "./SubKC.h"

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

#endif /* WORKER_H */

