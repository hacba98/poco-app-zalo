/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Converter.h
 * Author: cpu10855
 *
 * Created on May 23, 2019, 9:10 AM
 */

#ifndef CONVERTER_H
#define CONVERTER_H

#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/TToString.h>

#include "Poco/Mutex.h"

#include <string>

#define _BUFFER_SIZE_ 512

template <class T>
class Converter {
public:
	Converter(): _m(){
		boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> buffer(new apache::thrift::transport::TMemoryBuffer(_buf, _BUFFER_SIZE_, apache::thrift::transport::TMemoryBuffer::MemoryPolicy::COPY));
		boost::shared_ptr<apache::thrift::protocol::TProtocol> prot(new apache::thrift::protocol::TBinaryProtocol(buffer));

		_trans = buffer;
		_prot = prot;
	};
	~Converter(){};
	
	// serialize object o into string
	void serialize(T const& o, std::string& value){
		_m.lock();
		o.write(_prot.get());
		value = _trans->getBufferAsString();
		//value = _trans->readAsString(_trans->defaultSize);
		_trans->resetBuffer(_BUFFER_SIZE_);
		
		return _m.unlock();
	};
	
	// de-serialize string and pass it data to object o
	void deserialize(std::string const & value, T& o){
		_m.lock();
		_trans->resetBuffer((uint8_t*)value.data(), static_cast<uint32_t>(value.length()), apache::thrift::transport::TMemoryBuffer::MemoryPolicy::COPY);
		o.read(_prot.get());
		return _m.unlock();
	};
private:
	uint8_t _buf[_BUFFER_SIZE_];
	boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> _trans;
	boost::shared_ptr<apache::thrift::protocol::TProtocol> _prot;
	Poco::Mutex _m;
};

#endif /* CONVERTER_H */

