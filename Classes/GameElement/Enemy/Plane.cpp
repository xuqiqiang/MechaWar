#include "Plane.h"
#include "MathMethod.h"
#include "ObjectManager.h"
#include "Blast.h"

int Plane::direct_frame[4];
double Plane::plane_speed[type_sum];

double Plane::altitude_min;
double Plane::altitude_max;
double Plane::altitude_speed;

Plane::Plane(int direct, int type, int blood) : Flyer(direct, true){

	strcpy(class_name, "Enemy_Flyer_Plane");
	if (direct == 1){
		real_x = -(CCRANDOM_0_1() * 3 + 2) * PD::lengthW;
		real_y = ((int)(CCRANDOM_0_1() * 6) + 3)*PD::lengthH;
	}
	else if (direct == 2){
		real_x = ((int)(CCRANDOM_0_1() * 9) + 3)*PD::lengthW;
		real_y = -(CCRANDOM_0_1() * 3 + 2)*PD::lengthH;
	}

	altitude = 3 * PD::lengthH;

	x = real_x;
	y = real_y - altitude;


	this->type = type;
	this->blood = blood;
	blood_max = blood;
	speed = plane_speed[type];
	speed_max = speed;

	frame = 0;
	
	frame_sum = 1;

	
	if (type == type_airship) {

		sprite = new MySprite(PD::resm->plane[type][direct], true);

		switch (direct) {
		case 0:
			sprite->setSize(MathMethod::width_div_height(PD::resm->plane[type][direct]) * PD::lengthX, PD::lengthX);
			break;
		case 1:
			sprite->setSize(PD::lengthX * 3, MathMethod::height_div_width(PD::resm->plane[type][direct]) * PD::lengthX * 3);
			break;
		case 2:
			sprite->setSize(PD::lengthX * 2, MathMethod::height_div_width(PD::resm->plane[type][direct]) * PD::lengthX * 2);
			break;
		case 3:
			sprite->setSize(MathMethod::width_div_height(PD::resm->plane[type][direct]) * PD::lengthX * 3 / 4, PD::lengthX * 3 / 4);
			break;
		}
	}
	else if (type == type_flysaucer) {

		sprite = new MySprite(PD::resm->plane[type][direct], true);

		frame_sum = 6;
		sprite->setSize(MathMethod::width_div_height(PD::resm->plane[type][frame]) * PD::lengthX, PD::lengthX);
	}
	else{

		if (type == type_helicopter){
			frame_sum = 6;
		}

		sprite = new MySprite(PD::resm->new_plane[type - new_plane_id], frame_sum * direct_frame[direct], frame_sum * 4, true);

		sprite->setSize(MathMethod::width_div_height(PD::resm->new_plane[type - new_plane_id]) / (frame_sum * 4) * PD::lengthX, PD::lengthX);
	}


	PD::gs->addChild(sprite, 10);
	PD::om->sprite->push_back(sprite);
	sprite->setVisible(visible);




	if (type == type_airship) {

		sprite_shadow = new MySprite(PD::resm->plane_shadow[type][direct], true);

		switch (direct) {
		case 0:
			sprite_shadow->setSize(MathMethod::width_div_height(PD::resm->plane_shadow[type][direct]) * PD::lengthX, PD::lengthX);
			break;
		case 1:
			sprite_shadow->setSize(PD::lengthX * 3, MathMethod::height_div_width(PD::resm->plane_shadow[type][direct]) * PD::lengthX * 3);
			break;
		case 2:
			sprite_shadow->setSize(PD::lengthX * 2, MathMethod::height_div_width(PD::resm->plane_shadow[type][direct]) * PD::lengthX * 2);
			break;
		case 3:
			sprite_shadow->setSize(MathMethod::width_div_height(PD::resm->plane_shadow[type][direct]) * PD::lengthX * 3 / 4, PD::lengthX * 3 / 4);
			break;
		}
	}
	else if (type == type_flysaucer) {
		sprite_shadow = new MySprite(PD::resm->plane_shadow[type][0], true);
		sprite_shadow->setSize(MathMethod::width_div_height(PD::resm->plane_shadow[type][0]) * PD::lengthX, PD::lengthX);
	}
	else{

		sprite_shadow = new MySprite(PD::resm->new_plane_shadow[type - new_plane_id], frame_sum * direct_frame[direct], frame_sum * 4, true);
		sprite_shadow->setSize(MathMethod::width_div_height(PD::resm->new_plane_shadow[type - new_plane_id]) / (frame_sum * 4) * PD::lengthX, PD::lengthX);
	}

	sprite_shadow->setOpacity(100);

	PD::gs->addChild(sprite_shadow, 9);
	PD::om->sprite->push_back(sprite_shadow);
	sprite_shadow->setVisible(visible);


	sprite_blood = new MyRectangle(x - PD::lengthW*0.1, y - PD::lengthH*0.08,
		(PD::lengthW*0.7 - 2)*blood / blood_max, PD::lengthH*0.16 - 2, ccc4f(0.7, 0, 0, 0.7), true);
	PD::gs->addChild(sprite_blood, 11);
	PD::om->rectangle->push_back(sprite_blood);
	sprite_blood->setVisible(visible);

	onMoveSprite();

}

