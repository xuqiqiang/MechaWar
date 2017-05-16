#ifndef __ObjectManager_H__
#define __ObjectManager_H__

//#include "HelpBar.h"
#include "Map.h"
#include "Wall.h"
#include "Mine.h"
#include "Attackfield.h"
#include "Tower.h"
#include "Enemy.h"
#include "Timer.h"
#include "Bullet.h"
#include "Blast.h"
#include "MySprite.h"
#include "MyRectangle.h"
#include "MainTarget.h"

#include<vector>
using namespace std;

class HelpBar;

class ObjectManager
{
public:
	ObjectManager();

	CCLabelTTF* label_money;
	CCLabelTTF* label_blood;

	Attackfield *attackfield;
	HelpBar* helpBar;
	Map* map;
	vector<Wall*>* wall;
	vector<Mine*>* mine;
	vector<Tower*>* tower;
	vector<Enemy*>* enemy;
	vector<Bullet*>* bullet;
	vector<Blast*>* blast;


	vector<MySprite*>* sprite;

	vector<MyRectangle*>* rectangle;


	//Enemy *main_target;

	MainTarget *mainTarget;

	Timer* timer;


	void init();

	void initWall();

	void show();

	bool onTouch(CCPoint touch_point, int touch_event);

	void logic();

	void refreshStatus();

	void refreshView();
};

#endif