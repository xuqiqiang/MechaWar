#include "Tower.h"
#include "MathMethod.h"
#include "ObjectManager.h"
#include "Runner.h"
#include "Plane.h"


double Tower::tower_field[Tower::TYPE_SUM];
double Tower::tower_destory[Tower::TYPE_SUM];

int Tower::tower_price[Tower::TYPE_SUM];

Tower::Tower(int i, int j){
	this->i = i;
	this->j = j;
	grade = 0;
	

	this->x = j*PD::lengthW - PD::lengthW*0.05*(grade - 1);
	this->y = i*PD::lengthH - (double)((MathMethod::height_div_width(PD::resm->gun1) - 1)*PD::lengthH / 2) - MathMethod::height_div_width(PD::resm->gun1) * PD::lengthH*0.05*(grade - 1);
	w = PD::lengthW*(1 + 0.1*(grade - 1));
	h = MathMethod::getHeight(PD::resm->gun1, PD::lengthH)*(1 + 0.1*(grade - 1));// bmpheight / bmpwidth*PD::lengthH*(1 + 0.1*(grade - 1));
	

	/*r = MyRect(j*PD::lengthW - PD::lengthW*0.05*(grade - 1),
		i*PD::lengthH - (double)((bmpheight / bmpwidth - 1)*PD::lengthH / 2) - bmpheight / bmpwidth*PD::lengthH*0.05*(grade - 1),
		PD::lengthW*(1 + 0.1*(grade - 1)),
		MathMethod::getHeight(PD::resm->gun1, PD::lengthH)*(1 + 0.1*(grade - 1)));*/
	ispress = false;
	visible = true;

	angle_changed = false;
	target = NULL;


	/*sprite_honor = new MySprite(PD::resm->honor, true);
	PD::gs->addChild(sprite_honor, 1);
	PD::om->sprite->push_back(sprite_honor);
	sprite_honor->setVisible(false);*/
}


void Tower::onTouch(CCPoint touch_point, int touch_event){
	if (touch_event == PD::TOUCH_DOWN){
		if (MathMethod::pointInRect(touch_point, x, y, w, h)){
			ispress = true;
		}
	}
	else if (touch_event == PD::TOUCH_UP){
		if (ispress){
			ispress = false;
			if (MathMethod::pointInRect(touch_point, x, y, w, h)){
				if (!PD::om->attackfield->getVisible() ||
					PD::om->attackfield->tower != this){
					

					PD::om->attackfield->setField(field);
					PD::om->attackfield->setPosition(i, j);
					PD::om->attackfield->setTower(this);
					PD::om->attackfield->setVisible(true);

				}
				else if (PD::om->attackfield->getVisible() &&
					PD::om->attackfield->tower == this){

					PD::om->attackfield->setVisible(false);
					PD::om->attackfield->setTower(NULL);

					if (grade < grade_max){
						if (PD::status->money < update_price){
							//CCMessageBox("金钱不够!", "提示信息");
							CCMessageBox("Not enough money!", "Information");
						}
						else{
							
							PD::status->money -= update_price;
							PD::om->refreshStatus();

							promote();
						}
					}
				}

				return;
				
			}
		}

		if (PD::om->attackfield->getVisible() &&
			PD::om->attackfield->tower == this){
			PD::om->attackfield->setVisible(false);
			PD::om->attackfield->setTower(NULL);
		}
	}
}


bool Tower::checkMainTarget(){
	Enemy *main_target = PD::om->mainTarget->target;
	if (main_target != NULL&&
		MathMethod::stringStartWith(main_target->class_name, "Enemy_Runner") &&
		target != main_target){
		if (MathMethod::isInField(j*PD::lengthW,
			i*PD::lengthH,
			main_target->x,
			main_target->y,
			field)){
			target = main_target;
			return true;
		}
	}

	return false;
}

bool Tower::findTarget(){

	/*Enemy *main_target = PD::om->mainTarget->target;
	if (main_target != NULL&&
		MathMethod::stringStartWith(main_target->class_name, "Enemy_Runner")){
		if (MathMethod::isInField(j*PD::lengthW,
			i*PD::lengthH,
			main_target->x,
			main_target->y,
			field)){
			target = main_target;
			return true;
		}
	}*/

	int id;


	for (id = 0; id<PD::om->enemy->size(); id++){
		if (PD::om->enemy->at(id)!=NULL && 
			PD::om->enemy->at(id)->visible &&
			MathMethod::stringStartWith(PD::om->enemy->at(id)->class_name, "Enemy_Runner")){
			Runner *r = (Runner *)PD::om->enemy->at(id);
			if (MathMethod::stringStartWith(r->class_name, "Enemy_Runner_Tank")){
				
				if (MathMethod::isInField(j*PD::lengthW,
					i*PD::lengthH,
					r->x,
					r->y,
					field)){
					target = PD::om->enemy->at(id);
					return true;
				}
			}
		}
	}

	target = NULL;


	return false;
}


bool Tower::isTargetFar(){
	if (!target->visible)
		return true;


	double enemy_x = target->x;
	double enemy_y = target->y;
	if (MathMethod::stringStartWith(target->class_name, "Enemy_Flyer_Plane")){
		enemy_x = ((Plane*)target)->real_x;
		enemy_y = ((Plane*)target)->real_y;
	}

	return (!MathMethod::isInField(j*PD::lengthW,
		i*PD::lengthH,
		enemy_x,
		enemy_y,
		field));
}

void Tower::shoot(){
	if (visible){

		checkMainTarget();

		if (target == NULL || isTargetFar()){
			findTarget();
		}
		if (target != NULL){
			
			double new_angle = MathMethod::getAngle(j*PD::lengthW,
				i*PD::lengthH,
				target->x,
				target->y);
			if (new_angle != angle){
				angle = new_angle;
				angle_changed = true;
			}


		}
	}
}

void Tower::promote(){
	
	field *= 1.3;
	destoy = destoy*1.3;

	sprite_honor[grade] = new MySprite(PD::resm->honor,
		(1 + j)*PD::lengthW - PD::lengthW*0.2,
		(1 + i)*PD::lengthH - PD::lengthH*0.2 + grade*PD::lengthH*0.09,// + (MathMethod::height_div_width(PD::resm->honor) - 1)*PD::lengthH*0.1*(grade - 2),
		PD::lengthW*0.2,
		MathMethod::getHeight(PD::resm->honor, PD::lengthW*0.2), true);
	PD::gs->addChild(sprite_honor[grade], 1);
	PD::om->sprite->push_back(sprite_honor[grade]);
	sprite_honor[grade]->setVisible(visible);
	grade++;

	update_price = (grade + 1)*price;
}

void Tower::destroyed(){
	PD::om->blast->push_back(new Blast(j*PD::lengthW - PD::lengthW*0.15, i*PD::lengthH - PD::lengthH*0.15, PD::lengthX*1.3, 1, 2));
	setVisible(false);
	PD::om->map->map_data[i + 1][j + 1] = 0;

	PD::om->map->need_refind_path = true;
}

void Tower::setVisible(bool visible){
	this->visible = visible;
	for (int i = 0; i < grade; i++){
		sprite_honor[i]->setVisible(visible);
	}
}

void Tower::release(){
	for (int i = 0; i < grade; i++){
		MathMethod::releaseSprite(sprite_honor[i]);
	}
}