/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubKC.cpp
 * Author: cpu10855
 * 
 * Created on May 21, 2019, 11:21 AM
 */

#include "SubKC.h"

using namespace std;
using namespace Poco::Util;
using namespace kyotocabinet;

SubKC::SubKC(): _queue(), _mQueue(){
	worker1 = new Worker(this->_queue, this);
	worker2 = new Worker(this->_queue, this);
}

SubKC::~SubKC() {
}

const char* SubKC::name() const {
	return "Subsystem-KyotoCabinet";
}

void SubKC::initialize(Poco::Util::Application& mainApp){
	mainApp.logger().information(Poco::Logger::format("Initializing $0 .......", name()));
	
	try {
		// open DB connection
		// db object for writing data
		bool valid = false;
		valid = _dbUser.open(mainApp.config().getString("database.user"), HashDB::OWRITER | HashDB::OCREATE);
		valid = valid && _dbCounter.open(mainApp.config().getString("database.counter"), HashDB::OWRITER | HashDB::OCREATE);
		valid = valid && _dbFriend.open(mainApp.config().getString("database.friend"), HashDB::OWRITER | HashDB::OCREATE);
		valid = valid && _dbPending.open(mainApp.config().getString("database.pending"), HashDB::OWRITER | HashDB::OCREATE);	
		valid = valid && _dbRequest.open(mainApp.config().getString("database.request"), HashDB::OWRITER | HashDB::OCREATE);
		
		if (!valid)
			throw new Poco::Exception("Cannot open connections to database.", Application::EXIT_SOFTWARE);

	} catch (Poco::Exception e) {
		throw e;
	}
	
	mainApp.logger().information(Poco::Logger::format("Initializing $0 .....OK \xe2\x99\xaa", name()));
}

void SubKC::run(){
	// TODO : Improve the way to control number of workers depend on demand status.
	Poco::ThreadPool::defaultPool().start(*worker1);
	Poco::ThreadPool::defaultPool().start(*worker2);
	
	// prepare key
	string value;
	_dbCounter.get("user_counter", value);
	if (value.size() == 0)
		value = "0";
	_k_user = stoi(value);
	_kMAX_user = _k_user + 9;
	_dbCounter.set("user_counter", to_string(_kMAX_user + 1));
	
	_dbCounter.get("request_counter", value);
	if (value.size() == 0)
		value = "0";
	_k_req = stoi(value);
	_kMAX_req = _k_user + 9;
	_dbCounter.set("request_counter", to_string(_kMAX_req + 1));
	//for(;;);
}

void SubKC::uninitialize(){
	// Stop workers
	while (!_queue.empty()) // wait for all incomplete task
		Poco::Thread::sleep(1000);
	_queue.wakeUpAll();
	Poco::ThreadPool::defaultPool().joinAll();
	
	// TODO - db.close

	return;
}

void SubKC::defineOptions(Poco::Util::OptionSet& options){
	Subsystem::defineOptions(options);
	
	options.addOption(
		Option("dbhelp", "dbh", "display help about kyoto cabinet database")
		.required(false)
		.repeatable(false));
}


// Implements API 
using apache::thrift::to_string;

void SubKC::store(const std::string& key, const std::string& value, DB_TYPE type){
	_mQueue.lock();
	_queue.enqueueNotification(new WorkNotification(false, key, value, type));
	_mQueue.unlock();
	return;
}

void SubKC::load(const std::string& key, std::string& value, DB_TYPE type){
	return;
}

//------------------------- Generate auto-increment key -------------------------//

int32_t SubKC::generateUserId(){
	Poco::Mutex::ScopedLock lock(_k_user_m);
	if (_k_user < _kMAX_user) // normal case
		return _k_user++;
	else { // running out of key to give -> ask for new key range
		string value;
		_dbCounter.get("user_counter", value);
		_kMAX_user = stoi(value) + 9;
		_dbCounter.set("user_counter", to_string(_kMAX_user + 1));	
		return _k_user++;
	}
}

