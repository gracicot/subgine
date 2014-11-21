#pragma once

#include <map>
#include <thread>
#include <mutex>
#include <functional>

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
	
	void onUpdate(std::function<void()> callback);
	void onUpdate() const;

	void reset();
	void run(bool run);
	void update();
private:
	std::thread _thread;
	
	std::function<void()> _onUpdate;
	bool _run;
	double _speed;
	double _time;
	std::chrono::high_resolution_clock::time_point _timer;

	std::map<std::string, Engine*> _engineList;
};


}
