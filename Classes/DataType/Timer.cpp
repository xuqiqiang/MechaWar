#include "Timer.h"
#include "PD.h"

Timer::Timer(int time){
	this->time = time;
	time_set = time;
	enable = true;
}

bool Timer::run(){
	if (!enable)
		return false;

	if (time <= 0)
		return true;
	time -= PD::delay;
	return false;
}

bool Timer::runLoop(){
	if (!enable)
		return false;

	if (time <= 0){
		time = time_set;
		return true;
	}
	time -= PD::delay;
	return false;
}

bool Timer::complete(){
	if (!enable)
		return false;
	return (time <= 0);
}

void Timer::setTime(){
	time = time_set;
}

void Timer::setEnable(bool enable){
	this->enable = enable;
}