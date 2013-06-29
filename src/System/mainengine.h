#pragma once

#include "const.h"
#include <thread>
#include <mutex>


namespace subgine
{

class Engine;

class MainEngine
{
public:
	//constructors and destructors
	MainEngine();
	~MainEngine();

	//start or stop the engine
	void running(const bool state);
	bool isRunning() const;

	//speed
	void setSpeed(double speed);
	double getSpeed();

	void setLoopPerSecond(const int loopPerSecond);
	int getLoopPerSecond() const;

	//engines
	Engine& getEngine(const std::string tag);
	const Engine& getEngine(const std::string tag) const;

	Engine& addEngine(const std::string alias, Engine* e);

	static std::mutex& mutex();
	void runThread();

private:
	std::thread _thread;
	static std::mutex _mutex;

	int _loopPerSecond;
	double _speed;

	void launchThread();

	bool _running;
	double speed;

	std::map<std::string, Engine*> _engineList;
};


}
