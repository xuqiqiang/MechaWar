#include "HelpBar.h"
#include "ObjectManager.h"
#include "Attackfield.h"
#include "Tower.h"
#include "Pillbox.h"
#include "Rocket.h"
#include "SmokeRocket.h"




HelpBar::HelpBar(){

	showBar = true;

	hideButton = new HelpBarButton(PD::lengthW * 4, PD::H * 100 - PD::lengthH, HelpBarButton::HIDE_BT);
	pauseButton = new HelpBarButton(0, PD::H * 100 - PD::lengthH, HelpBarButton::PAUSE_BT);

	productButton[0] = new HelpBarButton(PD::lengthW * 6, PD::H * 100 - PD::lengthH, HelpBarButton::PRODUCT_1);
	productButton[1] = new HelpBarButton(PD::lengthW * 8,
		PD::H * 100 - PD::lengthH - (double)((MathMethod::height_div_width(PD::resm->gun1) - 1)*PD::lengthH / 2),
		HelpBarButton::PRODUCT_2);
	productButton[2] = new HelpBarButton((float)(PD::lengthW * 10), (float)(PD::H * 100 - PD::lengthH)
		, (float)PD::lengthW, (float)PD::lengthH
		, (float)(10 * PD::lengthW + PD::lengthW / 2 - MathMethod::width_div_height(PD::resm->gun31)*PD::lengthW / 2 / 2), (float)(PD::H * 100 - PD::lengthH + PD::lengthH / 2)
		, MathMethod::width_div_height(PD::resm->gun1)*PD::lengthW / 2, PD::lengthH / 2
		, (float)(10 * PD::lengthW - PD::W*0.2), (float)(PD::H * 100 - PD::lengthH)
		, PD::lengthW, PD::lengthH
		, HelpBarButton::PRODUCT_3);
	productButton[3] = new HelpBarButton((float)(PD::lengthW * 12), (float)(PD::H * 100 - PD::lengthH)
		, (float)PD::lengthW, (float)PD::lengthH
		, (float)(12 * PD::lengthW + PD::lengthW / 2 - MathMethod::width_div_height(PD::resm->gun1)*PD::lengthW / 2 / 2), (float)(PD::H * 100 - PD::lengthH + PD::lengthH / 2)
		, MathMethod::width_div_height(PD::resm->gun1)*PD::lengthW / 2, PD::lengthH / 2
		, (float)(12 * PD::lengthW + PD::lengthW / 2 - MathMethod::width_div_height(PD::resm->gun1)*PD::lengthW / 2 / 2), (float)(PD::H * 100 - PD::lengthH)
		, MathMethod::width_div_height(PD::resm->gun1)*PD::lengthW / 2, PD::lengthH / 2
		, HelpBarButton::PRODUCT_4);




	pre_point = Point_null;
}


void HelpBar::show(){
	
	bar = new MySprite(PD::resm->bar, PD::lengthW * 4, PD::H * 100 - PD::lengthH,
		PD::W * 100 - PD::lengthW * 4, PD::lengthH, false);
	PD::gs->addChild(bar, 100);
	PD::om->sprite->push_back(bar);

	hideButton->show();
	pauseButton->show();
	for (int i = 0; i < 4; i++)
		productButton[i]->show();

	rect1 = new MyRectangle(0, 0, PD::lengthW, PD::screen_height, ccc4f(0, 0.6f, 0, 0.6f), true);
	PD::gs->addChild(rect1, 200);
	PD::om->rectangle->push_back(rect1);
	rect1->setVisible(false);
	rect2 = new MyRectangle(0, 0, PD::screen_width, PD::lengthH, ccc4f(0, 0.6f, 0, 0.6f), true);
	PD::gs->addChild(rect2, 200);
	PD::om->rectangle->push_back(rect2);
	rect2->setVisible(false);
}

