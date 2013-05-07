/*
    Copyright 2012 <copyright holder> <email>

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/


#ifndef MAINENGINE_H
#define MAINENGINE_H

#include "const.h"
#include <thread>
#include <mutex>

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

#endif // MAINENGINE_H

