#include "Runner.h"
#include "ObjectManager.h"
#include "MathMethod.h"

//#include <typeinfo.h>

//const int Runner::POS_ID;
//const int Runner::DES_ID;

Runner::Runner(double pos_x, double pos_y){
	strcpy(class_name, "Enemy_Runner");
	this->x = pos_x;
	this->y = pos_y;

	

	speed = advice_speed;

	
	path = MathMethod::clonePath(PD::om->map->main_path);// ->(ArrayList<Point>)(PD.om.map.main_path.clone());
	path_tmp = NULL;

	//CCLog(typeid(this).name());
	

	sprite = new MySprite(PD::resm->advice, x, y, width, height, true);
	PD::gs->addChild(sprite, 1);
	PD::om->sprite->push_back(sprite);
	sprite->setVisible(visible);

	setNewDes();
}

Runner::Runner(double pos_x, double pos_y, bool child){
	this->x = pos_x;
	this->y = pos_y;

	width = PD::lengthW;
	height = PD::lengthH;

	speed = advice_speed;


	path = MathMethod::clonePath(PD::om->map->main_path);// ->(ArrayList<Point>)(PD.om.map.main_path.clone());
	path_tmp = NULL;

	//CCLog(typeid(this).name());


	setNewDes();
}


void Runner::setNewDes(){
	des_x = path->at(DES_ID).j*PD::lengthW;
	des_y = path->at(DES_ID).i*PD::lengthH;

	if (MathMethod::equal(des_x, x, speed)){
		if (des_y>y)
			direct = 2;
		else
			direct = 0;
	}
	else{
		if (des_x>x)
			direct = 1;
		else
			direct = 3;
	}

	//onChangeDirection();
}

void Runner::onChangeDirection(){
	switch (direct){
	case 0: sprite->setRotation(-90); break;
	case 1: sprite->setRotation(0); break;
	case 2: sprite->setRotation(90); break;
	case 3: sprite->setRotation(180); break;
	}
}

void Runner::moveToPath(){

	if (visible){
		
		
		des_x = path->at(DES_ID).j*PD::lengthW;
		des_y = path->at(DES_ID).i*PD::lengthH;



		//if (MathMethod::equal(des_x, x, speed) && MathMethod::equal(des_y, y, speed)){
		if (checkArrive(des_x, des_y)){
			x = des_x;
			y = des_y;
			
			if (path->at(DES_ID) == PD::om->map->des){
				//visible = false;
				//setVisible(false);
				arrive();
				return;
			}
			path->erase(path->begin() + POS_ID);
			setNewDes();
			onChangeDirection();
		}

		move();


		onSpriteMove();

	}
}

bool Runner::checkArrive(double des_x, double des_y){
	bool isArrive = false;
	switch (direct){
	case 0: if (y < des_y + speed / 2) isArrive = true; break;
	case 1: if (x > des_x - speed / 2) isArrive = true; break;
	case 2: if (y > des_y - speed / 2) isArrive = true; break;
	case 3: if (x < des_x + speed / 2) isArrive = true; break;
	}

	return isArrive;
}

void Runner::onSpriteMove(){
	sprite->setXY(x, y);
}

void Runner::logic(){
	moveToPath();
}

void Runner::setVisible(bool visible){
	this->visible = visible;
	sprite->setVisible(visible);
}

void Runner::release(){

	if (path != NULL){
		path->clear();
		delete path;
	}

	if (path_tmp != NULL){
		path_tmp->clear();
		delete path_tmp;
	}
	PD::gs->removeChild(sprite);
	delete sprite;
	delete this;
}

