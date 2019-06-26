/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "friend_service_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>



int _kErrorCodeValues[] = {
  ErrorCode::SUCCESS,
  ErrorCode::USER_NOT_FOUND,
  ErrorCode::INVALID_PARAMETER,
  ErrorCode::INVALID_SERVICE,
  ErrorCode::INTERNAL_ERROR,
  ErrorCode::DUPLICATED_REQUEST,
  ErrorCode::OUT_OF_RANGE
};
const char* _kErrorCodeNames[] = {
  "SUCCESS",
  "USER_NOT_FOUND",
  "INVALID_PARAMETER",
  "INVALID_SERVICE",
  "INTERNAL_ERROR",
  "DUPLICATED_REQUEST",
  "OUT_OF_RANGE"
};
const std::map<int, const char*> _ErrorCode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kErrorCodeValues, _kErrorCodeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


User::~User() throw() {
}


void User::__set_id(const int32_t val) {
  this->id = val;
}

void User::__set_name(const std::string& val) {
  this->name = val;
}

void User::__set_isMale(const bool val) {
  this->isMale = val;
}

void User::__set_birthDate(const int32_t val) {
  this->birthDate = val;
}

void User::__set_lastActive(const int32_t val) {
  this->lastActive = val;
}

void User::__set_phoneNumber(const int32_t val) {
  this->phoneNumber = val;
}

uint32_t User::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isMale);
          this->__isset.isMale = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->birthDate);
          this->__isset.birthDate = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->lastActive);
          this->__isset.lastActive = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->phoneNumber);
          this->__isset.phoneNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t User::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("User");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("isMale", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool(this->isMale);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("birthDate", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->birthDate);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("lastActive", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->lastActive);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("phoneNumber", ::apache::thrift::protocol::T_I32, 6);
  xfer += oprot->writeI32(this->phoneNumber);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(User &a, User &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.name, b.name);
  swap(a.isMale, b.isMale);
  swap(a.birthDate, b.birthDate);
  swap(a.lastActive, b.lastActive);
  swap(a.phoneNumber, b.phoneNumber);
  swap(a.__isset, b.__isset);
}

User::User(const User& other0) {
  id = other0.id;
  name = other0.name;
  isMale = other0.isMale;
  birthDate = other0.birthDate;
  lastActive = other0.lastActive;
  phoneNumber = other0.phoneNumber;
  __isset = other0.__isset;
}
User& User::operator=(const User& other1) {
  id = other1.id;
  name = other1.name;
  isMale = other1.isMale;
  birthDate = other1.birthDate;
  lastActive = other1.lastActive;
  phoneNumber = other1.phoneNumber;
  __isset = other1.__isset;
  return *this;
}
void User::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "User(";
  out << "id=" << to_string(id);
  out << ", " << "name=" << to_string(name);
  out << ", " << "isMale=" << to_string(isMale);
  out << ", " << "birthDate=" << to_string(birthDate);
  out << ", " << "lastActive=" << to_string(lastActive);
  out << ", " << "phoneNumber=" << to_string(phoneNumber);
  out << ")";
}


FriendList::~FriendList() throw() {
}


void FriendList::__set_size(const int32_t val) {
  this->size = val;
}

void FriendList::__set_data(const std::set<int32_t> & val) {
  this->data = val;
}