string SubKC::generateRequestId(){
	Poco::Mutex::ScopedLock lock(_k_req_m);
	if (_k_req < _kMAX_req) // normal case
		return to_string(_k_req++);
	else { // running out of key to give -> ask for new key range
		string value;
		_dbCounter.get("request_counter", value);
		_kMAX_req = stoi(value) + 9;
		_dbCounter.set("request_counter", to_string(_kMAX_req + 1));	
		return to_string(_k_req++);
	}
}

//------------------------- User -------------------------//

bool SubKC::checkUserExisted(const std::string& key){
	return _dbUser.existed(key);
}

void SubKC::storeUser(const std::string& key, const std::string& value){
	// old version
	//_dbUser_store.set((char*)&key, sizeof(key), value.data(), static_cast<uint32_t>(value.length()));
	
	// new version
	// test only - sleep in store method but client still receive response
	// Poco::Thread::sleep(3000);
	return _dbUser.set(key, value);
}

void SubKC::loadUser(const std::string& key, std::string& value){
	// check if exist
	return _dbUser.get(key, value);
}

//------------------------- Friend Request -------------------------//

void SubKC::storeRequest(const std::string& key, const std::string& value){
	return _dbRequest.set(key, value);
}

void SubKC::loadRequest(const std::string& key, std::string& value){
	return _dbRequest.get(key, value);
}

void SubKC::addPending(const std::string& key, const std::string& value){
	return _dbPending.append(key, value);
}

void SubKC::loadPending(const std::string& key, std::set<int32_t>& ret){
	string value;
	_dbPending.get(key, value);
	
	if (value.size() == 0) return; // don't have any data
	
	for(std::string::iterator it = value.begin(); it != value.end(); it+=4){
		int32_t ivalue = static_cast<int32_t>(
			static_cast<unsigned char>(it[3]) << 24 |
			static_cast<unsigned char>(it[2]) << 16 |
			static_cast<unsigned char>(it[1]) <<  8 |
			static_cast<unsigned char>(it[0]));
		ret.insert(ivalue);
	}
}
//------------------------- Friend List -------------------------//

void SubKC::loadFriendList(const std::string& key, std::set<int32_t>& ret, int32_t start_index, int32_t range = 10){
	string value;
	_dbFriend.get(key, value);
	
	if (value.size() == 0) return; // don't have any data
	
	// check out of range
	bool valid = true;
	if (value.size() < ((start_index + range) * 4)){
		range = value.size() - 4 * start_index;
		range /= 4;
	}
	
	for (std::string::iterator it = value.end() - start_index*4; range > 0; it-=4){
		int32_t ivalue = static_cast<int32_t>(
			static_cast<unsigned char>(it[0]) <<  24 |
			static_cast<unsigned char>(it[-1]) << 16 |
			static_cast<unsigned char>(it[-2]) <<  8 |
			static_cast<unsigned char>(it[-3]));
		ret.insert(ivalue);
		range--;
	}
}

//------------------------- Worker Code -------------------------//

void Worker::run(){
	Poco::Notification::Ptr pNf(_queue.waitDequeueNotification()); // does not have time out
	while(pNf){
		WorkNotification* job = dynamic_cast<WorkNotification*>(pNf.get());
		if (job){ // handle 
			Poco::FastMutex::ScopedLock lock(_mutex);
			if (job->isRead()){ // for read process
//				switch (job.type()){
//					case SubKC::DB_TYPE::USER:
//						_db->loadUser()
//				}
			} else { // for write process
				switch (job->type()){
					case SubKC::DB_TYPE::USER:
						_db->storeUser(job->key(), job->value());
						break;
						
					case SubKC::DB_TYPE::REQUEST:
						_db->storeRequest(job->key(), job->value());
						break;
						
					case SubKC::DB_TYPE::PENDING:
						_db->addPending(job->key(), job->value());
						break;
				}
			}
		}
		
		pNf = _queue.waitDequeueNotification();
	}
}
