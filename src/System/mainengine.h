#pragma once

#include <map>
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

	//speed
	void setSpeed(double speed);
	double getSpeed();

	//engines
	Engine& getEngine(const std::string tag);
	const Engine& getEngine(const std::string tag) const;

	void addEngine(const std::string alias, Engine* e);

	void run(bool run);
	void pause(bool pause);
	void update();
private:
	
	std::thread _thread;
	std::mutex _mutex;
	
	bool _run;
	double _speed;
	double _time;
	std::chrono::high_resolution_clock::time_point _timer;

	std::map<std::string, Engine*> _engineList;
};


}
