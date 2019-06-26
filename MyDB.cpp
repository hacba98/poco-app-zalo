/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyDB.cpp
 * Author: cpu10855
 * 
 * Created on June 10, 2019, 2:54 PM
 */

#include "MyDB.h"

using namespace std;
using namespace kyotocabinet;
using namespace Poco;

MyDB::~MyDB() {
}

bool MyDB::open(std::string path, uint32_t mode){
	return _kcdb.open(path, mode);
}

bool MyDB::close(){
	return _kcdb.close();
}

void MyDB::set(const std::string& key, const std::string& value){
	_mutex.lock();
	_kcdb.set(key, value);
	_mutex.unlock();
	return;
}

void MyDB::get(const std::string& key, std::string& value){
	//Poco::FastMutex::ScopedLock lock(_mutex);
	if (_kcdb.check(key) == -1) // not found;
		value = "";
	else 
		_kcdb.get(key, &value);
	return;
}

void MyDB::increase(const std::string& key){
	Poco::Mutex::ScopedLock lock(_mutex);
	_kcdb.increment(key, 1);
	return;
}

bool MyDB::existed(const std::string& key){
	return (_kcdb.check(key) != -1);
}

void MyDB::append(const std::string& key, const std::string& value){
	Poco::Mutex::ScopedLock lock(_mutex);
	MyDB::bytes ivalue = {std::stoi(value)};
	bool ok = _kcdb.append(key.c_str(), key.size(), ivalue.c_arr, 4); // size = 4 bytes
}

// status: incomplete, handle in Handler
void MyDB::loadPartial(const std::string& key, std::string& value, const int index, const int range){
	// database storing new data using append
	// retrieve data need to be in reverse order -> newest first
	// must have to load all value in DB but we can ease the networking load
	// by reduce the size of result
	if(_kcdb.get(key, &value)){ // found key
		
	} else
		value = "";
	return;
}	



