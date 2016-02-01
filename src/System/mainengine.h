#pragma once

#include "time.h"

#include <thread>
#include <mutex>
#include <functional>
#include <set>

namespace sbg
{

struct Engine;

struct MainEngine {
	MainEngine();
	MainEngine(MainEngine&&);
	MainEngine& operator=(MainEngine&&);
	MainEngine(const MainEngine&) = delete;
	MainEngine& operator=(const MainEngine&) = delete;
	~MainEngine();

	void setSpeed(double speed);
	double getSpeed();

	void add(std::shared_ptr<Engine> engine);
	void remove(std::shared_ptr<Engine> engine);
	void remove(std::weak_ptr<Engine> engine);
	
	void onUpdate(std::function<void()> callback);
	void onUpdate() const;

	void reset();
	void run(bool run);
	void update();
	
	Time getTime() const;
	
private:
	Time _time;
	std::thread _thread;
	
	std::function<void()> _onUpdate;
	bool _run = false;
	double _speed = 1;
	std::chrono::high_resolution_clock::time_point _timer = std::chrono::high_resolution_clock::now();

	std::set<std::weak_ptr<Engine>, std::owner_less<std::weak_ptr<Engine>>> _engines;
};


}
