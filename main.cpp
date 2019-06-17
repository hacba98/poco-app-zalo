// This file is for class Poco::Application - main subsystem has responsiblility for initializing it's subsystems
// Can only have one instance in a process
// maintain a layered-configuration ??? TODO - Try to use it

// Code to include .. check later
#include "Poco/Util/Util.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/OptionCallback.h"
#include "Poco/Util/IntValidator.h"
#include "Poco/Util/Subsystem.h"
#include "Poco/Process.h"
#include "Poco/AutoPtr.h"
#include "Poco/Logger.h"
#include "Poco/LogFile.h"
#include "Poco/FileChannel.h"
#include "Poco/TaskManager.h"
#include "Poco/Task.h"
#include "Poco/Exception.h"

#include <iostream>
#include <string>
#include <vector>

#include "SubKC.h" // for DB subsystem
#include "SubHandler.h" // for server subsystem
#include "SubCache.h" // for cache subsystem

using namespace Poco;
using namespace Poco::Util;
using namespace std;

class FriendServicesServer : public ServerApplication {
public:

	FriendServicesServer() : _helpRequested(false) {
	}

	~FriendServicesServer() {
	}

protected:

	void initialize(Application& self) {

		if (_helpRequested) return;
		cout << "starting Server ..." << endl;
		loadConfiguration();

		// Set path to data file storage
		// TODO : load from configurate file
		configConnection();

		// register sub system in here
		// Should have 2 subsystems upto now in this project
		// 1: Request handler
		// 2: Database - 
		// 3: Cache
		addSubsystem(new SubKC());
		addSubsystem(new SubHandler());
		addSubsystem(new SubCache());


		// initialize application's subsystems
		try {
			ServerApplication::initialize(self);
		} catch (Poco::Exception e) {
			logger().error(e.message());
		}

		// redirect log into file if running in background
		//if (!isInteractive())
		initializeLogging();

	}

	void uninitialize() {
		cout << "\nShutting down server" << endl;
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet& options) {
		ServerApplication::defineOptions(options);

		options.addOption(
			Option("help", "h", "display help information")
			.required(false)
			.repeatable(false));

		options.addOption(
			Option("port", "p", "provide port number")
			.required(false)
			.argument("value")
			.validator(new IntValidator(0, 65535))
			.binding("server.port"));

		options.addOption(
			Option("config-file", "f", "load configuration data from a file")
			.required(false)
			.repeatable(true)
			.argument("file"));
		//.callback(OptionCallback<FriendServicesServer>(this, &FriendServicesServer::handleConfig)));
	}

	void runSystem() {
		try {
			SubKC& database = this->getSubsystem<SubKC>();
			SubHandler& server = this->getSubsystem<SubHandler>();
			database.run();
			server.start(*this);
		} catch (Poco::Exception e) {
			this->logger().error(e.message());
		}
	}

	int main(const std::vector<string>& args) {
		if (_helpRequested) {
			displayHelp();
		} else {
			// Run
			runSystem();
			waitForTerminationRequest();
			uninitialize();
		}
		return Application::EXIT_OK;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	void handleOption(const std::string& name, const std::string& value) {
		ServerApplication::handleOption(name, value);

		if (name == "help") {
			_helpRequested = true;
			stopOptionsProcessing();
		}

	}

	void displayHelp() {
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("A sample server application that demonstrate friend function.");
		helpFormatter.format(std::cout);
	}

	void handleConfig() {
		// pass
		return;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	void configConnection() {
		config().setString("database.user", string("./storage/friend.user.kch"));
		config().setString("database.counter", string("./storage/friend.counter.kch"));
		config().setString("database.friend", string("./storage/friend.list.kch"));
		config().setString("database.pending", string("./storage/friend.pending.kch"));
		config().setString("database.request", string("./storage/friend.request.kch"));
	}

	void initializeLogging() {
		const std::string path = "./log.txt";
		Poco::AutoPtr<Poco::FileChannel> fileChannel(new Poco::FileChannel(path));
		logger().setChannel(fileChannel);

		// logging some basic data
		// Starting time
		//		char buffer[30];
		//		time_t starting = startTime().epochTime();
		//		strftime(buffer, sizeof(buffer), "%H:%M  %d %h %Y", localtime(&starting));
		//		logger().information(Logger::format("Starting Server at time: $0", string(buffer)));
		//		logger().information(Logger::format("Port running: $0", config().getString("server.port")));
		//logger().information(Logger::format("PID: $0", string(Poco::Process::id())));
		return;
	}

private:
	bool _helpRequested;
};

typedef FriendServicesServer _MyServer_;

int main(int argc, char** argv) {
	_MyServer_ app;
	return app.run(argc, argv);
}
