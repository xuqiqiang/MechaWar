#ifndef __Plane_H__
#define __Plane_H__

#include "PD.h"
#include "Flyer.h"
#include "MySprite.h"
#include "MyRectangle.h"
class Plane : public Flyer
{
private:

	static const int type_sum = 6;

	static double plane_speed[type_sum];

	//static int direct_index[4];

	static const int new_plane_id = 2;

	static int direct_frame[4];

	int frame;
	int frame_sum;


	MySprite *sprite;
	MySprite *sprite_shadow;
	MyRectangle *sprite_blood;

protected:
	//virtual void arrive();
	virtual void attacted(double destoy);
	virtual void onMoveSprite();

	virtual void move();
public:

	int type;

	double real_x, real_y;
	double altitude;

	static double altitude_min;
	static double altitude_max;
	static double altitude_speed;

	static const int type_airship = 0, type_flysaucer = 1, type_helicopter = 3;


	static void initData(){
		int plane_speed_tmp[type_sum] = { 2, 3, 2, 2, 2, 2 };
		for (int i = 0; i < type_sum; i++){
			plane_speed[i] = (double)plane_speed_tmp[i] * PD::H / 8.0f;//
		}
		altitude_min = 3 * PD::lengthH;
		altitude_max = 4 * PD::lengthH;

		altitude_speed = PD::H / 8.0f;//


		int direct_frame_tmp[type_sum] = { 1, 0, 3, 2 };
		for (int i = 0; i < 4; i++){
			direct_frame[i] = direct_frame_tmp[i];
		}
	}

	Plane(int direct, int type, int blood);

	virtual void logic();

	virtual void setVisible(bool visible);

	virtual void release();
};

#endif