#include "Rocket.h"
#include "MathMethod.h"
#include "ObjectManager.h"
#include "Flyer.h"
#include "Tower.h"
#include "Plane.h"

Rocket::Rocket(int i, int j) : Tower(i, j){
	destoy = tower_destory[ROCKET];//d;
	field = tower_field[ROCKET];//f;
	price = tower_price[ROCKET];//f;

	update_price = price;


	sprite_bottom = new MySprite(PD::resm->gun1, j*PD::lengthW - PD::lengthW*0.05*grade,
		i*PD::lengthH - (double)((MathMethod::height_div_width(PD::resm->gun1) - 1)*PD::lengthH / 2) - MathMethod::height_div_width(PD::resm->gun1)*PD::lengthH*0.05*grade,
		PD::lengthW*(1 + 0.1*grade),
		MathMethod::height_div_width(PD::resm->gun1)*PD::lengthH*(1 + 0.1*grade), true);
	PD::gs->addChild(sprite_bottom, 1);
	PD::om->sprite->push_back(sprite_bottom);
	sprite_bottom->setVisible(visible);


	angle = -60;
	sprite_top = new MySprite(PD::resm->gun_tower,
		//4,
		MathMethod::angle2TowerId(angle),
		//(int)((int)((540 - MathMethod::amendTowerAngle(angle)) + 11.125 / 2) % 356 / 11.125) + 1,
		j * PD::lengthW - PD::lengthW*0.05*(grade)-PD::lengthW*0.03,
		i*PD::lengthH - PD::lengthH*0.05*(grade)-PD::lengthH*0.03,
		PD::lengthW*(1 + 0.1*(grade)),
		PD::lengthH*(1 + 0.1*(grade)), true);
	PD::gs->addChild(sprite_top, 1);
	PD::om->sprite->push_back(sprite_top);
	sprite_top->setVisible(visible);


	timer = new Timer(shoot_time);
	
	timer_extra = new Timer(shoot_time_extra);

	timer_extra->setEnable(false);

	/*for (double a = -179; a <= 180; a += 45){
		PD::om->bullet->push_back(new Bullet(i, j, a, destoy, target));
	}

	PD::om->bullet->push_back(new Bullet(i, j, -180, destoy, target));
	PD::om->bullet->push_back(new Bullet(i, j, -90, destoy, target));
	PD::om->bullet->push_back(new Bullet(i, j, 0, destoy, target));
	PD::om->bullet->push_back(new Bullet(i, j, 90, destoy, target));*/
}



Rocket::Rocket(int i, int j, bool child) : Tower(i, j){
	
	timer = new Timer(shoot_time);

	timer_extra = new Timer(shoot_time_extra);

	timer_extra->setEnable(false);
}


bool Rocket::checkMainTarget(){
	

	Enemy *main_target = PD::om->mainTarget->target;
	if (main_target != NULL &&
		target != main_target){
		double enemy_x = -1000;
		double enemy_y = -1000;
		if (MathMethod::stringStartWith(main_target->class_name, "Enemy_Flyer")){
			enemy_x = ((Plane*)main_target)->real_x;
			enemy_y = ((Plane*)main_target)->real_y;
		}
		else if (MathMethod::stringStartWith(main_target->class_name, "Enemy_Runner")){
			enemy_x = main_target->x;
			enemy_y = main_target->y;
		}

		if (MathMethod::isInField(j*PD::lengthW, i*PD::lengthH, enemy_x, enemy_y, field)){
			target = main_target;
			return true;
		}
	}

	return false;
}


bool Rocket::findTarget(){

	/*Enemy *main_target = PD::om->mainTarget->target;
	if (main_target != NULL){
		double enemy_x = -1000;
		double enemy_y = -1000;
		if (MathMethod::stringStartWith(main_target->class_name, "Enemy_Flyer")){
			enemy_x = ((Plane*)main_target)->real_x;
			enemy_y = ((Plane*)main_target)->real_y;
		}
		else if (MathMethod::stringStartWith(main_target->class_name, "Enemy_Runner")){
			enemy_x = main_target->x;
			enemy_y = main_target->y;
		}

		if (MathMethod::isInField(j*PD::lengthW, i*PD::lengthH, enemy_x, enemy_y, field)){
			target = main_target;
			return true;
		}
	}*/

	int id;

	for (id = 0; id<PD::om->enemy->size(); id++){
		if (PD::om->enemy->at(id) != NULL &&
			PD::om->enemy->at(id)->visible){

			double enemy_x = -1000;
			double enemy_y = -1000;
			if (MathMethod::stringStartWith(PD::om->enemy->at(id)->class_name, "Enemy_Flyer_Plane")){
				enemy_x = ((Plane*)PD::om->enemy->at(id))->real_x;
				enemy_y = ((Plane*)PD::om->enemy->at(id))->real_y;
			}
			else if (MathMethod::stringStartWith(PD::om->enemy->at(id)->class_name, "Enemy_Runner_Tank")){
				enemy_x = PD::om->enemy->at(id)->x;
				enemy_y = PD::om->enemy->at(id)->y;
			}

			if (MathMethod::isInField(j*PD::lengthW, i*PD::lengthH, enemy_x, enemy_y, field)){
				target = PD::om->enemy->at(id);
				return true;
			}

		}
	}


	target = NULL;

	return false;
}


void Rocket::shoot(){
	Tower::shoot();
	if (visible){

		timer->run();

		if (grade == grade_max){
			timer_extra->run();
		}

		if (target != NULL){

			if (angle_changed){
				angle_changed = false;
				changeAngle();
			}

			if (timer->complete()){
				timer->setTime();
				fireBullet();
				
				
				if (grade == grade_max){
					timer_extra->setEnable(true);
					timer_extra->setTime();
				}
			}


			if (grade == grade_max){
				if (timer_extra->complete()){
					timer_extra->setEnable(false);
					fireBullet();
				}
			}
		}
	}
}


void Rocket::changeAngle(){
	sprite_top->setFrame(MathMethod::angle2TowerId(angle));
}


void Rocket::fireBullet(){
	PD::om->bullet->push_back(new Bullet(i, j, angle, destoy, Bullet::TYPE_RED, target));
}

void Rocket::promote(){
	Tower::promote();


	sprite_bottom->setStatus(j*PD::lengthW - PD::lengthW*0.05*(grade - 1),
		i*PD::lengthH - (double)((MathMethod::height_div_width(PD::resm->gun1) - 1)*PD::lengthH / 2) - MathMethod::height_div_width(PD::resm->gun1)*PD::lengthH*0.05*(grade - 1),
		PD::lengthW*(1 + 0.1*(grade - 1)),
		MathMethod::height_div_width(PD::resm->gun1)*PD::lengthH*(1 + 0.1*(grade - 1)));
	

	sprite_top->setStatus(j * PD::lengthW - PD::lengthW*0.05*(grade)-PD::lengthW*0.03,
		i*PD::lengthH - PD::lengthH*0.05*(grade)-PD::lengthH*0.03,
		PD::lengthW*(1 + 0.1*(grade)),
		PD::lengthH*(1 + 0.1*(grade)));

}

void Rocket::setVisible(bool visible){
	Tower::setVisible(visible);
	sprite_top->setVisible(visible);
	sprite_bottom->setVisible(visible);
}

void Rocket::release(){
	Tower::release();

	MathMethod::releaseSprite(sprite_top);
	MathMethod::releaseSprite(sprite_bottom);
	delete timer;
	delete this;
}