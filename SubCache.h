/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubCache.h
 * Author: cpu10855
 *
 * Created on June 17, 2019, 9:08 AM
 */

#ifndef SUBCACHE_H
#define SUBCACHE_H

#include "Poco/Util/Application.h"
#include "Poco/Util/Subsystem.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/Option.h"
#include "Poco/Logger.h"
#include "Poco/Exception.h"

#include <vector>
#include <string>

#include "gen-cpp/FriendServices.h"
#include "MyCache.h"

class SubCache : public Poco::Util::Subsystem {
public:
	
	SubCache();
	~SubCache();
	
	//
	// inlines
	//
	template <typename K, typename C>
	bool get(const std::string& name, K& key, C& ret);
	//
	template <typename K, typename C>
	void put(const std::string& name, const K& key, const C& ret);
	//
	template <typename K, typename C>
	bool check(const std::string& name, const K& key);
	
protected:
	virtual void initialize(Poco::Util::Application& app);
	virtual void uninitialize();
	virtual void defineOptions(Poco::Util::OptionSet& options);
	virtual const char* name() const;
	
private:
	// big cache 
	std::vector<std::unique_ptr<IMyCache>> _caches;
	
	// small cache
	
	// configurations
	std::uint32_t _small_size;
	std::uint32_t _large_size;
	IMyCache::POLICY _policy = IMyCache::POLICY::CLEAR_QUATER;
	double _hitRate = 0;

};

template <typename K, typename C> bool SubCache::get(const std::string& name, K& key, C& ret){
	for (int i=0; i < _caches.size(); i++){
		MyCache<K,C> *pC = dynamic_cast<MyCache<K,C>*>(_caches[i].get());
		if (pC->name() == name){
			if (pC->get(key, ret)) // found in cache
				return true;
			return false;
		}	
	}
	Poco::Util::Application::instance().logger().debug("Wrong cache name");
	return false;
};

template <typename K, typename C> void SubCache::put(const std::string& name, const K& key, const C& value){
	for (int i=0; i < _caches.size(); i++){
		MyCache<K,C> *pC = dynamic_cast<MyCache<K,C>*>(_caches[i].get());
		if (pC->name() == name){
			pC->put(key, value);
			return;
		}	
	}
	Poco::Util::Application::instance().logger().debug("Wrong cache name");
	return;
}

template <typename K, typename C> bool SubCache::check(const std::string& name, const K& key){
	for (int i=0; i < _caches.size(); i++){
		MyCache<K,C> *pC = dynamic_cast<MyCache<K,C>*>(_caches[i].get());
		if (pC->name() == name){
			if (pC->check(key)) // found in cache
				return true;
			return false;
		}	
	}
	Poco::Util::Application::instance().logger().debug("Wrong cache name");
	return false;
}

#endif /* SUBCACHE_H */

