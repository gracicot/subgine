#include "mainengine.h"

#include <ratio>
#include <chrono>
#include <ctime>

#include "engine.h"

std::mutex MainEngine::_mutex;

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
	_thread = std::thread(&MainEngine::runThread, this);
}

void MainEngine::runThread()
{
	auto timer = std::chrono::high_resolution_clock::now();
	double time = 0;

	while (_running) {
		if (_loopPerSecond > 0) {
			std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1, 1>> (1.0 / (double) _loopPerSecond));
		}

		time = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1, 1>>> (std::chrono::high_resolution_clock::now() - timer).count() * _speed * 10.0;
		timer = std::chrono::high_resolution_clock::now();

		for (auto engines : _engineList) {
			engines.second->execute(time);
		}
	}
}

Engine& MainEngine::addEngine(const std::string alias, Engine* e)
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

Engine& MainEngine::getEngine(const std::string tag)
{
	std::map<std::string, Engine*>::iterator it = _engineList.find(tag);

	if (it != _engineList.end()) {
		return *it->second;
	}

	throw std::out_of_range("Cannot find Engine associated with tag " + tag + "...");
}

const Engine& MainEngine::getEngine(const std::string tag) const
{
	std::map<std::string, Engine*>::const_iterator it = _engineList.find(tag);

	if (it != _engineList.end()) {
		return *it->second;
	}

	throw std::out_of_range("Cannot find Engine associated with tag " + tag + "...");
}

int MainEngine::getLoopPerSecond() const
{
	return _loopPerSecond;
}

void MainEngine::setLoopPerSecond(const int loopPerSecond)
{
	_loopPerSecond = loopPerSecond;
}

std::mutex& MainEngine::mutex()
{
	return _mutex;
}
