#ifndef __Mine_H__
#define __Mine_H__


#include "PD.h"
#include "MyPoint.h"
#include "MySprite.h"
#include "Timer.h"
#include "MathMethod.h"


class Smoke{
public:
	double x, y, width, height, speed;
	int exist_time;
	bool visible;
	MySprite *spirit;

	Smoke(){
		visible = false;
	}
	Smoke(double xx, double yy, double ww, double hh){
		x = xx;
		y = yy;
		width = ww;
		height = hh;
		speed = 7;
		visible = true;
		exist_time = 8;
		

		spirit = new MySprite(PD::resm->explosion2, 20 - exist_time, x, y, width, height, true);
		PD::gs->addChild(spirit, 3);
	}
	void run(){
		if (visible){
			if (exist_time == 0){
				visible = false;
				return;
			}
			//spirit.setTexture_frame(20 - existtime);
			//spirit.show();
			//Drawer.DrawImage_frame(20-existtime,PD.resm.bombbmp1.getWidth()/PD.resm.bombbmp1.getHeight(),PD.resm.bombbmp1,(float)(x),(float)(y),(float)wid,(float)hei,true);
			y -= speed;
			x -= speed / 4;
			width += speed / 2;
			height += speed / 2;
			exist_time--;

			spirit->setXY(x, y);
			spirit->setSize(width, height);
			spirit->setFrame(20 - exist_time);
		}
	}

	void setVisible(bool visible){
		this->visible = visible;
		spirit->setVisible(visible);
	}

	void release(){
		MathMethod::releaseSprite(spirit);
		delete this;
	}
};

class Mine
{
public:

	static const int price = 15;
	static const int run_delay = 2000;
	int i, j;
	bool visible;
	int moneyplus;

	Timer *timer;

	Smoke *smoke1, *smoke2;

	Mine(int i,int j);

	MySprite *spirit;

	

	void show();

	void run();

	void destroyed();

	void setVisible(bool visible);

	void release();
};

#endif