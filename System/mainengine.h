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
#include "engine.h"

class MainEngine : private sf::Thread
{
public:
	//constructors and destructors
	MainEngine();
	~MainEngine();

	//start or stop the engine
	void setRunning(const bool state);
	bool getRunning() const;

	//speed
	void setSpeed(double speed);
	double getSpeed();
	
	//engines
	Engine& getEngine(const std::string tag);
	const Engine& getEngine(const std::string tag) const;

	Engine& addEngine(Engine* e, std::string alias);

private:
	double _speed;

	virtual void Run();
	bool _engineRunning; //this is the state of the engine
	double speed;

	std::map<std::string, Engine*> _engineList;
};

#endif // MAINENGINE_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
