#include "mainengine.h"

#include <iostream>
#include <ratio>
#include <chrono>
#include <algorithm>

#include "engine.h"

using namespace std;

namespace sbg
{

MainEngine::MainEngine() = default;
MainEngine::MainEngine(MainEngine&&) = default;
MainEngine& MainEngine::operator=(MainEngine&&) = default;


MainEngine::~MainEngine()
{
	if (_thread.joinable()) {
		_thread.join();
	}
}

void MainEngine::reset()
{
	_timer = chrono::high_resolution_clock::now();
	_time = {};
}

void MainEngine::run(bool run)
{
	_run = run;
	
	if (run) {
		reset();
		_thread = thread([&](){
			while (_run) {
				update();
				onUpdate();
			}
		});
	} else {
		if (_thread.joinable()) {
			_thread.join();
		}
	}
}

void MainEngine::onUpdate() const
{
	if (_onUpdate) {
		_onUpdate();
	}
}

void MainEngine::onUpdate(function< void() > callback)
{
	_onUpdate = callback;
}

void MainEngine::update()
{
	double lastTime = _time.getCurrentTime();
	_time.setCurrentTime(_time.getNextTime());
	_time.setNextTime(((chrono::duration_cast<chrono::duration<double, ratio<1, 1>>> (chrono::high_resolution_clock::now() - _timer).count() * _speed) + lastTime + _time.getCurrentTime())/3.0);
	_timer = chrono::high_resolution_clock::now();

	
// 	auto timer2 = chrono::high_resolution_clock::now();
	for (auto ref : _engines) {
		if (!ref.expired()) {
			auto engine = ref.lock();
			engine->execute(_time);
		} else {
			remove(ref);
		}
// 		cerr << engines.first << ": " << chrono::duration_cast<chrono::duration<double, milli>> (chrono::high_resolution_clock::now() - timer2).count() << endl;
// 		timer2 = chrono::high_resolution_clock::now();
	}
}

void MainEngine::add(weak_ptr<Engine> engine)
{
	_engines.insert(engine);
}

void MainEngine::remove(weak_ptr<Engine> engine)
{
	auto it = find_if(_engines.begin(), _engines.end(), [&engine](weak_ptr<Engine> other){
		return !engine.owner_before(other) && !other.owner_before(engine);
	});
	
	if (it != _engines.end()) {
		_engines.erase(it);
	}
}

double MainEngine::getSpeed()
{
	return _speed;
}

void MainEngine::setSpeed(double speed)
{
	_speed = speed >= 0 ? speed : 0;
}

Time MainEngine::getTime() const
{
	return _time;
}

}
