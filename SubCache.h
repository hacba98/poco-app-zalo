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
#include "Poco/NotificationQueue.h"
#include "Poco/Notification.h"
#include "Poco/NotificationQueue.h"
#include "Poco/ThreadPool.h"
#include "Poco/Runnable.h"
#include "Poco/AutoPtr.h"
#include "Poco/Mutex.h"


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
	
	/// async function support for async call
	template <typename K, typename C>
	void putAsync(const std::string& name, const K& key, const C& ret);

protected:
	virtual void initialize(Poco::Util::Application& app);
	virtual void uninitialize();
	virtual void defineOptions(Poco::Util::OptionSet& options);
	virtual const char* name() const;

private:
	// caches vector
	std::vector<std::unique_ptr<IMyCache>> _caches;

	// Notification queue
	Poco::NotificationQueue _queue;
	Poco::Mutex _mQueue;
	
	// TODO change runnable objects into array of objects - DONE
	std::vector<boost::shared_ptr<Poco::Runnable>> _wVec;

	// configurations
	std::uint32_t _small_size;
	std::uint32_t _large_size;
	IMyCache::POLICY _policy = IMyCache::POLICY::CLEAR_QUATER;
	double _hitRate = 0;

};

template <typename K, typename C> bool SubCache::get(const std::string& name, K& key, C& ret) {
	for (int i = 0; i < _caches.size(); i++) {
		MyCache<K, C> *pC = dynamic_cast<MyCache<K, C>*> (_caches[i].get());
		if (pC) {
			if (pC->name() == name.c_str()){
				if (pC->get(key, ret)) // found in cache
					return true;
				return false;
			}
		}
	}
	Poco::Util::Application::instance().logger().debug("Wrong cache name");
	return false;
};

template <typename K, typename C> void SubCache::put(const std::string& name, const K& key, const C& value) {
	for (int i = 0; i < _caches.size(); i++) {
		MyCache<K, C> *pC = dynamic_cast<MyCache<K, C>*> (_caches[i].get());
		if (pC) {
			if (pC->name() == name.c_str()){
				pC->put(key, value);
				return;
			}
		}
	}
	Poco::Util::Application::instance().logger().debug("Wrong cache name");
	return;
}

template <typename K, typename C> bool SubCache::check(const std::string& name, const K& key) {
	for (int i = 0; i < _caches.size(); i++) {
		MyCache<K, C> *pC = dynamic_cast<MyCache<K, C>*> (_caches[i].get());
		if(pC){
			if (pC->name() == name.c_str()){
				if (pC->check(key)) // found in cache
					return true;
				return false;
			}
		}
	}
	Poco::Util::Application::instance().logger().debug("Wrong cache name");
	return false;
}

template <typename K, typename C>
class CacheNotification: public Poco::Notification{
public:
	CacheNotification(const std::string& name, const K& key, const C& value):
		_name(name), _key(key), _value(value){}
	
private:
	std::string _name;
	K _key;
	C _value;
};

class CacheWorker: public Poco::Runnable {
public:
	CacheWorker(Poco::NotificationQueue& queue, SubCache* cache): _queue(queue), _cache(cache), _mutex(){
	};
	
	template <typename K, typename C>
	void run (){
		Poco::Notification::Ptr pNf(_queue.waitDequeueNotification()); // does not have time out
		while(pNf){
			WorkNotification<K, C> *job = dynamic_cast<WorkNotification<K, C>*>(pNf.get());
			
		}
	}
		
private:
	Poco::NotificationQueue& _queue;
	boost::shared_ptr<SubCache> _cache;
	Poco::Mutex _mutex;
};

template <typename K, typename C> void SubCache::putAsync(const std::string& name, const K& key, const C& ret){
	_mQueue.lock();
	_queue.enqueueNotification(new CacheNotification<K,C>(name, key, ret));
	_mQueue.unlock();
	return;
}



#endif /* SUBCACHE_H */

