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


#include "mainengine.h"

#include "engine.h"

MainEngine::MainEngine()
{
	_running = false;

}

MainEngine::~MainEngine()
{
	_running = false;
	this->Wait();

}

void MainEngine::running(const bool state)
{
	if(!_running && state)
	{
		_running = true;
		this->Launch();
	}
	else if(_running && !state)
	{
		_running = false;
		this->Wait();
	}

}

void MainEngine::Run()
{
	sf::Clock timer;
	float time = 0;

	while(_running)
	{
		sf::Sleep(1.0 / 90.0);
		time = timer.GetElapsedTime() * _speed * 10.0;
		timer.Reset();

	for(auto engines : _engineList)
		{
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

	if(it != _engineList.end())
	{
		return *it->second;
	}

	throw std::out_of_range("Cannot find Engine associated with tag " + tag + "...");
}

const Engine& MainEngine::getEngine(const std::string tag) const
{
	std::map<std::string, Engine*>::const_iterator it = _engineList.find(tag);

	if(it != _engineList.end())
	{
		return *it->second;
	}

	throw std::out_of_range("Cannot find Engine associated with tag " + tag + "...");
}


