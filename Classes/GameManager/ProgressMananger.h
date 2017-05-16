#ifndef __ProgressMananger_H__
#define __ProgressMananger_H__

//#include "PD.h"
#include "MySprite.h"
#include "Timer.h"
class ProgressMananger
{
private:
	MySprite *sprite_wave;
	CCLabelTTF* label_wave;
	Timer *timer;

	int progress;

	static const int SHOW_WAVE = 0, SHOW_ADVICE = 1, STARTING = 2;

	static const int SHOW_WAVE_TIME = 2000;

	int round;
	int wave;

protected:
public:


	ProgressMananger(int round);

	void setProgress(int progress);

	void logic();

};

#endif