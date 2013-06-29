#include "mainengine.h"

#include <ratio>
#include <chrono>
#include <ctime>

#include "engine.h"

using namespace std;


namespace subgine
{



mutex MainEngine::_mutex;

MainEngine::MainEngine() : _speed(0), _running(false), _loopPerSecond(90)
{

}

MainEngine::~MainEngine()
{
	running(false);
}

void MainEngine::running(const bool state)
{
	if (!_running && state) {
		_running = true;
		launchThread();
	} else if (_running && !state) {
		_running = false;
		_thread.join();
	}
}

void MainEngine::launchThread()
{
	_thread = thread(&MainEngine::runThread, this);
}

void MainEngine::runThread()
{
	auto timer = chrono::high_resolution_clock::now();
	double time = 0;

	while (_running) {
		if (_loopPerSecond > 0) {
			this_thread::sleep_for(chrono::duration<double, ratio<1, 1>> (1.0 / (double) _loopPerSecond));
		}

		time = chrono::duration_cast<chrono::duration<double, ratio<1, 1>>> (chrono::high_resolution_clock::now() - timer).count() * _speed * 10.0;
		timer = chrono::high_resolution_clock::now();

		for (auto engines : _engineList) {
			engines.second->execute(time);
		}
	}
}

Engine& MainEngine::addEngine(const string alias, Engine* e)
{
	_engineList[alias] = e;
}

bool MainEngine::isRunning() const
{
	return _running;
}

double MainEngine::getSpeed()
{
	return _speed;
}

void MainEngine::setSpeed(double speed)
{
	_speed = speed >= 0 ? speed : 0;
}

Engine& MainEngine::getEngine(const string tag)
{
	map<string, Engine*>::iterator it = _engineList.find(tag);

	if (it != _engineList.end()) {
		return *it->second;
	}

	throw out_of_range("Cannot find Engine associated with tag " + tag + "...");
}

const Engine& MainEngine::getEngine(const string tag) const
{
	map<string, Engine*>::const_iterator it = _engineList.find(tag);

	if (it != _engineList.end()) {
		return *it->second;
	}

	throw out_of_range("Cannot find Engine associated with tag " + tag + "...");
}

int MainEngine::getLoopPerSecond() const
{
	return _loopPerSecond;
}

void MainEngine::setLoopPerSecond(const int loopPerSecond)
{
	_loopPerSecond = loopPerSecond;
}

mutex& MainEngine::mutex()
{
	return _mutex;
}

}

