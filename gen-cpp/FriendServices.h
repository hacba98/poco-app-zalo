/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef FriendServices_H
#define FriendServices_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "friend_service_types.h"



#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class FriendServicesIf {
 public:
  virtual ~FriendServicesIf() {}
  virtual int32_t CreateUser(const InputProfileData& profile) = 0;
  virtual void GetUserInformation(GetUserResult& _return, const int32_t id) = 0;
  virtual void checkRequest(pingResult& _return, const int32_t id) = 0;
  virtual ErrorCode::type addFriend(const FriendRequest& request) = 0;
  virtual ErrorCode::type acceptRequest(const int32_t curId, const int32_t requestId) = 0;
  virtual ErrorCode::type declineRequest(const int32_t curId, const int32_t requestId) = 0;
  virtual ErrorCode::type removeFriend(const int32_t curId, const int32_t friendId) = 0;
  virtual void viewFriendList(listFriendResult& _return, const int32_t id, const int32_t index, const int32_t size) = 0;
};

class FriendServicesIfFactory {
 public:
  typedef FriendServicesIf Handler;

  virtual ~FriendServicesIfFactory() {}

  virtual FriendServicesIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(FriendServicesIf* /* handler */) = 0;
};

class FriendServicesIfSingletonFactory : virtual public FriendServicesIfFactory {
 public:
  FriendServicesIfSingletonFactory(const boost::shared_ptr<FriendServicesIf>& iface) : iface_(iface) {}
  virtual ~FriendServicesIfSingletonFactory() {}

  virtual FriendServicesIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(FriendServicesIf* /* handler */) {}

 protected:
  boost::shared_ptr<FriendServicesIf> iface_;
};

class FriendServicesNull : virtual public FriendServicesIf {
 public:
  virtual ~FriendServicesNull() {}
  int32_t CreateUser(const InputProfileData& /* profile */) {
    int32_t _return = 0;
    return _return;
  }
  void GetUserInformation(GetUserResult& /* _return */, const int32_t /* id */) {
    return;
  }
  void checkRequest(pingResult& /* _return */, const int32_t /* id */) {
    return;
  }
  ErrorCode::type addFriend(const FriendRequest& /* request */) {
    ErrorCode::type _return = (ErrorCode::type)0;
    return _return;
  }
  ErrorCode::type acceptRequest(const int32_t /* curId */, const int32_t /* requestId */) {
    ErrorCode::type _return = (ErrorCode::type)0;
    return _return;
  }
  ErrorCode::type declineRequest(const int32_t /* curId */, const int32_t /* requestId */) {
    ErrorCode::type _return = (ErrorCode::type)0;
    return _return;
  }
  ErrorCode::type removeFriend(const int32_t /* curId */, const int32_t /* friendId */) {
    ErrorCode::type _return = (ErrorCode::type)0;
    return _return;
  }
  void viewFriendList(listFriendResult& /* _return */, const int32_t /* id */, const int32_t /* index */, const int32_t /* size */) {
    return;
  }
};

typedef struct _FriendServices_CreateUser_args__isset {
  _FriendServices_CreateUser_args__isset() : profile(false) {}
  bool profile :1;
} _FriendServices_CreateUser_args__isset;

class FriendServices_CreateUser_args {
 public:

  FriendServices_CreateUser_args(const FriendServices_CreateUser_args&);
  FriendServices_CreateUser_args& operator=(const FriendServices_CreateUser_args&);
  FriendServices_CreateUser_args() {
  }

  virtual ~FriendServices_CreateUser_args() throw();
  InputProfileData profile;

  _FriendServices_CreateUser_args__isset __isset;

  void __set_profile(const InputProfileData& val);

