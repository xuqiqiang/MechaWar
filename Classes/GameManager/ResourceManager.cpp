#include "ResourceManager.h"

ResourceManager::ResourceManager(){
	background = CCTextureCache::sharedTextureCache()->addImage("background.jpg");

	house[0] = CCTextureCache::sharedTextureCache()->addImage("house1.png");
	house[1] = CCTextureCache::sharedTextureCache()->addImage("house2.png");
	house[2] = CCTextureCache::sharedTextureCache()->addImage("house3.png");
	house[3] = CCTextureCache::sharedTextureCache()->addImage("house4.png");
	house_shadow[0] = CCTextureCache::sharedTextureCache()->addImage("houseshadow1.png");
	house_shadow[1] = CCTextureCache::sharedTextureCache()->addImage("houseshadow2.png");
	house_shadow[2] = CCTextureCache::sharedTextureCache()->addImage("houseshadow3.png");
	house_shadow[3] = CCTextureCache::sharedTextureCache()->addImage("houseshadow4.png");

	bar = CCTextureCache::sharedTextureCache()->addImage("bar1.jpg");

	hide = CCTextureCache::sharedTextureCache()->addImage("hide.png");
	resume = CCTextureCache::sharedTextureCache()->addImage("jixu.png");
	pause = CCTextureCache::sharedTextureCache()->addImage("zhan.png");
	mine = CCTextureCache::sharedTextureCache()->addImage("mine.png");
	gun1 = CCTextureCache::sharedTextureCache()->addImage("gun1.png");
	gun_tower = CCTextureCache::sharedTextureCache()->addImage("gun_tower.png");
	gun31 = CCTextureCache::sharedTextureCache()->addImage("gun31.png");

	for (int i = 0; i < GUN_TOWER_PRO_SUM; i++){
		char str[20];
		if (i < 25)
			sprintf(str, "gun3%c.png", 'a' + i);
		else
			sprintf(str, "gun3z%c.png", 'a' + i - 25);
		gun_tower_pro[i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}

	range = CCTextureCache::sharedTextureCache()->addImage("range.png");
	mine = CCTextureCache::sharedTextureCache()->addImage("mine.png");


	
	for (int i = 0; i<16; i++){
		char str[20];
		if (i < 10)
			sprintf(str, "frame%c.png", '0' + i);
		else
			sprintf(str, "frame%c.png", 'a' + i - 10);
		bomb[0][i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}
	for (int i = 0; i<10; i++){
		char str[20];
		if (i < 9)
			sprintf(str, "bomb%c.png", '1' + i);
		else
			sprintf(str, "bomb%c.png", 'a');
		bomb[1][i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}

	explosion1 = CCTextureCache::sharedTextureCache()->addImage("explosion1.png");
	explosion2 = CCTextureCache::sharedTextureCache()->addImage("explosion2.png");

	promote = CCTextureCache::sharedTextureCache()->addImage("promote.png");

	advice = CCTextureCache::sharedTextureCache()->addImage("advice.png");


	char tank_type[6] = "5468a";
	char direct[5] = "urdl";// dlru";
	for (int i = 0; i < TANK_SUM; i++)
		for (int j = 0; j < 4; j++){
			char str[20];
			sprintf(str, "e%c%c.png", tank_type[i], direct[j]);
			tank[i][j] = CCTextureCache::sharedTextureCache()->addImage(str);
		}

	for (int i = 0; i<NEW_TANK_SUM; i++){
		char str[20];
		sprintf(str, "tank%d.png", i + 1);
		new_tank[i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}


	for (int i = 0; i<NEW_PLANE_SUM; i++){
		char str[20];
		sprintf(str, "plane%d.png", i + 1);
		new_plane[i] = CCTextureCache::sharedTextureCache()->addImage(str);

		sprintf(str, "planeshadow%d.png", i + 1);
		new_plane_shadow[i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}


	fire = CCTextureCache::sharedTextureCache()->addImage("fire2.png");
	
	for (int i = 0; i<4; i++){
		char str[20];
		sprintf(str, "e7%c.png", direct[i]);
		plane[0][i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}
	for (int i = 0; i<6; i++){
		char str[20];
		sprintf(str, "e9%c.png", 'a'+i);
		plane[1][i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}

	for (int i = 0; i<4; i++){
		char str[20];
		sprintf(str, "airshadow%c.png", direct[i]);
		plane_shadow[0][i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}
	plane_shadow[1][0] = CCTextureCache::sharedTextureCache()->addImage("e9shadow.png");

	missile1 = CCTextureCache::sharedTextureCache()->addImage("missile1.png");
	missile2 = CCTextureCache::sharedTextureCache()->addImage("missile2.png");


	for (int i = 0; i<4; i++){
		char str[20];
		sprintf(str, "select%d.png", i+1);
		target[i] = CCTextureCache::sharedTextureCache()->addImage(str);
	}
	
	wave = CCTextureCache::sharedTextureCache()->addImage("wave.png");

	honor = CCTextureCache::sharedTextureCache()->addImage("honor.png");
}