#ifndef __ResourceManager_H__
#define __ResourceManager_H__

#include "cocos2d.h"
USING_NS_CC;

class ResourceManager
{
public:
	ResourceManager();

	CCTexture2D* background;

	static int const HOUSE_TYPES = 4;

	CCTexture2D* house[HOUSE_TYPES];
	CCTexture2D* house_shadow[HOUSE_TYPES];

	CCTexture2D* bar;

	CCTexture2D* hide;
	CCTexture2D* resume;
	CCTexture2D* pause;
	CCTexture2D* mine;
	CCTexture2D* gun1;
	CCTexture2D* gun_tower;

	static int const GUN_TOWER_PRO_SUM = 32;
	CCTexture2D* gun_tower_pro[GUN_TOWER_PRO_SUM];
	CCTexture2D* gun31;
	CCTexture2D* range;

	CCTexture2D* bomb[2][16];
	CCTexture2D* explosion1;
	CCTexture2D* explosion2;

	CCTexture2D* promote;
	CCTexture2D* advice;

	static int const TANK_SUM = 5;
	CCTexture2D* tank[TANK_SUM][4];

	static int const NEW_TANK_SUM = 6;
	CCTexture2D* new_tank[NEW_TANK_SUM];

	CCTexture2D* fire;

	CCTexture2D* plane[2][6];
	CCTexture2D* plane_shadow[2][4];

	static int const NEW_PLANE_SUM = 4;
	CCTexture2D* new_plane[NEW_PLANE_SUM];
	CCTexture2D* new_plane_shadow[NEW_PLANE_SUM];

	CCTexture2D *missile1, *missile2;
	CCTexture2D *target[4];

	CCTexture2D *wave;
	CCTexture2D *honor;
};

#endif