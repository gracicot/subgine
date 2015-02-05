#pragma once

#include "time.h"

#include <thread>
#include <mutex>
#include <functional>
#include <set>

namespace sbg
{

class Engine;

class MainEngine
{
public:
	MainEngine();
	~MainEngine();

	void setSpeed(double speed);
	double getSpeed();

	void add(std::weak_ptr<Engine> engine);
	void remove(std::weak_ptr<Engine> engine);
	
	void onUpdate(std::function<void()> callback);
	void onUpdate() const;

	void reset();
	void run(bool run);
	void update();
private:
	Time _time;
	std::thread _thread;
	
	std::function<void()> _onUpdate;
	bool _run;
	double _speed;
	std::chrono::high_resolution_clock::time_point _timer;

	std::set<std::weak_ptr<Engine>, std::owner_less<std::weak_ptr<Engine>>> _engines;
};


}
