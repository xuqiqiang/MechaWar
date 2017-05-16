#ifndef __Timer_H__
#define __Timer_H__

class Timer
{
private:
	int time;
	int time_set;

	bool enable;
public:
	Timer(int time);

	bool run();
	bool runLoop();
	bool complete();
	void setTime();
	void setEnable(bool enable);
};

#endif