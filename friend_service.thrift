/**
	Thrift file define services for friend function
	Project Friend Services
*/

// Structure for containing basic user's information
struct User {
	1: i32 id, // TODO - Find a way to make this unique
	2: string name,
	3: bool isMale,
	4: i32 birthDate,
	5: i32 lastActive, // 0 - active
	6: i32 phoneNumber,
}

struct FriendList {
	1: i32 size,
	2: set<i32> data
}

struct PendingRequest {
	1: i32 size,
	2: set<i32> data
}

struct FriendRequest {
	1: i32 p_send_req, // id of person who sending friend request
	2: i32 p_recv_req, // vice versa
	3: string greeting,
	4: i32 time
}

////////////////////////////////////////////////////////
//		Services exposed by server            //
////////////////////////////////////////////////////////

// Define enum type
// -- Define enum error code	
enum ErrorCode {
	SUCCESS = 0,
	USER_NOT_FOUND = 1,
	INVALID_PARAMETER = 2,
	INVALID_SERVICE = 3,
	INTERNAL_ERROR = 4,
}

// Define data structure for services
// -- Structure client send to create new user --
struct InputProfileData {
	1: string name,
	2: bool isMale,
	3: i32 birthDate,
	4: i32 phoneNumber
}

// -- Structure server send to return user information
struct GetUserResult {
	1: required ErrorCode code,
	2: User data
}

struct pingResult {
	1: bool haveData,
	2: set<i32> pendingData
}

struct listFriendResult {
	1: i32 size,
	2: i32 idx,
	3: set<i32> friendList
}

service FriendServices{
	// -- Basic api for testing server and DB --
	// Create new User
	i32 CreateUser (1: InputProfileData profile),
	// Get User
	GetUserResult GetUserInformation(1: i32 id),

	// -- API for friend function
	// Check for new friend request
	pingResult checkRequest(1: i32 id);

	// Add new friend -> Async req
	ErrorCode addFriend(1: FriendRequest request);
	
	// Accept request
	ErrorCode acceptRequest(1: i32 curId, 2: i32 requestId);

	// Decline request
	ErrorCode declineRequest(1: i32 curId, 2: i32 requestId);

	// Remove a friend
	ErrorCode removeFriend(1: i32 curId, 2: i32 friendId);

	// View friend list
	listFriendResult viewFriendList (1: i32 id, 2: i32 index, 3: i32 size);
}

