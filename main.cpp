// This file is for class Poco::Application - main subsystem has responsiblility for initializing it's subsystems
// Can only have one instance in a process
// maintain a layered-configuration ??? TODO - Try to use it

// Code to include .. check later
//#include "Poco" ...

using namespace Poco::Util;

class DBSubsystem : public Subsystem
{

}

typedef class FriendServicesServer : public ServerApplication{
  public :
      FriendServicesServer(){
          // register sub system in here
          // Should have 2 subsystems upto now in this project
          // 1: Request handler
          // 2: Database
          Application::instance().addSubsystem();
Application::instance().addSubsystem();
}

~FriendServicesServer() {}

protected:
}
MyServer;