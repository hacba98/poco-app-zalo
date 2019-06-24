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
	typedef Poco::FastMutex Mutex;
	Converter() : _m() {
		boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> buffer(new apache::thrift::transport::TMemoryBuffer(_BUFFER_SIZE_));
		boost::shared_ptr<apache::thrift::protocol::TProtocol> prot(new apache::thrift::protocol::TBinaryProtocol(buffer));

		_trans = buffer;
		_prot = prot;
	};

	~Converter() {
	};

	// serialize object o into string

	inline void serialize(T const& o, std::string& value) {
		Mutex::ScopedLock lock(_m);
		o.write(_prot.get());
		value = _trans->getBufferAsString();
		_trans->resetBuffer(_BUFFER_SIZE_);
	};

	// de-serialize string and pass it data to object o

	inline void deserialize(std::string const & value, T& o) {
		Mutex::ScopedLock lock(_m);
		_trans->resetBuffer((uint8_t*) value.data(), static_cast<uint32_t> (value.length()));
		o.read(_prot.get());
	};
private:
	boost::shared_ptr<apache::thrift::transport::TMemoryBuffer> _trans;
	boost::shared_ptr<apache::thrift::protocol::TProtocol> _prot;
	Mutex _m;
	
};

#endif /* CONVERTER_H */

