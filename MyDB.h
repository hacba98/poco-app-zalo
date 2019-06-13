/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyDB.h
 * Author: cpu10855
 *
 * Created on June 10, 2019, 2:54 PM
 */

#ifndef MYDB_H
#define MYDB_H

#include "kchashdb.h"
#include "Poco/Mutex.h"

#include <thrift/TToString.h>

#include <string.h>
#include <iostream>
#include <vector>

/**
 * wrap-up class contain basic Hash DB as long as its mutex
 */
class MyDB {
public:
	union bytes {
		std::int32_t n;
		char c_arr[4];
	};
	
	MyDB(): _mutex(){};
	~MyDB();
	
	// open - close operation
	bool open(std::string path, uint32_t mode);
	bool close();
	
	// read - write operation
	void set(const std::string& key, const std::string& value);
	void get(const std::string& key, std::string& value);
	
	// utility function
	void increase(const std::string& key);
	bool existed(const std::string& key);
	void append(const std::string& key, const std::string& value);
	
private:
	kyotocabinet::HashDB _kcdb;
	Poco::Mutex _mutex;
};

#endif /* MYDB_H */

