/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubHandler.cpp
 * Author: cpu10855
 * 
 * Created on May 22, 2019, 2:44 PM
 */

#include "SubHandler.h"

using namespace std;
using namespace Poco;
using namespace Poco::Util;
using namespace apache::thrift;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
using namespace apache::thrift::server;

SubHandler::SubHandler() {
}

SubHandler::~SubHandler() {
}

//SubHandler::SubHandler(const int port): _port(port){
//}

const char * SubHandler::name () const {
	return "Subsystem-Server Handler";
}

void SubHandler::initialize(Poco::Util::Application& app){
	app.logger().information(Logger::format("Initializing $0 .......", name()));
	
	// construct transport & protocol layers
	try {
		_port = app.config().getInt("server.port", 8080);
		boost::shared_ptr<FriendServicesHandler> handler(new FriendServicesHandler);
		boost::shared_ptr<TProcessor> processor(new FriendServicesProcessor(handler));
		boost::shared_ptr<TServerTransport> serverTransport(new TServerSocket(_port));
		boost::shared_ptr<TTransportFactory> transportFactory(new TTransportFactory());
		boost::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
		
		boost::shared_ptr<TServer> core(new TSimpleServer(processor, serverTransport, transportFactory, protocolFactory));
		_core = core;
		
		if (!_core)
			throw "Setting up server failed.";
	} catch (string e){
		throw new Poco::Exception(e, Application::EXIT_SOFTWARE);
	}
	
	app.logger().information(Logger::format("Initializing $0 .....OK \xe2\x99\xaa", name()));
}

void SubHandler::uninitialize() {
	if (_running)
		terminate();
	// do whaT?
	//~SubHandler();
}

void SubHandler::defineOptions(Poco::Util::OptionSet& options){
	Subsystem::defineOptions(options);
	
	options.addOption(
		Option("svhelp", "svh", "display help about thrift server")
		.required(false)
		.repeatable(false));
}

void SubHandler::run(){
	if (_running) {
		throw Poco::Exception("Server is already start", Application::EXIT_NOHOST);
	}
	_running = true;
	_core->serve();
}

void SubHandler::terminate(){
	if(_running)
		_core->stop();
		
	_running = false;
}

void SubHandler::start(Poco::Util::Application& app){
	try{
		app.logger().information(Logger::format("Server is starting at port $0", app.config().getString("server.port", "8080")));
		this->run();
	} catch (Poco::Exception e){
		app.logger().error(e.message());
	}
}