void Plane::logic(){
	Flyer::logic();
	if (visible){

		if (type == type_flysaucer ||
			type == type_helicopter) {
			frame = (frame + 1) % frame_sum;
		}

	}
}

void Plane::onMoveSprite(){
	if (type == type_airship) {
		switch (direct) {
		case 0:
			sprite->setXY(x - (MathMethod::width_div_height(PD::resm->plane[type][direct]) - 1)
				* PD::lengthW / 2, y);

			sprite_shadow->setXY(real_x - (MathMethod::width_div_height(PD::resm->plane_shadow[type][direct]) - 1)
				* PD::lengthW / 2, real_y);
			break;
		case 1:
			sprite->setXY(x - PD::lengthW * 1.3 + PD::W * 1, y);
			sprite_shadow->setXY(real_x - PD::lengthW, real_y);
			break;
		case 2:
			sprite->setXY(x - PD::lengthW * 0.75 + PD::W * 1, y
				- (MathMethod::width_div_height(PD::resm->plane[type][direct]) * 2 + 0.4) * PD::lengthH / 2);
			sprite_shadow->setXY(real_x - PD::lengthW / 2, real_y
				- (MathMethod::width_div_height(PD::resm->plane_shadow[type][direct]) * 2 + 0.4) * PD::lengthH / 2);
			break;
		case 3:
			sprite->setXY(x - (MathMethod::width_div_height(PD::resm->plane[type][direct]) - 1)
				* PD::lengthW * 3 / 8, y + PD::lengthH * 1 / 8);
			sprite_shadow->setXY(real_x - (MathMethod::width_div_height(PD::resm->plane_shadow[type][direct]) - 1)
				* PD::lengthW * 3 / 8, real_y + PD::lengthH * 1 / 8);
			break;
		}
	}
	else if (type == type_flysaucer) {
		sprite->setTexture(PD::resm->plane[type][frame]);
		sprite->setXY(x - ((MathMethod::width_div_height(PD::resm->plane[type][frame]) - 0.5) * PD::lengthW) / 2 + PD::W * 1, y);

		sprite_shadow->setXY(real_x - ((MathMethod::width_div_height(PD::resm->plane_shadow[type][0]) - 1) * PD::lengthW) / 2, real_y);
	}
	else{
		if (type == type_helicopter){
			sprite->setFrame(frame + frame_sum * direct_frame[direct]);
			sprite_shadow->setFrame(frame + frame_sum * direct_frame[direct]);
		}
		//frame_sum * direct_frame[direct]
		//sprite->setXY(x - ((MathMethod::width_div_height(PD::resm->plane[type][frame]) - 0.5) * PD::lengthW) / 2 + PD::W * 1, y);
		sprite->setXY(x - (MathMethod::getWidth(PD::resm->new_plane[type - new_plane_id], height) / (frame_sum * 4) - height) / 2, y);
		sprite_shadow->setXY(real_x - (MathMethod::getWidth(PD::resm->new_plane_shadow[type - new_plane_id], height) / (frame_sum * 4) - height) / 2, real_y);
	}

	//sprite_blood->setRectPosition(x + PD::lengthW*0.2 + 1, y - PD::lengthH*0.08 + 1);
	sprite_blood->setRectPosition(x - PD::W * 0.1, y);
}