bool HelpBar::onTouch(CCPoint touch_point, int touch_event){

	//this->touch_point = touch_point;

	if (pauseButton->onTouch(touch_point, touch_event)){
		if (PD::situation != PD::SITUATION_PAUSE){
			PD::setsituation(PD::SITUATION_PAUSE);
			pauseButton->sprite1->setTexture(PD::resm->resume);
		}
		else{
			PD::setsituation(PD::presituation);
			pauseButton->sprite1->setTexture(PD::resm->pause);
		}

		return true;
	}
	else if (hideButton->onTouch(touch_point, touch_event)){
		setShowBar(!showBar);
		return true;
	}
	else{

		bool find = false;

		for (int i = 0; i < 4; i++){
			if (productButton[i]->onTouch(touch_point, touch_event)){

				CCPoint true_point = MathMethod::convertTouchPointToTruePoint(touch_point);

				MyPoint location = MyPoint((int)(true_point.y / PD::lengthH),
					(int)(true_point.x / PD::lengthW));

				if (productButton[i]->type == HelpBarButton::PRODUCT_1){

					if (PD::status->money < Mine::price)
						return false;
					if (PD::om->map->map_data[location.i + 1][location.j + 1] == Map::EMPTY
						&&PD::om->map->map_data[location.i + 2][location.j + 1] == Map::EMPTY
						&&PD::om->map->map_data[location.i + 1][location.j + 2] == Map::EMPTY
						&&PD::om->map->map_data[location.i + 2][location.j + 2] == Map::EMPTY){

						if (PD::om->map->setupMineInMap(location.i + 1, location.j + 1)){
							PD::status->money -= Mine::price;

							PD::om->refreshStatus();

							PD::om->mine->push_back(new Mine(location.i, location.j));
							//PD::om->add(new Mine(location.i, location.j));
						}
					}
				}
				else{
					int type = productButton[i]->type - HelpBarButton::PRODUCT_2;
					if (PD::status->money < Tower::tower_price[type])
						return false;

					if (PD::om->map->map_data[location.i + 1][location.j + 1] == Map::EMPTY){
						//PD::om->map->map_data[location.i+1][location.j+1]=Map.OBSTRACLE;

						if (PD::om->map->setupTowerInMap(location.i + 1, location.j + 1)){
							PD::status->money -= Tower::tower_price[type];

							PD::om->refreshStatus();

							if (productButton[i]->type == HelpBarButton::PRODUCT_2)
								PD::om->tower->push_back(new Pillbox(location.i, location.j));
							else if (productButton[i]->type == HelpBarButton::PRODUCT_3)
								PD::om->tower->push_back(new Rocket(location.i, location.j));
							else if (productButton[i]->type == HelpBarButton::PRODUCT_4)
								PD::om->tower->push_back(new SmokeRocket(location.i, location.j));
							//PD::om->add(new Pillbox(location.i, location.j));
							//else if (btn.type == HelpBarButton.PRODUCT_3)
							//	PD::om->add(new Rocket(location.i, location.j));
						}
					}
				}
			}
			if (productButton[i]->ispress)
				find = true;
		}
		return find;
	}
	return false;
}

void HelpBar::setShowBar(bool showBar){
	this->showBar = showBar;

	bar->setVisible(showBar);

	if (showBar){
		hideButton->setXY(PD::lengthW * 4, PD::H * 100 - PD::lengthH);
		hideButton->sprite1->setRotation(0);
	}
	else{
		hideButton->setXY(PD::W * 100 - PD::lengthW, PD::H * 100 - PD::lengthH);
		hideButton->sprite1->setRotation(180);
	}


	for (int i = 0; i < 4; i++){
	//if (productButton[i]->onTouch(touch_point, touch_event)){
	//for (HelpBarButton btn : productButton){
		productButton[i]->setVisible(showBar);
	}
}



