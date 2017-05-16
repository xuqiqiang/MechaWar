#ifndef __Tower_H__
#define __Tower_H__

#include "PD.h"
#include "Enemy.h"
#include "MySprite.h"

class Tower
{
public:
	static const int grade_max = 3;
	int grade;
	int update_price;

private:
	bool isTargetFar();
protected:

	

	MySprite *sprite_honor[grade_max];
	double x, y, w, h;
	//MyRect r;
	
	double field, destoy, price;
	bool ispress;
	bool angle_changed;// = false;


	virtual bool checkMainTarget();
	virtual bool findTarget();
public:

	bool visible;
	int i, j;
	Tower();
	//double bmpwidth, bmpheight;
	

	static const int TYPE_SUM = 3;
	static const int PILLBOX = 0, ROCKET = 1, SMOKEROCKET = 2;

	

	static double tower_field[TYPE_SUM];
	static double tower_destory[TYPE_SUM];

	static int tower_price[TYPE_SUM];

	Enemy *target;// = null;
	double angle;


	static void initData(){
		double tower_field_tmp[TYPE_SUM] = {
				2 * PD::lengthX,
				3 * PD::lengthX,
				3 * PD::lengthX
		};

		double tower_destory_tmp[TYPE_SUM] = {
				1,//12,
				10,//0,
				10,//0
		};

		int tower_price_tmp[TYPE_SUM] = {
				10,
				50,
				50
		};

		for (int i = 0; i < TYPE_SUM; i++){
			tower_field[i] = tower_field_tmp[i];
			tower_destory[i] = tower_destory_tmp[i];
			tower_price[i] = tower_price_tmp[i];
		}
	}

	Tower(int i, int j);

	void show();

	void onTouch(CCPoint touch_point, int touch_event);

	virtual void shoot();

	virtual void promote();

	void destroyed();

	virtual void setVisible(bool visible);

	virtual void release();
};

#endif