void Plane::setVisible(bool visible){
	this->visible = visible;
	sprite->setVisible(visible);
	sprite_shadow->setVisible(visible);
	sprite_blood->setVisible(visible);
}

void Plane::move(){
	//Enemy::move();
	switch (direct){
	case 0:real_y -= speed; break;
	case 1:real_x += speed; break;
	case 2:real_y += speed; break;
	case 3:real_x -= speed; break;
	}



	if (direct == 1){
		if (real_x > PD::lengthW&&real_x<PD::lengthW*(PD::om->map->des.j - 1))
		if (PD::om->map->map_data[(int)(real_y / PD::lengthH) + 1][(int)(real_x / PD::lengthW)] == Map::EMPTY &&
			PD::om->map->map_data[(int)(real_y / PD::lengthH) + 1][(int)(real_x / PD::lengthW) + 1] == Map::EMPTY &&
			PD::om->map->map_data[(int)(real_y / PD::lengthH) + 1][(int)(real_x / PD::lengthW) + 2] == Map::EMPTY){
			if (altitude>altitude_min){
				altitude -= altitude_speed;
			}
		}
		else{
			if (altitude<altitude_max){
				altitude += altitude_speed;
			}
		}
	}
	else if (direct == 2){
		if (real_y>PD::lengthH&&real_y<PD::lengthH*(PD::om->map->des.i - 1))
		if (PD::om->map->map_data[(int)(real_y / PD::lengthH)][(int)(real_x / PD::lengthW) + 1] == Map::EMPTY &&
			PD::om->map->map_data[(int)(real_y / PD::lengthH) + 1][(int)(real_x / PD::lengthW) + 1] == Map::EMPTY &&
			PD::om->map->map_data[(int)(real_y / PD::lengthH) + 2][(int)(real_x / PD::lengthW) + 1] == Map::EMPTY){
			if (altitude>altitude_min){
				altitude -= altitude_speed;
			}
		}
		else{
			if (altitude < altitude_max){
				altitude += altitude_speed;
			}
		}
	}


	x = real_x;
	y = real_y - altitude;

}


void Plane::attacted(double destoy){
	Flyer::attacted(destoy);
	if (blood <= 0){
		//PD::om->blast->push_back(new Blast(x - PD::lengthW*0.15, y - PD::lengthH*0.15, PD::lengthX*1.3, 1, 11));
		if (type == type_airship){
			if (direct == 1){
				PD::om->blast->push_back(new Blast(x - PD::lengthW * 2 / 3, y, PD::lengthX, 1, 12));
				PD::om->blast->push_back(new Blast(x - PD::lengthW * 0.5, y - PD::lengthH*0.5, PD::lengthX * 2, 1, 11));
				PD::om->blast->push_back(new Blast(x + PD::lengthW * 2 / 3, y, PD::lengthX, 1, 12));
			}
			else if (direct == 2){
				PD::om->blast->push_back(new Blast(x, y - PD::lengthH * 2 / 3, PD::lengthX, 1, 12));
				PD::om->blast->push_back(new Blast(x - PD::lengthW * 0.5, y - PD::lengthH*0.5, PD::lengthX * 2, 1, 11));
				PD::om->blast->push_back(new Blast(x, y + PD::lengthH * 2 / 3, PD::lengthX, 1, 12));
			}
		}
		else{
			PD::om->blast->push_back(new Blast(x - PD::lengthW * 2 / 3 + PD::lengthW*0.15, y + PD::lengthH*0.15, PD::lengthX * 0.7, 1, 12));
			PD::om->blast->push_back(new Blast(x - PD::lengthW * 0.25, y - PD::lengthH*0.25, PD::lengthX * 1.5, 1, 11));
			PD::om->blast->push_back(new Blast(x + PD::lengthW * 2 / 3 + PD::lengthW*0.15, y + PD::lengthH*0.15, PD::lengthX * 0.7, 1, 12));
		}
	}

	sprite_blood->setRectSize((PD::lengthW*0.7 - 2)*blood / blood_max, PD::lengthH*0.16 - 2);
}

void Plane::release(){

	MathMethod::releaseSprite(sprite);
	MathMethod::releaseRectangle(sprite_blood);

	delete this;
}