uint32_t FriendList::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->size);
          this->__isset.size = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_SET) {
          {
            this->data.clear();
            uint32_t _size2;
            ::apache::thrift::protocol::TType _etype5;
            xfer += iprot->readSetBegin(_etype5, _size2);
            uint32_t _i6;
            for (_i6 = 0; _i6 < _size2; ++_i6)
            {
              int32_t _elem7;
              xfer += iprot->readI32(_elem7);
              this->data.insert(_elem7);
            }
            xfer += iprot->readSetEnd();
          }
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FriendList::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FriendList");

  xfer += oprot->writeFieldBegin("size", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->size);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_SET, 2);
  {
    xfer += oprot->writeSetBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->data.size()));
    std::set<int32_t> ::const_iterator _iter8;
    for (_iter8 = this->data.begin(); _iter8 != this->data.end(); ++_iter8)
    {
      xfer += oprot->writeI32((*_iter8));
    }
    xfer += oprot->writeSetEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FriendList &a, FriendList &b) {
  using ::std::swap;
  swap(a.size, b.size);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

FriendList::FriendList(const FriendList& other9) {
  size = other9.size;
  data = other9.data;
  __isset = other9.__isset;
}
FriendList& FriendList::operator=(const FriendList& other10) {
  size = other10.size;
  data = other10.data;
  __isset = other10.__isset;
  return *this;
}
void FriendList::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FriendList(";
  out << "size=" << to_string(size);
  out << ", " << "data=" << to_string(data);
  out << ")";
}


PendingRequest::~PendingRequest() throw() {
}


void PendingRequest::__set_size(const int32_t val) {
  this->size = val;
}

void PendingRequest::__set_data(const std::set<int32_t> & val) {
  this->data = val;
}

uint32_t PendingRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->size);
          this->__isset.size = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_SET) {
          {
            this->data.clear();
            uint32_t _size11;
            ::apache::thrift::protocol::TType _etype14;
            xfer += iprot->readSetBegin(_etype14, _size11);
            uint32_t _i15;
            for (_i15 = 0; _i15 < _size11; ++_i15)
            {
              int32_t _elem16;
              xfer += iprot->readI32(_elem16);
              this->data.insert(_elem16);
            }
            xfer += iprot->readSetEnd();
          }
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t PendingRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PendingRequest");

  xfer += oprot->writeFieldBegin("size", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->size);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_SET, 2);
  {
    xfer += oprot->writeSetBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->data.size()));
    std::set<int32_t> ::const_iterator _iter17;
    for (_iter17 = this->data.begin(); _iter17 != this->data.end(); ++_iter17)
    {
      xfer += oprot->writeI32((*_iter17));
    }
    xfer += oprot->writeSetEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PendingRequest &a, PendingRequest &b) {
  using ::std::swap;
  swap(a.size, b.size);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

PendingRequest::PendingRequest(const PendingRequest& other18) {
  size = other18.size;
  data = other18.data;
  __isset = other18.__isset;
}
PendingRequest& PendingRequest::operator=(const PendingRequest& other19) {
  size = other19.size;
  data = other19.data;
  __isset = other19.__isset;
  return *this;
}
void PendingRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PendingRequest(";
  out << "size=" << to_string(size);
  out << ", " << "data=" << to_string(data);
  out << ")";
}


FriendRequest::~FriendRequest() throw() {
}


void FriendRequest::__set_p_send_req(const int32_t val) {
  this->p_send_req = val;
}

void FriendRequest::__set_p_recv_req(const int32_t val) {
  this->p_recv_req = val;
}

void FriendRequest::__set_greeting(const std::string& val) {
  this->greeting = val;
}

void FriendRequest::__set_time(const int32_t val) {
  this->time = val;
}

void FriendRequest::__set_id(const int32_t val) {
  this->id = val;
}

uint32_t FriendRequest::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->p_send_req);
          this->__isset.p_send_req = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->p_recv_req);
          this->__isset.p_recv_req = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->greeting);
          this->__isset.greeting = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->time);
          this->__isset.time = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FriendRequest::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FriendRequest");

  xfer += oprot->writeFieldBegin("p_send_req", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->p_send_req);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("p_recv_req", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->p_recv_req);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("greeting", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->greeting);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("time", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->time);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FriendRequest &a, FriendRequest &b) {
  using ::std::swap;
  swap(a.p_send_req, b.p_send_req);
  swap(a.p_recv_req, b.p_recv_req);
  swap(a.greeting, b.greeting);
  swap(a.time, b.time);
  swap(a.id, b.id);
  swap(a.__isset, b.__isset);
}

FriendRequest::FriendRequest(const FriendRequest& other20) {
  p_send_req = other20.p_send_req;
  p_recv_req = other20.p_recv_req;
  greeting = other20.greeting;
  time = other20.time;
  id = other20.id;
  __isset = other20.__isset;
}
FriendRequest& FriendRequest::operator=(const FriendRequest& other21) {
  p_send_req = other21.p_send_req;
  p_recv_req = other21.p_recv_req;
  greeting = other21.greeting;
  time = other21.time;
  id = other21.id;
  __isset = other21.__isset;
  return *this;
}
void FriendRequest::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FriendRequest(";
  out << "p_send_req=" << to_string(p_send_req);
  out << ", " << "p_recv_req=" << to_string(p_recv_req);
  out << ", " << "greeting=" << to_string(greeting);
  out << ", " << "time=" << to_string(time);
  out << ", " << "id=" << to_string(id);
  out << ")";
}


