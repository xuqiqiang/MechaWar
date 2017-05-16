#ifndef __PD_H__
#define __PD_H__
#include "GameManager.h"
#include "cocos2d.h"
#include "ResourceManager.h"
#include "GameScene.h"
#include "Status.h"
#include "CameraManager.h"
#include "ProgressMananger.h"

USING_NS_CC;

class RoundManager;
class ObjectManager;

class PD
{
public:

	static double OX, OY;
	static double W, H;
	static int screen_width, screen_height;

	static int situation, presituation;

	static const int SITUATION_WAITREADY = 0,
		SITUATION_STARTING = 1,
		SITUATION_PAUSE = 2,
		SITUATION_WIN = 3,
		SITUATION_LOSE = 4,
		SITUATION_CLEAN = 5,
		SITUATION_ACHIEVE = 6,
		SITUATION_BACK = 7;

	static const int TOUCH_DOWN = 0, TOUCH_MOVE = 1, TOUCH_UP = 2;


	static double lengthX;
	static double lengthW;
	static double lengthH;

	static const int ROW = 12;
	static const int COL = 18;

	static int round;

	static RoundManager* rm;
	static ProgressMananger* pm;
	static ObjectManager* om;
	//static GameManager* gm;
	static ResourceManager* resm;
	static CameraManager *cm;
	static GameScene *gs;

	static double delay;

	static Status *status;

	static void init(CCSize visibleSize, CCPoint origin);

	static void initGame(GameScene *gs);

	static void setsituation(int s);
	
};

#endif