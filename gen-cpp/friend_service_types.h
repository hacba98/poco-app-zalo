/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef friend_service_TYPES_H
#define friend_service_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




struct ErrorCode {
  enum type {
    SUCCESS = 0,
    USER_NOT_FOUND = 1,
    INVALID_PARAMETER = 2,
    INVALID_SERVICE = 3,
    INTERNAL_ERROR = 4,
    DUPLICATED_REQUEST = 5
  };
};

extern const std::map<int, const char*> _ErrorCode_VALUES_TO_NAMES;

class User;

class FriendList;

class PendingRequest;

class FriendRequest;

class InputProfileData;

class GetUserResult;

class pingResult;

class listFriendResult;

typedef struct _User__isset {
  _User__isset() : id(false), name(false), isMale(false), birthDate(false), lastActive(false), phoneNumber(false) {}
  bool id :1;
  bool name :1;
  bool isMale :1;
  bool birthDate :1;
  bool lastActive :1;
  bool phoneNumber :1;
} _User__isset;

class User {
 public:

  User(const User&);
  User& operator=(const User&);
  User() : id(0), name(), isMale(0), birthDate(0), lastActive(0), phoneNumber(0) {
  }

  virtual ~User() throw();
  int32_t id;
  std::string name;
  bool isMale;
  int32_t birthDate;
  int32_t lastActive;
  int32_t phoneNumber;

  _User__isset __isset;

  void __set_id(const int32_t val);

  void __set_name(const std::string& val);

  void __set_isMale(const bool val);

  void __set_birthDate(const int32_t val);

  void __set_lastActive(const int32_t val);

  void __set_phoneNumber(const int32_t val);

