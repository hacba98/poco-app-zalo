/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyCache.cpp
 * Author: cpu10855
 * 
 * Created on June 13, 2019, 3:07 PM
 */

#include <memory>

#include "MyCache.h"

using namespace std;

template <typename TKEY, typename TDATA>
void MyCache<TKEY, TDATA>::initialize(){
	_current = 0;
	_hit = _miss = 1; // Laplace smoothing 
	_mem_storage = new MyList<TKEY, TDATA>(_capacity);
}

// ------------ CORE ----------------
template <typename TKEY, typename TDATA>
bool MyCache<TKEY, TDATA>::check(const TKEY& key){
	return _mapping.find(key) != _mapping.end();
}

/**
 * Function to access data from cache
 * this will search in hash map first and then search in storage if found.
 * @param key_ parameter to provide key for hash
 * @param data_ output parameter
 * @return true if found in cache, false otherwise
 */
template <typename TKEY, typename TDATA>
bool MyCache<TKEY, TDATA>::get(const TKEY& key, TDATA& data_){
	// get in hash map
	typename std::map<TKEY, DoubleNode<TKEY, TDATA>>::iterator it = _mapping.find(key);
	if (it == _mapping.end()) {
		_miss++;
		return false;
	}
	
	// retrieve real data in memory storage
	data_ = it->second->getData();
	// update top using LRU strategy
	_mem_storage->reorder(it->second);
	_hit++;
	return true;
}

/**
 * Function to put data to cache. 
 * Clear mapping using _policy when running out of space to store
 * @param key keep in both hash map and list
 * @param data keep in list
 */
template <typename TKEY, typename TDATA>
void MyCache<TKEY, TDATA>::put(const TKEY& key, const TDATA& data){
	// store in memory storage -> return address -> store in hash map
	_mapping[key] = _mem_storage->add(key, data);
	
	// check if it still have space
	_current++;
	if (!available())
		clear();
	return;
}

/**
 * Function to clear cache
 */
template <typename TKEY, typename TDATA>
void MyCache<TKEY, TDATA>::_clear(std::vector<TKEY> candidates){
	for (int i=0; i < candidates.size(); i++){
		_mapping.erase(candidates[i]);
	}
}

template <typename TKEY, typename TDATA>
void MyCache<TKEY, TDATA>::clear(){
	switch (_policy){
		case POLICY::CLEAR_ALL:
			//case nay chac ko can
		case POLICY::CLEAR_HALF:
			_clear(_mem_storage->remove(_mem_storage->getSize() / 2));
			_current = _capacity/2;
			return;
		case POLICY::CLEAR_QUATER:
			_clear(_mem_storage->remove(_mem_storage->getSize() * 1 / 4));
			_current = _capacity*3/4;
			return;
	}
}