FriendData::~FriendData() throw() {
}


void FriendData::__set_id(const int32_t val) {
  this->id = val;
}

void FriendData::__set_name(const std::string& val) {
  this->name = val;
}

void FriendData::__set_isMale(const bool val) {
  this->isMale = val;
}

uint32_t FriendData::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->id);
          this->__isset.id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isMale);
          this->__isset.isMale = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FriendData::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FriendData");

  xfer += oprot->writeFieldBegin("id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("isMale", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool(this->isMale);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FriendData &a, FriendData &b) {
  using ::std::swap;
  swap(a.id, b.id);
  swap(a.name, b.name);
  swap(a.isMale, b.isMale);
  swap(a.__isset, b.__isset);
}

FriendData::FriendData(const FriendData& other22) {
  id = other22.id;
  name = other22.name;
  isMale = other22.isMale;
  __isset = other22.__isset;
}
FriendData& FriendData::operator=(const FriendData& other23) {
  id = other23.id;
  name = other23.name;
  isMale = other23.isMale;
  __isset = other23.__isset;
  return *this;
}
void FriendData::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FriendData(";
  out << "id=" << to_string(id);
  out << ", " << "name=" << to_string(name);
  out << ", " << "isMale=" << to_string(isMale);
  out << ")";
}


InputProfileData::~InputProfileData() throw() {
}


void InputProfileData::__set_name(const std::string& val) {
  this->name = val;
}

void InputProfileData::__set_isMale(const bool val) {
  this->isMale = val;
}

void InputProfileData::__set_birthDate(const int32_t val) {
  this->birthDate = val;
}

void InputProfileData::__set_phoneNumber(const int32_t val) {
  this->phoneNumber = val;
}

uint32_t InputProfileData::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->isMale);
          this->__isset.isMale = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->birthDate);
          this->__isset.birthDate = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->phoneNumber);
          this->__isset.phoneNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t InputProfileData::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("InputProfileData");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("isMale", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->isMale);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("birthDate", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->birthDate);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("phoneNumber", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->phoneNumber);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(InputProfileData &a, InputProfileData &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.isMale, b.isMale);
  swap(a.birthDate, b.birthDate);
  swap(a.phoneNumber, b.phoneNumber);
  swap(a.__isset, b.__isset);
}

InputProfileData::InputProfileData(const InputProfileData& other24) {
  name = other24.name;
  isMale = other24.isMale;
  birthDate = other24.birthDate;
  phoneNumber = other24.phoneNumber;
  __isset = other24.__isset;
}
InputProfileData& InputProfileData::operator=(const InputProfileData& other25) {
  name = other25.name;
  isMale = other25.isMale;
  birthDate = other25.birthDate;
  phoneNumber = other25.phoneNumber;
  __isset = other25.__isset;
  return *this;
}
void InputProfileData::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "InputProfileData(";
  out << "name=" << to_string(name);
  out << ", " << "isMale=" << to_string(isMale);
  out << ", " << "birthDate=" << to_string(birthDate);
  out << ", " << "phoneNumber=" << to_string(phoneNumber);
  out << ")";
}


GetUserResult::~GetUserResult() throw() {
}


void GetUserResult::__set_code(const ErrorCode::type val) {
  this->code = val;
}

void GetUserResult::__set_data(const User& val) {
  this->data = val;
}

uint32_t GetUserResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_code = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast26;
          xfer += iprot->readI32(ecast26);
          this->code = (ErrorCode::type)ecast26;
          isset_code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->data.read(iprot);
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_code)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t GetUserResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("GetUserResult");

  xfer += oprot->writeFieldBegin("code", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->code);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->data.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(GetUserResult &a, GetUserResult &b) {
  using ::std::swap;
  swap(a.code, b.code);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

GetUserResult::GetUserResult(const GetUserResult& other27) {
  code = other27.code;
  data = other27.data;
  __isset = other27.__isset;
}
GetUserResult& GetUserResult::operator=(const GetUserResult& other28) {
  code = other28.code;
  data = other28.data;
  __isset = other28.__isset;
  return *this;
}
void GetUserResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "GetUserResult(";
  out << "code=" << to_string(code);
  out << ", " << "data=" << to_string(data);
  out << ")";
}


