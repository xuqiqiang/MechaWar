#ifndef __HelpBar_H__
#define __HelpBar_H__


#include "PD.h"
#include "MyPoint.h"

//#include "SpriteManager.h"
#include "MyRectangle.h"
#include "MySprite.h"
#include "MathMethod.h"
#include "MyLabel.h"
#include "ObjectManager.h"



class HelpBarButton{
private:
	double x1, y1, w1, h1, x2, y2, w2, h2;
public:
	int type;
	bool ispress;
	static const int PAUSE_BT = 0, HIDE_BT = 1, PRODUCT_1 = 2, PRODUCT_2 = 3, PRODUCT_3 = 4, PRODUCT_4 = 5;
	bool visible;
	double x, y, w, h;
	CCRect r;

	MySprite *sprite1, *sprite2;

	CCLabelTTF* product_price;

	//HelpBarButton(){
	//}

	HelpBarButton(double x, double y, int type){

		this->x = x;
		this->y = y;

		this->type = type;

		w = PD::lengthW;
		h = PD::lengthH;

		r = CCRectMake(x,y,w,h);

		if (type == PRODUCT_2){
			w = PD::lengthW;
			h = MathMethod::getHeight("gun1.png",w);
			//h = (double)RM.gunbmp.getHeight() / (double)RM.gunbmp.getWidth()*PD.lengthH;
		}

		visible = true;
		ispress = false;
		//enable = true;

	}


	HelpBarButton(double xx, double yy, double ww, double hh,
		double xx1, double yy1, double ww1, double hh1,
		double xx2, double yy2, double ww2, double hh2, int type){
		x = xx;
		y = yy;
		w = ww;
		h = hh;

		r = CCRectMake(x, y, w, h);

		x1 = xx1;
		y1 = yy1;
		w1 = ww1;
		h1 = hh1;
		x2 = xx2;
		y2 = yy2;
		w2 = ww2;
		h2 = hh2;
		this->type = type;


		visible = true;
		ispress = false;
		//enable = true;
	}


	bool onTouch(CCPoint touch_point, int touch_event);

	void setXY(double x, double y){	//hideButton
		this->x = x;
		this->y = y;
		r = CCRectMake(x, y, w, h);

		sprite1->setXY(x, y);
	}

	void setVisible(bool visible){
		this->visible = visible;
		sprite1->setVisible(visible);
		if (sprite2!=NULL)
			sprite2->setVisible(visible);

		if (product_price != NULL)
			product_price->setVisible(visible);
	}

	void show(){
		//if (visible){
			//char* bmp1,bmp2;

		sprite2 = NULL;
		product_price = NULL;
		char str_price[20] = "";
		CCTexture2D *bmp1, *bmp2;
		if (type < PRODUCT_3){
			if (type == HIDE_BT){
				bmp1 = PD::resm->hide;// "hide.png";
			}
			else if (type == PAUSE_BT){
				bmp1 = PD::resm->pause; //"zhan.png";
			}
			else if (type == PRODUCT_1){
				bmp1 = PD::resm->mine; //"mine.png";

				sprintf(str_price, "$%d", Mine::price);
			}
			else if (type == PRODUCT_2){
				bmp1 = PD::resm->gun1; //"gun1.png";
				sprintf(str_price, "$%d", Tower::tower_price[Tower::PILLBOX]);
			}
			sprite1 = new MySprite(bmp1, x, y, w, h, false);
			PD::gs->addChild(sprite1, 100);
			PD::om->sprite->push_back(sprite1);
		}
		else{

			if (type == PRODUCT_3){
				bmp1 = PD::resm->gun31;
				sprite1 = new MySprite(bmp1, x1, y1, w1, h1, false);
				PD::gs->addChild(sprite1, 100);
				PD::om->sprite->push_back(sprite1);

				bmp2 = PD::resm->gun_tower; //"gun31.png";
				sprite2 = new MySprite(bmp2, 4, x2, y2, w2, h2, false);
				PD::gs->addChild(sprite2, 100);
				PD::om->sprite->push_back(sprite2);

				sprintf(str_price, "$%d", Tower::tower_price[Tower::ROCKET]);
			}
			else if (type == PRODUCT_4){

				bmp1 = PD::resm->gun31;
				sprite1 = new MySprite(bmp1, x1, y1, w1, h1, false);
				PD::gs->addChild(sprite1, 100);
				PD::om->sprite->push_back(sprite1);

				bmp2 = PD::resm->gun_tower_pro[13]; //"gun31.png";
				sprite2 = new MySprite(bmp2, x2, y2, w2, h2, false);
				PD::gs->addChild(sprite2, 100);
				PD::om->sprite->push_back(sprite1);

				sprintf(str_price, "$%d", Tower::tower_price[Tower::SMOKEROCKET]);
			}
		}

		if (strlen(str_price) > 0){
			product_price = MyLabel::getLabel(str_price, x + PD::W * 6, PD::H * 100 - PD::lengthH + PD::H * 7, PD::H * 3, "Arial");
			PD::gs->addChild(product_price, 101);
		}
	}

};


class HelpBar
{
public:
	HelpBar();

	bool showBar;

	//CCPoint touch_point;
	MyPoint pre_point;

	MySprite* bar;

	MyRectangle *rect1, *rect2;

	HelpBarButton *hideButton, *pauseButton, *productButton[4];

	

	void show();

	/*void ccTouchesBegan(CCPoint touchPoint);
	void ccTouchesMoved(CCPoint touchPoint);
	void ccTouchesEnded(CCPoint touchPoint);*/

	bool onTouch(CCPoint touch_point,int touch_event);

	void setShowBar(bool showBar);

	//void logic();

	void setRect(MyPoint location, int type);
};

#endif