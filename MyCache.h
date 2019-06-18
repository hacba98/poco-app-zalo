/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyCache.h
 * Author: cpu10855
 *
 * Created on June 13, 2019, 3:07 PM
 */

#ifndef MYCACHE_H
#define MYCACHE_H

#include "Poco/Mutex.h"

#include <map>
#include <memory>
#include <vector>
#include <string>

#include "MyList.h"

#define DEFAULT_CACHE_SIZE 512 // number of elements store in cache not the size in bytes

// Cache interface - type independence
class IMyCache {
public:
	enum POLICY
	{
	    CLEAR_ALL = 0,
	    CLEAR_HALF,
	    CLEAR_QUATER
	};
	
	virtual ~IMyCache() = default;
	IMyCache(std::string name): _name(name){};
	
	// core
//	virtual bool check = 0;
//	virtual bool get = 0;
//	virtual void put = 0;
	
	//virtual void clear() = 0;
	
	// utility
	//virtual void available() = 0;
	//virtual void setCapacity(std::uint32_t) = 0;
	//virtual void setPolicy(POLICY new_policy) = 0;
    
	inline double hitPercentage() { return _hit * 1.0 / (_hit + _miss); }
	inline std::string name() { return _name; } 
protected:
	// for statistic only
	std::int32_t _hit;
	std::int32_t _miss;

	// identifier: all in lower-case. Ex: friend.cache.user,...
	std::string _name;
};

template <typename TKEY, typename TDATA>
class MyCache : public IMyCache
{
public:

    // constructors
    MyCache(std::int32_t size, MyCache::POLICY policy, std::string name): IMyCache(name),
	_capacity(size), _policy(policy), _mutex(){
	    initialize();
    }
    ~MyCache(){};

    // initialize function
    void initialize();

    // core methods
    bool check(const TKEY& key);
    bool get(const TKEY& key_, TDATA& data_);
    void put(const TKEY& key, const TDATA& data);
    
    void clear(); // normal clear - using default policy - called when cache run out of space
    //void clear(POLICY clear_policy);

    // utility methods
    inline bool available() { return _current < _capacity; }
    inline void setCapacity(std::uint32_t new_capacity) { _capacity = new_capacity; } // have to resize mem_storage
    inline void setPolicy(POLICY new_policy){ _policy = new_policy;}

private:
    // policy for remove element out of cache when reach max capacity
    MyCache::POLICY _policy;

    // Actual in memory storage
    // Using double linked list with Node contain specify data
    // Why using double linked list? Have constrait time to update most recently accessed element
    // MyLinkedList<template> _mem_storage;
    std::shared_ptr<MyList<TKEY, TDATA>> _mem_storage;

    // Mapping data structure
    // for O(1) access time
    // map: key=node.key -> value=node's address
    std::map<TKEY, DoubleNode<TKEY, TDATA>*> _mapping;

    // addition attributes
    std::uint32_t _capacity;
    std::uint32_t _current;
    Poco::Mutex _mutex;
    
    void _clear(std::vector<TKEY> candidates);
};

#include "MyCache.tcc"

#endif /* MYCACHE_H */