  bool operator == (const FriendServices_CreateUser_args & rhs) const
  {
    if (!(profile == rhs.profile))
      return false;
    return true;
  }
  bool operator != (const FriendServices_CreateUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_CreateUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FriendServices_CreateUser_pargs {
 public:


  virtual ~FriendServices_CreateUser_pargs() throw();
  const InputProfileData* profile;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_CreateUser_result__isset {
  _FriendServices_CreateUser_result__isset() : success(false) {}
  bool success :1;
} _FriendServices_CreateUser_result__isset;

class FriendServices_CreateUser_result {
 public:

  FriendServices_CreateUser_result(const FriendServices_CreateUser_result&);
  FriendServices_CreateUser_result& operator=(const FriendServices_CreateUser_result&);
  FriendServices_CreateUser_result() : success(0) {
  }

  virtual ~FriendServices_CreateUser_result() throw();
  int32_t success;

  _FriendServices_CreateUser_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const FriendServices_CreateUser_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FriendServices_CreateUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_CreateUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_CreateUser_presult__isset {
  _FriendServices_CreateUser_presult__isset() : success(false) {}
  bool success :1;
} _FriendServices_CreateUser_presult__isset;

class FriendServices_CreateUser_presult {
 public:


  virtual ~FriendServices_CreateUser_presult() throw();
  int32_t* success;

  _FriendServices_CreateUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _FriendServices_GetUserInformation_args__isset {
  _FriendServices_GetUserInformation_args__isset() : id(false) {}
  bool id :1;
} _FriendServices_GetUserInformation_args__isset;

class FriendServices_GetUserInformation_args {
 public:

  FriendServices_GetUserInformation_args(const FriendServices_GetUserInformation_args&);
  FriendServices_GetUserInformation_args& operator=(const FriendServices_GetUserInformation_args&);
  FriendServices_GetUserInformation_args() : id(0) {
  }

  virtual ~FriendServices_GetUserInformation_args() throw();
  int32_t id;

  _FriendServices_GetUserInformation_args__isset __isset;

  void __set_id(const int32_t val);

  bool operator == (const FriendServices_GetUserInformation_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const FriendServices_GetUserInformation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_GetUserInformation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FriendServices_GetUserInformation_pargs {
 public:


  virtual ~FriendServices_GetUserInformation_pargs() throw();
  const int32_t* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_GetUserInformation_result__isset {
  _FriendServices_GetUserInformation_result__isset() : success(false) {}
  bool success :1;
} _FriendServices_GetUserInformation_result__isset;

class FriendServices_GetUserInformation_result {
 public:

  FriendServices_GetUserInformation_result(const FriendServices_GetUserInformation_result&);
  FriendServices_GetUserInformation_result& operator=(const FriendServices_GetUserInformation_result&);
  FriendServices_GetUserInformation_result() {
  }

  virtual ~FriendServices_GetUserInformation_result() throw();
  GetUserResult success;

  _FriendServices_GetUserInformation_result__isset __isset;

  void __set_success(const GetUserResult& val);

  bool operator == (const FriendServices_GetUserInformation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FriendServices_GetUserInformation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_GetUserInformation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_GetUserInformation_presult__isset {
  _FriendServices_GetUserInformation_presult__isset() : success(false) {}
  bool success :1;
} _FriendServices_GetUserInformation_presult__isset;

class FriendServices_GetUserInformation_presult {
 public:


  virtual ~FriendServices_GetUserInformation_presult() throw();
  GetUserResult* success;

  _FriendServices_GetUserInformation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _FriendServices_checkRequest_args__isset {
  _FriendServices_checkRequest_args__isset() : id(false) {}
  bool id :1;
} _FriendServices_checkRequest_args__isset;

class FriendServices_checkRequest_args {
 public:

  FriendServices_checkRequest_args(const FriendServices_checkRequest_args&);
  FriendServices_checkRequest_args& operator=(const FriendServices_checkRequest_args&);
  FriendServices_checkRequest_args() : id(0) {
  }

  virtual ~FriendServices_checkRequest_args() throw();
  int32_t id;

  _FriendServices_checkRequest_args__isset __isset;

  void __set_id(const int32_t val);

  bool operator == (const FriendServices_checkRequest_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    return true;
  }
  bool operator != (const FriendServices_checkRequest_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_checkRequest_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FriendServices_checkRequest_pargs {
 public:


  virtual ~FriendServices_checkRequest_pargs() throw();
  const int32_t* id;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_checkRequest_result__isset {
  _FriendServices_checkRequest_result__isset() : success(false) {}
  bool success :1;
} _FriendServices_checkRequest_result__isset;

class FriendServices_checkRequest_result {
 public:

  FriendServices_checkRequest_result(const FriendServices_checkRequest_result&);
  FriendServices_checkRequest_result& operator=(const FriendServices_checkRequest_result&);
  FriendServices_checkRequest_result() {
  }

  virtual ~FriendServices_checkRequest_result() throw();
  pingResult success;

  _FriendServices_checkRequest_result__isset __isset;

  void __set_success(const pingResult& val);

  bool operator == (const FriendServices_checkRequest_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FriendServices_checkRequest_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_checkRequest_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_checkRequest_presult__isset {
  _FriendServices_checkRequest_presult__isset() : success(false) {}
  bool success :1;
} _FriendServices_checkRequest_presult__isset;

class FriendServices_checkRequest_presult {
 public:


  virtual ~FriendServices_checkRequest_presult() throw();
  pingResult* success;

  _FriendServices_checkRequest_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _FriendServices_addFriend_args__isset {
  _FriendServices_addFriend_args__isset() : request(false) {}
  bool request :1;
} _FriendServices_addFriend_args__isset;

class FriendServices_addFriend_args {
 public:

  FriendServices_addFriend_args(const FriendServices_addFriend_args&);
  FriendServices_addFriend_args& operator=(const FriendServices_addFriend_args&);
  FriendServices_addFriend_args() {
  }

  virtual ~FriendServices_addFriend_args() throw();
  FriendRequest request;

  _FriendServices_addFriend_args__isset __isset;

  void __set_request(const FriendRequest& val);

  bool operator == (const FriendServices_addFriend_args & rhs) const
  {
    if (!(request == rhs.request))
      return false;
    return true;
  }
  bool operator != (const FriendServices_addFriend_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_addFriend_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FriendServices_addFriend_pargs {
 public:


  virtual ~FriendServices_addFriend_pargs() throw();
  const FriendRequest* request;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_addFriend_result__isset {
  _FriendServices_addFriend_result__isset() : success(false) {}
  bool success :1;
} _FriendServices_addFriend_result__isset;

class FriendServices_addFriend_result {
 public:

  FriendServices_addFriend_result(const FriendServices_addFriend_result&);
  FriendServices_addFriend_result& operator=(const FriendServices_addFriend_result&);
  FriendServices_addFriend_result() : success((ErrorCode::type)0) {
  }

  virtual ~FriendServices_addFriend_result() throw();
  ErrorCode::type success;

  _FriendServices_addFriend_result__isset __isset;

  void __set_success(const ErrorCode::type val);

  bool operator == (const FriendServices_addFriend_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FriendServices_addFriend_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_addFriend_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_addFriend_presult__isset {
  _FriendServices_addFriend_presult__isset() : success(false) {}
  bool success :1;
} _FriendServices_addFriend_presult__isset;

class FriendServices_addFriend_presult {
 public:


  virtual ~FriendServices_addFriend_presult() throw();
  ErrorCode::type* success;

  _FriendServices_addFriend_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _FriendServices_acceptRequest_args__isset {
  _FriendServices_acceptRequest_args__isset() : curId(false), requestId(false) {}
  bool curId :1;
  bool requestId :1;
} _FriendServices_acceptRequest_args__isset;

class FriendServices_acceptRequest_args {
 public:

  FriendServices_acceptRequest_args(const FriendServices_acceptRequest_args&);
  FriendServices_acceptRequest_args& operator=(const FriendServices_acceptRequest_args&);
  FriendServices_acceptRequest_args() : curId(0), requestId(0) {
  }

  virtual ~FriendServices_acceptRequest_args() throw();
  int32_t curId;
  int32_t requestId;

  _FriendServices_acceptRequest_args__isset __isset;

  void __set_curId(const int32_t val);

  void __set_requestId(const int32_t val);

  bool operator == (const FriendServices_acceptRequest_args & rhs) const
  {
    if (!(curId == rhs.curId))
      return false;
    if (!(requestId == rhs.requestId))
      return false;
    return true;
  }
  bool operator != (const FriendServices_acceptRequest_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_acceptRequest_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FriendServices_acceptRequest_pargs {
 public:


  virtual ~FriendServices_acceptRequest_pargs() throw();
  const int32_t* curId;
  const int32_t* requestId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_acceptRequest_result__isset {
  _FriendServices_acceptRequest_result__isset() : success(false) {}
  bool success :1;
} _FriendServices_acceptRequest_result__isset;

class FriendServices_acceptRequest_result {
 public:

  FriendServices_acceptRequest_result(const FriendServices_acceptRequest_result&);
  FriendServices_acceptRequest_result& operator=(const FriendServices_acceptRequest_result&);
  FriendServices_acceptRequest_result() : success((ErrorCode::type)0) {
  }

  virtual ~FriendServices_acceptRequest_result() throw();
  ErrorCode::type success;

  _FriendServices_acceptRequest_result__isset __isset;

  void __set_success(const ErrorCode::type val);

  bool operator == (const FriendServices_acceptRequest_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FriendServices_acceptRequest_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_acceptRequest_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_acceptRequest_presult__isset {
  _FriendServices_acceptRequest_presult__isset() : success(false) {}
  bool success :1;
} _FriendServices_acceptRequest_presult__isset;

class FriendServices_acceptRequest_presult {
 public:


  virtual ~FriendServices_acceptRequest_presult() throw();
  ErrorCode::type* success;

  _FriendServices_acceptRequest_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _FriendServices_declineRequest_args__isset {
  _FriendServices_declineRequest_args__isset() : curId(false), requestId(false) {}
  bool curId :1;
  bool requestId :1;
} _FriendServices_declineRequest_args__isset;

class FriendServices_declineRequest_args {
 public:

  FriendServices_declineRequest_args(const FriendServices_declineRequest_args&);
  FriendServices_declineRequest_args& operator=(const FriendServices_declineRequest_args&);
  FriendServices_declineRequest_args() : curId(0), requestId(0) {
  }

  virtual ~FriendServices_declineRequest_args() throw();
  int32_t curId;
  int32_t requestId;

  _FriendServices_declineRequest_args__isset __isset;

  void __set_curId(const int32_t val);

  void __set_requestId(const int32_t val);

  bool operator == (const FriendServices_declineRequest_args & rhs) const
  {
    if (!(curId == rhs.curId))
      return false;
    if (!(requestId == rhs.requestId))
      return false;
    return true;
  }
  bool operator != (const FriendServices_declineRequest_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_declineRequest_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FriendServices_declineRequest_pargs {
 public:


  virtual ~FriendServices_declineRequest_pargs() throw();
  const int32_t* curId;
  const int32_t* requestId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_declineRequest_result__isset {
  _FriendServices_declineRequest_result__isset() : success(false) {}
  bool success :1;
} _FriendServices_declineRequest_result__isset;

class FriendServices_declineRequest_result {
 public:

  FriendServices_declineRequest_result(const FriendServices_declineRequest_result&);
  FriendServices_declineRequest_result& operator=(const FriendServices_declineRequest_result&);
  FriendServices_declineRequest_result() : success((ErrorCode::type)0) {
  }

  virtual ~FriendServices_declineRequest_result() throw();
  ErrorCode::type success;

  _FriendServices_declineRequest_result__isset __isset;

  void __set_success(const ErrorCode::type val);

  bool operator == (const FriendServices_declineRequest_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FriendServices_declineRequest_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_declineRequest_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_declineRequest_presult__isset {
  _FriendServices_declineRequest_presult__isset() : success(false) {}
  bool success :1;
} _FriendServices_declineRequest_presult__isset;

class FriendServices_declineRequest_presult {
 public:


  virtual ~FriendServices_declineRequest_presult() throw();
  ErrorCode::type* success;

  _FriendServices_declineRequest_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _FriendServices_removeFriend_args__isset {
  _FriendServices_removeFriend_args__isset() : curId(false), friendId(false) {}
  bool curId :1;
  bool friendId :1;
} _FriendServices_removeFriend_args__isset;

class FriendServices_removeFriend_args {
 public:

  FriendServices_removeFriend_args(const FriendServices_removeFriend_args&);
  FriendServices_removeFriend_args& operator=(const FriendServices_removeFriend_args&);
  FriendServices_removeFriend_args() : curId(0), friendId(0) {
  }

  virtual ~FriendServices_removeFriend_args() throw();
  int32_t curId;
  int32_t friendId;

  _FriendServices_removeFriend_args__isset __isset;

  void __set_curId(const int32_t val);

  void __set_friendId(const int32_t val);

  bool operator == (const FriendServices_removeFriend_args & rhs) const
  {
    if (!(curId == rhs.curId))
      return false;
    if (!(friendId == rhs.friendId))
      return false;
    return true;
  }
  bool operator != (const FriendServices_removeFriend_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_removeFriend_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FriendServices_removeFriend_pargs {
 public:


  virtual ~FriendServices_removeFriend_pargs() throw();
  const int32_t* curId;
  const int32_t* friendId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_removeFriend_result__isset {
  _FriendServices_removeFriend_result__isset() : success(false) {}
  bool success :1;
} _FriendServices_removeFriend_result__isset;

class FriendServices_removeFriend_result {
 public:

  FriendServices_removeFriend_result(const FriendServices_removeFriend_result&);
  FriendServices_removeFriend_result& operator=(const FriendServices_removeFriend_result&);
  FriendServices_removeFriend_result() : success((ErrorCode::type)0) {
  }

  virtual ~FriendServices_removeFriend_result() throw();
  ErrorCode::type success;

  _FriendServices_removeFriend_result__isset __isset;

  void __set_success(const ErrorCode::type val);

  bool operator == (const FriendServices_removeFriend_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FriendServices_removeFriend_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_removeFriend_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_removeFriend_presult__isset {
  _FriendServices_removeFriend_presult__isset() : success(false) {}
  bool success :1;
} _FriendServices_removeFriend_presult__isset;

class FriendServices_removeFriend_presult {
 public:


  virtual ~FriendServices_removeFriend_presult() throw();
  ErrorCode::type* success;

  _FriendServices_removeFriend_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _FriendServices_viewFriendList_args__isset {
  _FriendServices_viewFriendList_args__isset() : id(false), index(false), size(false) {}
  bool id :1;
  bool index :1;
  bool size :1;
} _FriendServices_viewFriendList_args__isset;

class FriendServices_viewFriendList_args {
 public:

  FriendServices_viewFriendList_args(const FriendServices_viewFriendList_args&);
  FriendServices_viewFriendList_args& operator=(const FriendServices_viewFriendList_args&);
  FriendServices_viewFriendList_args() : id(0), index(0), size(0) {
  }

  virtual ~FriendServices_viewFriendList_args() throw();
  int32_t id;
  int32_t index;
  int32_t size;

  _FriendServices_viewFriendList_args__isset __isset;

  void __set_id(const int32_t val);

  void __set_index(const int32_t val);

  void __set_size(const int32_t val);

  bool operator == (const FriendServices_viewFriendList_args & rhs) const
  {
    if (!(id == rhs.id))
      return false;
    if (!(index == rhs.index))
      return false;
    if (!(size == rhs.size))
      return false;
    return true;
  }
  bool operator != (const FriendServices_viewFriendList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_viewFriendList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class FriendServices_viewFriendList_pargs {
 public:


  virtual ~FriendServices_viewFriendList_pargs() throw();
  const int32_t* id;
  const int32_t* index;
  const int32_t* size;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_viewFriendList_result__isset {
  _FriendServices_viewFriendList_result__isset() : success(false) {}
  bool success :1;
} _FriendServices_viewFriendList_result__isset;

class FriendServices_viewFriendList_result {
 public:

  FriendServices_viewFriendList_result(const FriendServices_viewFriendList_result&);
  FriendServices_viewFriendList_result& operator=(const FriendServices_viewFriendList_result&);
  FriendServices_viewFriendList_result() {
  }

  virtual ~FriendServices_viewFriendList_result() throw();
  listFriendResult success;

  _FriendServices_viewFriendList_result__isset __isset;

  void __set_success(const listFriendResult& val);

  bool operator == (const FriendServices_viewFriendList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const FriendServices_viewFriendList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendServices_viewFriendList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _FriendServices_viewFriendList_presult__isset {
  _FriendServices_viewFriendList_presult__isset() : success(false) {}
  bool success :1;
} _FriendServices_viewFriendList_presult__isset;

class FriendServices_viewFriendList_presult {
 public:


  virtual ~FriendServices_viewFriendList_presult() throw();
  listFriendResult* success;

  _FriendServices_viewFriendList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class FriendServicesClient : virtual public FriendServicesIf {
 public:
  FriendServicesClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  FriendServicesClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t CreateUser(const InputProfileData& profile);
  void send_CreateUser(const InputProfileData& profile);
  int32_t recv_CreateUser();
  void GetUserInformation(GetUserResult& _return, const int32_t id);
  void send_GetUserInformation(const int32_t id);
  void recv_GetUserInformation(GetUserResult& _return);
  void checkRequest(pingResult& _return, const int32_t id);
  void send_checkRequest(const int32_t id);
  void recv_checkRequest(pingResult& _return);
  ErrorCode::type addFriend(const FriendRequest& request);
  void send_addFriend(const FriendRequest& request);
  ErrorCode::type recv_addFriend();
  ErrorCode::type acceptRequest(const int32_t curId, const int32_t requestId);
  void send_acceptRequest(const int32_t curId, const int32_t requestId);
  ErrorCode::type recv_acceptRequest();
  ErrorCode::type declineRequest(const int32_t curId, const int32_t requestId);
  void send_declineRequest(const int32_t curId, const int32_t requestId);
  ErrorCode::type recv_declineRequest();
  ErrorCode::type removeFriend(const int32_t curId, const int32_t friendId);
  void send_removeFriend(const int32_t curId, const int32_t friendId);
  ErrorCode::type recv_removeFriend();
  void viewFriendList(listFriendResult& _return, const int32_t id, const int32_t index, const int32_t size);
  void send_viewFriendList(const int32_t id, const int32_t index, const int32_t size);
  void recv_viewFriendList(listFriendResult& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class FriendServicesProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<FriendServicesIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (FriendServicesProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_CreateUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetUserInformation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_checkRequest(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addFriend(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_acceptRequest(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_declineRequest(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeFriend(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_viewFriendList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  FriendServicesProcessor(boost::shared_ptr<FriendServicesIf> iface) :
    iface_(iface) {
    processMap_["CreateUser"] = &FriendServicesProcessor::process_CreateUser;
    processMap_["GetUserInformation"] = &FriendServicesProcessor::process_GetUserInformation;
    processMap_["checkRequest"] = &FriendServicesProcessor::process_checkRequest;
    processMap_["addFriend"] = &FriendServicesProcessor::process_addFriend;
    processMap_["acceptRequest"] = &FriendServicesProcessor::process_acceptRequest;
    processMap_["declineRequest"] = &FriendServicesProcessor::process_declineRequest;
    processMap_["removeFriend"] = &FriendServicesProcessor::process_removeFriend;
    processMap_["viewFriendList"] = &FriendServicesProcessor::process_viewFriendList;
  }

  virtual ~FriendServicesProcessor() {}
};

class FriendServicesProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  FriendServicesProcessorFactory(const ::boost::shared_ptr< FriendServicesIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< FriendServicesIfFactory > handlerFactory_;
};

class FriendServicesMultiface : virtual public FriendServicesIf {
 public:
  FriendServicesMultiface(std::vector<boost::shared_ptr<FriendServicesIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~FriendServicesMultiface() {}
 protected:
  std::vector<boost::shared_ptr<FriendServicesIf> > ifaces_;
  FriendServicesMultiface() {}
  void add(boost::shared_ptr<FriendServicesIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t CreateUser(const InputProfileData& profile) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->CreateUser(profile);
    }
    return ifaces_[i]->CreateUser(profile);
  }

  void GetUserInformation(GetUserResult& _return, const int32_t id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetUserInformation(_return, id);
    }
    ifaces_[i]->GetUserInformation(_return, id);
    return;
  }

  void checkRequest(pingResult& _return, const int32_t id) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->checkRequest(_return, id);
    }
    ifaces_[i]->checkRequest(_return, id);
    return;
  }

  ErrorCode::type addFriend(const FriendRequest& request) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addFriend(request);
    }
    return ifaces_[i]->addFriend(request);
  }

  ErrorCode::type acceptRequest(const int32_t curId, const int32_t requestId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->acceptRequest(curId, requestId);
    }
    return ifaces_[i]->acceptRequest(curId, requestId);
  }

  ErrorCode::type declineRequest(const int32_t curId, const int32_t requestId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->declineRequest(curId, requestId);
    }
    return ifaces_[i]->declineRequest(curId, requestId);
  }

  ErrorCode::type removeFriend(const int32_t curId, const int32_t friendId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeFriend(curId, friendId);
    }
    return ifaces_[i]->removeFriend(curId, friendId);
  }

  void viewFriendList(listFriendResult& _return, const int32_t id, const int32_t index, const int32_t size) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->viewFriendList(_return, id, index, size);
    }
    ifaces_[i]->viewFriendList(_return, id, index, size);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class FriendServicesConcurrentClient : virtual public FriendServicesIf {
 public:
  FriendServicesConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  FriendServicesConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t CreateUser(const InputProfileData& profile);
  int32_t send_CreateUser(const InputProfileData& profile);
  int32_t recv_CreateUser(const int32_t seqid);
  void GetUserInformation(GetUserResult& _return, const int32_t id);
  int32_t send_GetUserInformation(const int32_t id);
  void recv_GetUserInformation(GetUserResult& _return, const int32_t seqid);
  void checkRequest(pingResult& _return, const int32_t id);
  int32_t send_checkRequest(const int32_t id);
  void recv_checkRequest(pingResult& _return, const int32_t seqid);
  ErrorCode::type addFriend(const FriendRequest& request);
  int32_t send_addFriend(const FriendRequest& request);
  ErrorCode::type recv_addFriend(const int32_t seqid);
  ErrorCode::type acceptRequest(const int32_t curId, const int32_t requestId);
  int32_t send_acceptRequest(const int32_t curId, const int32_t requestId);
  ErrorCode::type recv_acceptRequest(const int32_t seqid);
  ErrorCode::type declineRequest(const int32_t curId, const int32_t requestId);
  int32_t send_declineRequest(const int32_t curId, const int32_t requestId);
  ErrorCode::type recv_declineRequest(const int32_t seqid);
  ErrorCode::type removeFriend(const int32_t curId, const int32_t friendId);
  int32_t send_removeFriend(const int32_t curId, const int32_t friendId);
  ErrorCode::type recv_removeFriend(const int32_t seqid);
  void viewFriendList(listFriendResult& _return, const int32_t id, const int32_t index, const int32_t size);
  int32_t send_viewFriendList(const int32_t id, const int32_t index, const int32_t size);
  void recv_viewFriendList(listFriendResult& _return, const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif



#endif
