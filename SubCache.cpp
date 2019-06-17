/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubCache.cpp
 * Author: cpu10855
 * 
 * Created on June 17, 2019, 9:08 AM
 */

#include "SubCache.h"

SubCache::SubCache(): _caches(){
}

SubCache::~SubCache() {
}

const char* SubCache::name() const {
	return "Subsystem-Cache";
}

void SubCache::initialize(Poco::Util::Application& app){
	app.logger().information(Poco::Logger::format("Initializing $0 .......", name()));
	
	try {
		// configurate variables
		_small_size = app.config().getInt("cache.small_size", 500);
		_large_size = app.config().getInt("cache.large_size", 2000);
		
		// initialize cache array
		// large cache - main data: user, friend request
		MyCache<string, User> *userCache = new MyCache<string, User>(_large_size, _policy, "friend.cache.user");
		MyCache<string, FriendRequest> *friendCache = new MyCache<string, FriendRequest>(_large_size, _policy, "friend.cache.friendRequest");
		_caches.push_back(std::unique_ptr<IMyCache>(userCache));
		_caches.push_back(std::unique_ptr<IMyCache>(friendCache));
		
		// small cache? TODO: Should all DB object have a cache object
		
	} catch (Poco::Exception e) {
		throw e;
	}
	
	app.logger().information(Poco::Logger::format("Initializing $0 .....OK \xe2\x99\xaa", name()));
}

void SubCache::uninitialize(){
	// what to do here?
	// cache auto delete when obj delete
	// print out hit rate
	for (int i=0; i < _caches.size(); i++){
		Poco::Util::Application::instance().logger().information(
			Poco::Logger::format("Hit rate of $0 = $1.", _caches[i]->name(), to_string(_caches[i]->hitPercentage())));
	}
}

void SubCache::defineOptions(Poco::Util::OptionSet& options){
	Poco::Util::Subsystem::defineOptions(options);
	
	options.addOption(
		Poco::Util::Option("dbhelp", "dbh", "display help about kyoto cabinet database")
		.required(false)
		.repeatable(false));
}