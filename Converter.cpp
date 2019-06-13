/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Converter.cpp
 * Author: cpu10855
 * 
 * Created on May 23, 2019, 9:10 AM
 */

#include "Converter.h"

using namespace apache::thrift;
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
using apache::thrift::to_string;

using namespace Poco;

//template <class T>
//Converter<T>::Converter(): _m() {
//	boost::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
//	boost::shared_ptr<TProtocol> prot(new TBinaryProtocol(buffer));
//	
//	_trans = buffer;
//	_prot = prot;
//}
//
//template <class T>
//Converter<T>::~Converter() {
//}
//
//template <class T>
//void Converter<T>::serialize(const T& o, std::string& value){
//	_m.lock();
//	o.write(_prot.get());
//	value = _trans->getBufferAsString();
//	return _m.unlock();
//}
//
//template <class T>
//void Converter<T>::deserialize(const std::string& value, T& o){
//	_m.lock();
//	_trans->resetBuffer((uint8_t*)value.data(), static_cast<uint32_t>(value.length()));
//	o.read(_prot.get());
//	return _m.unlock();
//}