  bool operator == (const User & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(isMale == rhs.isMale))
      return false;
    if (!(birthDate == rhs.birthDate))
      return false;
    if (!(lastActive == rhs.lastActive))
      return false;
    if (!(phoneNumber == rhs.phoneNumber))
      return false;
    return true;
  }
  bool operator != (const User &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const User & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(User &a, User &b);

inline std::ostream& operator<<(std::ostream& out, const User& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _FriendList__isset {
  _FriendList__isset() : size(false), data(false) {}
  bool size :1;
  bool data :1;
} _FriendList__isset;

class FriendList {
 public:

  FriendList(const FriendList&);
  FriendList& operator=(const FriendList&);
  FriendList() : size(0) {
  }

  virtual ~FriendList() throw();
  int32_t size;
  std::set<int32_t>  data;

  _FriendList__isset __isset;

  void __set_size(const int32_t val);

  void __set_data(const std::set<int32_t> & val);

  bool operator == (const FriendList & rhs) const
  {
    if (!(size == rhs.size))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const FriendList &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendList & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(FriendList &a, FriendList &b);

inline std::ostream& operator<<(std::ostream& out, const FriendList& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _PendingRequest__isset {
  _PendingRequest__isset() : size(false), data(false) {}
  bool size :1;
  bool data :1;
} _PendingRequest__isset;

class PendingRequest {
 public:

  PendingRequest(const PendingRequest&);
  PendingRequest& operator=(const PendingRequest&);
  PendingRequest() : size(0) {
  }

  virtual ~PendingRequest() throw();
  int32_t size;
  std::set<int32_t>  data;

  _PendingRequest__isset __isset;

  void __set_size(const int32_t val);

  void __set_data(const std::set<int32_t> & val);

  bool operator == (const PendingRequest & rhs) const
  {
    if (!(size == rhs.size))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const PendingRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PendingRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PendingRequest &a, PendingRequest &b);

inline std::ostream& operator<<(std::ostream& out, const PendingRequest& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _FriendRequest__isset {
  _FriendRequest__isset() : p_send_req(false), p_recv_req(false), greeting(false), time(false), id(false) {}
  bool p_send_req :1;
  bool p_recv_req :1;
  bool greeting :1;
  bool time :1;
  bool id :1;
} _FriendRequest__isset;

class FriendRequest {
 public:

  FriendRequest(const FriendRequest&);
  FriendRequest& operator=(const FriendRequest&);
  FriendRequest() : p_send_req(0), p_recv_req(0), greeting(), time(0), id(0) {
  }

  virtual ~FriendRequest() throw();
  int32_t p_send_req;
  int32_t p_recv_req;
  std::string greeting;
  int32_t time;
  int32_t id;

  _FriendRequest__isset __isset;

  void __set_p_send_req(const int32_t val);

  void __set_p_recv_req(const int32_t val);

  void __set_greeting(const std::string& val);

  void __set_time(const int32_t val);

  void __set_id(const int32_t val);

  bool operator == (const FriendRequest & rhs) const
  {
    if (!(p_send_req == rhs.p_send_req))
      return false;
    if (!(p_recv_req == rhs.p_recv_req))
      return false;
    if (!(greeting == rhs.greeting))
      return false;
    if (!(time == rhs.time))
      return false;
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const FriendRequest &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendRequest & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(FriendRequest &a, FriendRequest &b);

inline std::ostream& operator<<(std::ostream& out, const FriendRequest& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _InputProfileData__isset {
  _InputProfileData__isset() : name(false), isMale(false), birthDate(false), phoneNumber(false) {}
  bool name :1;
  bool isMale :1;
  bool birthDate :1;
  bool phoneNumber :1;
} _InputProfileData__isset;

class InputProfileData {
 public:

  InputProfileData(const InputProfileData&);
  InputProfileData& operator=(const InputProfileData&);
  InputProfileData() : name(), isMale(0), birthDate(0), phoneNumber(0) {
  }

  virtual ~InputProfileData() throw();
  std::string name;
  bool isMale;
  int32_t birthDate;
  int32_t phoneNumber;

  _InputProfileData__isset __isset;

  void __set_name(const std::string& val);

  void __set_isMale(const bool val);

  void __set_birthDate(const int32_t val);

  void __set_phoneNumber(const int32_t val);

  bool operator == (const InputProfileData & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(isMale == rhs.isMale))
      return false;
    if (!(birthDate == rhs.birthDate))
      return false;
    if (!(phoneNumber == rhs.phoneNumber))
      return false;
    return true;
  }
  bool operator != (const InputProfileData &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InputProfileData & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(InputProfileData &a, InputProfileData &b);

inline std::ostream& operator<<(std::ostream& out, const InputProfileData& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _GetUserResult__isset {
  _GetUserResult__isset() : data(false) {}
  bool data :1;
} _GetUserResult__isset;

class GetUserResult {
 public:

  GetUserResult(const GetUserResult&);
  GetUserResult& operator=(const GetUserResult&);
  GetUserResult() : code((ErrorCode::type)0) {
  }

  virtual ~GetUserResult() throw();
  ErrorCode::type code;
  User data;

  _GetUserResult__isset __isset;

  void __set_code(const ErrorCode::type val);

  void __set_data(const User& val);

  bool operator == (const GetUserResult & rhs) const
  {
    if (!(code == rhs.code))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const GetUserResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const GetUserResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(GetUserResult &a, GetUserResult &b);

inline std::ostream& operator<<(std::ostream& out, const GetUserResult& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _pingResult__isset {
  _pingResult__isset() : haveData(false), data(false) {}
  bool haveData :1;
  bool data :1;
} _pingResult__isset;

class pingResult {
 public:

  pingResult(const pingResult&);
  pingResult& operator=(const pingResult&);
  pingResult() : haveData(0) {
  }

  virtual ~pingResult() throw();
  bool haveData;
  std::vector<FriendRequest>  data;

  _pingResult__isset __isset;

  void __set_haveData(const bool val);

  void __set_data(const std::vector<FriendRequest> & val);

  bool operator == (const pingResult & rhs) const
  {
    if (!(haveData == rhs.haveData))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const pingResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const pingResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(pingResult &a, pingResult &b);

inline std::ostream& operator<<(std::ostream& out, const pingResult& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _listFriendResult__isset {
  _listFriendResult__isset() : size(false), idx(false), friendList(false) {}
  bool size :1;
  bool idx :1;
  bool friendList :1;
} _listFriendResult__isset;

class listFriendResult {
 public:

  listFriendResult(const listFriendResult&);
  listFriendResult& operator=(const listFriendResult&);
  listFriendResult() : size(0), idx(0) {
  }

  virtual ~listFriendResult() throw();
  int32_t size;
  int32_t idx;
  std::set<int32_t>  friendList;

  _listFriendResult__isset __isset;

  void __set_size(const int32_t val);

  void __set_idx(const int32_t val);

  void __set_friendList(const std::set<int32_t> & val);

  bool operator == (const listFriendResult & rhs) const
  {
    if (!(size == rhs.size))
      return false;
    if (!(idx == rhs.idx))
      return false;
    if (!(friendList == rhs.friendList))
      return false;
    return true;
  }
  bool operator != (const listFriendResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const listFriendResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(listFriendResult &a, listFriendResult &b);

inline std::ostream& operator<<(std::ostream& out, const listFriendResult& obj)
{
  obj.printTo(out);
  return out;
}



#endif
