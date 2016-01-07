#pragma once

namespace sbg {

struct Time {
	Time();
	Time(double currentTime, double nextTime);
	
	double getCurrentTime() const;
	double getNextTime() const;
	
	void setCurrentTime(double currentTime);
	void setNextTime(double nextTime);
	
private:
	double _currentTime;
	double _nextTime;
};

}
