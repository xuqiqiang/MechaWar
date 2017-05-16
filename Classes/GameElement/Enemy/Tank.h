#ifndef __Tank_H__
#define __Tank_H__

#include "PD.h"
#include "Runner.h"
#include "MyRectangle.h"

class Tank : public Runner
{
private:
	static double destroy_field;

	static const int new_tank_id = 5;
	int frame;
	int frame_sum;

	static int direct_frame[4];

protected:
	
	virtual void onSpriteMove();
public:

	int type;

	static const int type_sum = 10;
	//static boolean have[] = new boolean[type_sum];

	static double tank_speed[type_sum];// = { 2, 5, 3, 4, 4, 4, 4, 4, 4, 4 };

	static void initData(){
		int tank_speed_tmp[type_sum] = { 3, 5, 3, 4, 4, 4, 4, 4, 4, 4 };
		for (int i = 0; i < type_sum; i++){
			tank_speed[i] = tank_speed_tmp[i] * PD::H / 8.0f;//
		}

		destroy_field = PD::lengthX * 2;


		int direct_frame_tmp[type_sum] = { 1, 0, 3, 2 };
		for (int i = 0; i < 4; i++){
			direct_frame[i] = direct_frame_tmp[i];
		}
	}

	//MySprite *sprite;
	MyRectangle *sprite_blood;

	Tank(double x, double y, int type, int blood);

	virtual void onChangeDirection();

	virtual void arrive();
	//virtual void show();
	virtual void attacted(double destoy);

	virtual void setVisible(bool visible);

	virtual void release();
};

#endif