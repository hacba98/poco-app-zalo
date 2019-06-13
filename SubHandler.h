/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubHandler.h
 * Author: cpu10855
 *
 * Created on May 22, 2019, 2:44 PM
 */

#ifndef SUBHANDLER_H
#define SUBHANDLER_H

#include "Poco/Util/Subsystem.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Logger.h"
#include "Poco/Exception.h"

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TSocket.h>

#include "FriendServicesHandler.h"

class SubHandler : public Poco::Util::Subsystem {
public:
	enum STYPE {
		SIMPLE_SERVER = 0,
		THREADED_SERVER = 1,
		THREADPOOL_SERVER = 2,
		NONBLOCKING_SERVER = 3
	};
	// some default 
	SubHandler();
	~SubHandler();
	
	// some specific constructor
	//SubHandler(const int port);
	//SubHandler(const int port, const int n_woker, STYPE type);
	
	// implement abstract method from subsystem class
	virtual void initialize (Poco::Util::Application& app);
	virtual void uninitialize ();
	virtual void defineOptions(Poco::Util::OptionSet& options);
	virtual const char * name() const;
	
	// method for using 
	void run();
	void terminate();
	void start(Poco::Util::Application& app);
		
	
private:
	int _port;
	bool _running = false;
	boost::shared_ptr<apache::thrift::server::TServer> _core;
	
};

#endif /* SUBHANDLER_H */

