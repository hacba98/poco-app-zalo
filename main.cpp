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
#include "Poco/TaskNotification.h"
#include "Poco/Exception.h"
#include "Poco/Path.h"

#include "Poco/Observer.h"

#include <iostream>
#include <string>
#include <vector>

#include "SubKC.h" // for DB subsystem
#include "SubHandler.h" // for server subsystem
#include "SubCache.h" // for cache subsystem

using namespace Poco;
using namespace Poco::Util;
using namespace std;

class RunTask : public Poco::Task {
public:

	RunTask(std::string name) : Poco::Task(name) {
	}

	void runTask() {
		setProgress(0);
		SubHandler &server = Application::instance().getSubsystem<SubHandler>();
		SubKC &db = Application::instance().getSubsystem<SubKC>();
		db.run();
		server.start();
	}

	void cancel() {
		SubHandler &server = Application::instance().getSubsystem<SubHandler>();
		server.terminate();
	}
};

class FriendServicesServer : public ServerApplication {
public:

	FriendServicesServer() : _helpRequested(false) {
		// register sub system in here -> due to requirement of server 
		// 1: Request handler
		addSubsystem(new SubKC());
		// 2: Database - 
		addSubsystem(new SubHandler());
		// 3: Cache
		addSubsystem(new SubCache());
	}

	~FriendServicesServer() {
	}
	
	void runSystem() {
		try {
			SubKC& database = this->getSubsystem<SubKC>();
			SubHandler& server = this->getSubsystem<SubHandler>();
			database.run();
			server.start();
		} catch (Poco::Exception e) {
			logger().error(e.message());
		}
	}

	void stopSystem() {
		try {
			SubHandler& server = this->getSubsystem<SubHandler>();
			server.terminate();
		} catch (Poco::Exception e) {
			logger().error(e.message());
		}
	}

protected:

	void initialize(Application& self) {

		if (_helpRequested) return;
		cout << "Starting Server ..." << endl;

		// initialize application's subsystems
		try {
			ServerApplication::initialize(self);
		} catch (Poco::Exception e) {
			logger().error(e.message());
		}

		// redirect log into file if running in background
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
			.argument("file")
			.binding("server.configuration.XML")
			.callback(OptionCallback<FriendServicesServer>(this, &FriendServicesServer::handleConfig)));
	}

	int main(const std::vector<string>& args) {
		if (_helpRequested) {
			displayHelp();
		} else {
			// Run
			//			runSystem();
			//			waitForTerminationRequest();
			//			stopSystem();
			//			//uninitialize();

			// Task manager version
			Poco::ThreadPool pool;
			Poco::TaskManager tm(pool);
			tm.start(new RunTask("application"));
			waitForTerminationRequest();
			tm.cancelAll();
			tm.joinAll();
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

	void handleConfig(const std::string& name, const std::string& value) {
		// pass
		// load from XML file
		Poco::Path pXML(config().getString("server.configuration.XML"));
		if (Application::findFile(pXML)) {
			loadConfiguration(pXML.getFileName(), 0);
		} else {
			throw Poco::Exception("Cannot find configuration file.");
		}

		return;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	void initializeLogging() {
		try {
			const std::string path = config().getString("server.log[@information]");
			Poco::AutoPtr<Poco::FileChannel> fileChannel(new Poco::FileChannel(path));
			logger().setChannel(fileChannel);
			return;
		} catch (Poco::Exception e) {
			logger().error(e.message());
		}
		// logging some basic data
		// Starting time
		//		char buffer[30];
		//		time_t starting = startTime().epochTime();
		//		strftime(buffer, sizeof(buffer), "%H:%M  %d %h %Y", localtime(&starting));
		//		logger().information(Logger::format("Starting Server at time: $0", string(buffer)));
		//		logger().information(Logger::format("Port running: $0", config().getString("server.port")));
		//logger().information(Logger::format("PID: $0", string(Poco::Process::id())));
	}

private:
	bool _helpRequested;
};

typedef FriendServicesServer _MyServer_;

int main(int argc, char** argv) {
	_MyServer_ app;
	return app.run(argc, argv);
}