pingResult::~pingResult() throw() {
}


void pingResult::__set_haveData(const bool val) {
  this->haveData = val;
}

void pingResult::__set_data(const std::vector<FriendRequest> & val) {
  this->data = val;
}

uint32_t pingResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->haveData);
          this->__isset.haveData = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->data.clear();
            uint32_t _size29;
            ::apache::thrift::protocol::TType _etype32;
            xfer += iprot->readListBegin(_etype32, _size29);
            this->data.resize(_size29);
            uint32_t _i33;
            for (_i33 = 0; _i33 < _size29; ++_i33)
            {
              xfer += this->data[_i33].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t pingResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("pingResult");

  xfer += oprot->writeFieldBegin("haveData", ::apache::thrift::protocol::T_BOOL, 1);
  xfer += oprot->writeBool(this->haveData);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->data.size()));
    std::vector<FriendRequest> ::const_iterator _iter34;
    for (_iter34 = this->data.begin(); _iter34 != this->data.end(); ++_iter34)
    {
      xfer += (*_iter34).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(pingResult &a, pingResult &b) {
  using ::std::swap;
  swap(a.haveData, b.haveData);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

pingResult::pingResult(const pingResult& other35) {
  haveData = other35.haveData;
  data = other35.data;
  __isset = other35.__isset;
}
pingResult& pingResult::operator=(const pingResult& other36) {
  haveData = other36.haveData;
  data = other36.data;
  __isset = other36.__isset;
  return *this;
}
void pingResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "pingResult(";
  out << "haveData=" << to_string(haveData);
  out << ", " << "data=" << to_string(data);
  out << ")";
}


listFriendResult::~listFriendResult() throw() {
}


void listFriendResult::__set_size(const int32_t val) {
  this->size = val;
}

void listFriendResult::__set_idx(const int32_t val) {
  this->idx = val;
}

void listFriendResult::__set_friendList(const std::vector<FriendData> & val) {
  this->friendList = val;
}

void listFriendResult::__set_code(const ErrorCode::type val) {
  this->code = val;
}

uint32_t listFriendResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->size);
          this->__isset.size = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->idx);
          this->__isset.idx = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->friendList.clear();
            uint32_t _size37;
            ::apache::thrift::protocol::TType _etype40;
            xfer += iprot->readListBegin(_etype40, _size37);
            this->friendList.resize(_size37);
            uint32_t _i41;
            for (_i41 = 0; _i41 < _size37; ++_i41)
            {
              xfer += this->friendList[_i41].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.friendList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast42;
          xfer += iprot->readI32(ecast42);
          this->code = (ErrorCode::type)ecast42;
          this->__isset.code = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t listFriendResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("listFriendResult");

  xfer += oprot->writeFieldBegin("size", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->size);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("idx", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->idx);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("friendList", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->friendList.size()));
    std::vector<FriendData> ::const_iterator _iter43;
    for (_iter43 = this->friendList.begin(); _iter43 != this->friendList.end(); ++_iter43)
    {
      xfer += (*_iter43).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("code", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32((int32_t)this->code);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(listFriendResult &a, listFriendResult &b) {
  using ::std::swap;
  swap(a.size, b.size);
  swap(a.idx, b.idx);
  swap(a.friendList, b.friendList);
  swap(a.code, b.code);
  swap(a.__isset, b.__isset);
}

listFriendResult::listFriendResult(const listFriendResult& other44) {
  size = other44.size;
  idx = other44.idx;
  friendList = other44.friendList;
  code = other44.code;
  __isset = other44.__isset;
}
listFriendResult& listFriendResult::operator=(const listFriendResult& other45) {
  size = other45.size;
  idx = other45.idx;
  friendList = other45.friendList;
  code = other45.code;
  __isset = other45.__isset;
  return *this;
}
void listFriendResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "listFriendResult(";
  out << "size=" << to_string(size);
  out << ", " << "idx=" << to_string(idx);
  out << ", " << "friendList=" << to_string(friendList);
  out << ", " << "code=" << to_string(code);
  out << ")";
}


