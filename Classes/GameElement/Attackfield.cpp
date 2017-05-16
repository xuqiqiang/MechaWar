#include "Attackfield.h"
#include "Tower.h"
#include "ObjectManager.h"
#include "MyLabel.h"

const double Attackfield::rotate_speed = 1.4;

Attackfield::Attackfield(){
	angle = 0;
	visible = false;
	tower = NULL;

	sprite = new MySprite(PD::resm->range, true);
	PD::gs->addChild(sprite, 300);
	PD::om->sprite->push_back(sprite);
	sprite->setVisible(visible);

	sprite_button = new MySprite(PD::resm->promote, true);
	PD::gs->addChild(sprite_button, 301);
	PD::om->sprite->push_back(sprite_button);
	sprite_button->setVisible(visible);

	label_money = MyLabel::getLabel(PD::H * 3, "Arial");
	PD::gs->addChild(label_money, 301);
	label_money->setVisible(visible);
	
}

/*Attackfield::Attackfield(double field){
	this->field = field;
	angle = 0;
	visible = true;
}*/

void Attackfield::setPosition(int i, int j){
	this->i = i;
	this->j = j;
	x = PD::lengthW * j + PD::lengthW / 2 - field;
	y = PD::lengthH * i + PD::lengthH / 2 - field;
	//SpriteManager::setPosition(sprite,ccp(x,y));
	sprite->setXY(x, y);
}

void Attackfield::setField(double field){
	this->field = field;
	//SpriteManager::setSize(sprite, field * 2, field * 2);
	sprite->setSize(field * 2, field * 2);
}

void Attackfield::setVisible(bool visible){
	this->visible = visible;
	sprite->setVisible(visible);

	if (tower != NULL&&tower->grade<tower->grade_max){
		sprite_button->setVisible(visible);
		label_money->setVisible(visible);
		//CCLog("sprite_button");
	}
	angle = 0;
}

void Attackfield::setTower(Tower *tower){
	this->tower = tower;

	if (tower != NULL&&tower->grade<tower->grade_max){
		sprite_button->setSize(PD::lengthW, PD::lengthH);
		sprite_button->setXY(j*PD::lengthW, i*PD::lengthH);
		

		char str[20];
		sprintf(str, "$:%d", tower->update_price);
		label_money->setString(str);
		MyLabel::setXY(label_money, j*PD::lengthW + PD::lengthW*0.8, i*PD::lengthH + PD::lengthH);
		
	}
}


bool Attackfield::getVisible(){
	return visible;
}

/*void Attackfield::show(){
	sprite = SpriteManager::newSprite(PD::resm->range, x, y, field * 2, field * 2);
	PD::gs->addChild(sprite, 300);
}*/

void Attackfield::logic(){
	if (visible){
		angle += rotate_speed;
		//SpriteManager::setRotation(sprite, angle);
		sprite->setRotation(angle);
	}
}