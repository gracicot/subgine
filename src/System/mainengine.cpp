#include "mainengine.h"

#include <iostream>
#include <ratio>
#include <chrono>
#include <ctime>

#include "engine.h"

using namespace std;


namespace subgine
{

MainEngine::MainEngine() : _speed(0), _timer(chrono::high_resolution_clock::now()), _time(0)
{

}

MainEngine::~MainEngine()
{
	if (_thread.joinable()) {
		_thread.join();
	}
}

void MainEngine::run()
{
	if (_thread.joinable()) {
		_thread.join();
	}
	
	_thread = thread(&MainEngine::runSync, this);
}

void MainEngine::runSync()
{
	_time = chrono::duration_cast<chrono::duration<double, ratio<1, 1>>> (chrono::high_resolution_clock::now() - _timer).count() * _speed;
	_timer = chrono::high_resolution_clock::now();

// 	auto timer2 = chrono::high_resolution_clock::now();
	int precision = 1;
	
	for (int i = 0 ; i<precision ; i++)
		for (auto engines : _engineList) {
			engines.second->execute(_time/precision);
	// 		cerr << engines.first << ": " << chrono::duration_cast<chrono::duration<double, milli>> (chrono::high_resolution_clock::now() - timer2).count() << endl;
	// 		timer2 = chrono::high_resolution_clock::now();
		}
}

Engine& MainEngine::addEngine(const string alias, Engine* e)
{
	_engineList[alias] = e;
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

}