void HelpBar::setRect(MyPoint location, int type){
	if (type == HelpBarButton::PRODUCT_1) {

		rect1->setRectSize(PD::lengthW * 2, PD::lengthH * 100);
		rect1->setRectPosition(PD::lengthW*location.j, 0);
		
		rect2->setRectSize(PD::lengthW * 100, PD::lengthH * 2);
		rect2->setRectPosition(0, PD::lengthH*location.i);


		if (PD::om->map->map_data[location.i + 1][location.j + 1] == Map::EMPTY
			&& PD::om->map->map_data[location.i + 2][location.j + 1] == Map::EMPTY
			&& PD::om->map->map_data[location.i + 1][location.j + 2] == Map::EMPTY
			&& PD::om->map->map_data[location.i + 2][location.j + 2] == Map::EMPTY) {// &&

			rect1->setRectColor(ccc4f(0, 0.6f, 0, 0.6f));
			rect2->setRectColor(ccc4f(0, 0.6f, 0, 0.6f));
		}
		else{
			rect1->setRectColor(ccc4f(0.6f, 0, 0, 0.6f));
			rect2->setRectColor(ccc4f(0.6f, 0, 0, 0.6f));
		}
	}
	else{
		rect1->setRectSize(PD::lengthW, PD::lengthH * 100);
		rect1->setRectPosition(PD::lengthW*location.j, 0);


		rect2->setRectSize(PD::lengthW * 100, PD::lengthH);
		rect2->setRectPosition(0, PD::lengthH*location.i);

		if (PD::om->map->map_data[location.i + 1][location.j + 1] >= 2) {
			rect1->setRectColor(ccc4f(0.6f, 0, 0, 0.6f));
			rect2->setRectColor(ccc4f(0.6f, 0, 0, 0.6f));
		}
		else{
			rect1->setRectColor(ccc4f(0, 0.6f, 0, 0.6f));
			rect2->setRectColor(ccc4f(0, 0.6f, 0, 0.6f));
		}
	}
}


bool HelpBarButton::onTouch(CCPoint touch_point, int touch_event){


	if (ispress && type >= PRODUCT_1){
		if (touch_event == PD::TOUCH_MOVE){


			CCPoint true_point = MathMethod::convertTouchPointToTruePoint(touch_point);

			MyPoint location = MyPoint((int)(true_point.y / PD::lengthH),
				(int)(true_point.x / PD::lengthW));

			if (location != PD::om->helpBar->pre_point){

				PD::om->helpBar->pre_point = location.clone();

				PD::om->helpBar->setRect(location, type);

				if (type > PRODUCT_1)
					PD::om->attackfield->setPosition(location.i, location.j);
			}



		}

		else if (touch_event == PD::TOUCH_UP){



			//if (ispress){
			ispress = false;

			//if (type >= PRODUCT_1){
			PD::om->helpBar->setShowBar(true);
			if (type > PRODUCT_1){
				PD::om->attackfield->setVisible(false);
			}

			PD::om->helpBar->rect1->setVisible(false);
			PD::om->helpBar->rect2->setVisible(false);

			return true;

			//}
			//}
		}
	}


	if (visible){

		if (touch_event == PD::TOUCH_DOWN){
			if (r.containsPoint(touch_point))
			{
				ispress = true;


				

				if (type >= PRODUCT_1){
					PD::om->helpBar->setShowBar(false);

					CCPoint true_point = MathMethod::convertTouchPointToTruePoint(touch_point);

					MyPoint location = MyPoint((int)(true_point.y / PD::lengthH),
						(int)(true_point.x / PD::lengthW));
					PD::om->helpBar->setRect(location, type);
					PD::om->helpBar->rect1->setVisible(true);
					PD::om->helpBar->rect2->setVisible(true);
					if (type>PRODUCT_1){
						
						PD::om->attackfield->setField(Tower::tower_field[type - PRODUCT_2]);
						PD::om->attackfield->setPosition(location.i, location.j);
						PD::om->attackfield->setVisible(true);
					}
				}
			}
		}
		else if (touch_event == PD::TOUCH_UP){

			

			if (ispress){
				ispress = false;


				if (r.containsPoint(touch_point))
				{
					return true;
				}
			}
		}
	}


	

	return false;
}


