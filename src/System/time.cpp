#include "time.h"

namespace sbg {

Time::Time(): _currentTime(0), _nextTime(0)
{

}

Time::Time(double currentTime, double nextTime):_currentTime(currentTime), _nextTime(nextTime)
{

}

double Time::getCurrentTime() const
{
	return _currentTime;
}

double Time::getNextTime() const
{
	return _nextTime;
}

void Time::setCurrentTime(double currentTime)
{
	_currentTime = currentTime;
}

void Time::setNextTime(double nextTime)
{
	_nextTime = nextTime;
}

}