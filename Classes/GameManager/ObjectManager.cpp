#include "ObjectManager.h"
#include "Runner.h"
#include "Tank.h"
#include "Flyer.h"
#include "Plane.h"
#include "SpriteManager.h"
#include "HelpBar.h"
#include "MathMethod.h"
#include "MyLabel.h"

//#define LOGIC(object) object*2


ObjectManager::ObjectManager(){
	
	helpBar = new HelpBar();
	map = new Map();
	wall = new vector<Wall*>();
	mine = new vector<Mine*>();
	tower = new vector<Tower*>();
	enemy = new vector<Enemy*>();
	bullet = new vector<Bullet*>();
	blast = new vector<Blast*>();

	sprite = new vector<MySprite*>();

	rectangle = new vector<MyRectangle*>();

	//timer = new Timer(1000);

	char blood[20];
	sprintf(blood, "blood:%d", PD::status->blood);
	label_blood = MyLabel::getLabel(blood, PD::W * 20, PD::H * 2, PD::H * 5, "Arial");
	PD::gs->addChild(label_blood, 1000);

	char money[20];
	sprintf(money, "$:%d", PD::status->money);
	label_money = MyLabel::getLabel(money, PD::W * 40, PD::H * 2, PD::H * 5, "Arial");
	PD::gs->addChild(label_money, 1000);


	
}

void ObjectManager::init(){
	initWall();
	map->initMainPath();
	attackfield = new Attackfield();

	mainTarget = new MainTarget();

	//enemy->push_back(new Runner(0, -PD::lengthH));
	//enemy->push_back(new Tank(0, -PD::lengthH, 0, 300));

	/*enemy->push_back(new Tank(0, -PD::lengthH, 0, 300));
	enemy->push_back(new Tank(0, -PD::lengthH*2, 0, 300));
	enemy->push_back(new Tank(0, -PD::lengthH*3, 0, 300));

	//enemy->push_back(new Flyer(1));

	//enemy->push_back(new Flyer(2));

	enemy->push_back(new Plane(1, Plane::type_airship, 500));
	enemy->push_back(new Plane(2, Plane::type_flysaucer, 500));*/

	//main_target = NULL;
}

void ObjectManager::initWall(){
	int i, j;
	for (i = 1; i<map->row - 1; i++)
	for (j = 1; j<map->col - 1; j++)
	if (PD::om->map->map_data[i][j] == 2){
		wall->push_back(new Wall(i - 1, j - 1, 0));
	}
	for (i = 1; i<map->row - 1; i++)
	for (j = 1; j<map->col - 1; j++)
	if (PD::om->map->map_data[i][j] == 3){
		PD::om->map->map_data[i][j] = 0;
		PD::om->map->map_data[i + 1][j] = 2;
		PD::om->map->map_data[i][j + 1] = 2;
		PD::om->map->map_data[i + 1][j + 1] = 2;
		PD::om->map->map_data[i + 1][j + 2] = 2;
		wall->push_back(new Wall(i - 1, j - 1, 3));
	}
	else if (PD::om->map->map_data[i][j] == 4){
		PD::om->map->map_data[i][j] = 2;
		PD::om->map->map_data[i + 1][j] = 2;
		PD::om->map->map_data[i + 1][j + 1] = 2;
		wall->push_back(new Wall(i - 1, j - 1, 2));
	}
	else if (PD::om->map->map_data[i][j] == 5){
		PD::om->map->map_data[i][j] = 2;
		PD::om->map->map_data[i + 1][j] = 2;
		PD::om->map->map_data[i][j + 1] = 2;
		PD::om->map->map_data[i + 1][j + 1] = 2;
		PD::om->map->map_data[i][j + 2] = 2;
		PD::om->map->map_data[i + 1][j + 2] = 2;
		PD::om->map->map_data[i][j + 3] = 2;
		PD::om->map->map_data[i + 1][j + 3] = 2;
		wall->push_back(new Wall(i - 2, j - 1, 1));
	}
}

/*void ObjectManager::add(CCObject obj){
	if (obj instanceof Mine){
		mine->add((Mine)obj);
	}
}*/

void ObjectManager::show(){
	helpBar->show();
	map->showBackground();
	for (int i = 0; i < wall->size(); i++)
		wall->at(i)->show();
}

bool ObjectManager::onTouch(CCPoint touch_point, int touch_event){

	if (PD::situation == PD::SITUATION_STARTING ||
		PD::situation == PD::SITUATION_PAUSE ||
		PD::situation == PD::SITUATION_WAITREADY){
		if (helpBar->onTouch(touch_point, touch_event))
			return true;

		touch_point = MathMethod::convertTouchPointToTruePoint(touch_point);

		for (int i = 0; i < enemy->size(); i++)
			enemy->at(i)->onTouch(touch_point, touch_event);

		for (int i = 0; i < tower->size(); i++)
			tower->at(i)->onTouch(touch_point, touch_event);

	}
	return false;
}

void ObjectManager::logic(){
	
	attackfield->logic();
	mainTarget->logic();

	if (PD::situation == PD::SITUATION_STARTING){

		for (int i = 0; i < mine->size(); i++)
		if (mine->at(i)->visible)
			mine->at(i)->run();


		for (int i = 0; i < tower->size(); i++)
		if (tower->at(i)->visible)
			tower->at(i)->shoot();

		

		/*for (int i = 0; i < bullet->size(); i++)
		if (bullet->at(i)->visible)
			bullet->at(i)->gooff();*/


		for (int i = bullet->size() - 1; i >= 0; i--){
			if (bullet->at(i)->visible)
				bullet->at(i)->gooff();
			else{
				bullet->at(i)->release();
				bullet->at(i) = NULL;
				bullet->erase(bullet->begin() + i);
			}
		}

		for (int i = blast->size() - 1; i >= 0; i--){
			if (blast->at(i)->visible)
				blast->at(i)->play();
			else{
				blast->at(i)->release();
				blast->at(i) = NULL;
				blast->erase(blast->begin() + i);
			}
		}


		/*if (timer->runLoop()){
			enemy->push_back(new Tank(0, -PD::lengthH, (int)(CCRANDOM_0_1() * 4), 300));

			enemy->push_back(new Plane((int)(CCRANDOM_0_1() * 2) + 1, (int)(CCRANDOM_0_1() * 2), 500));
		}*/

	}


	if (PD::situation == PD::SITUATION_STARTING ||
		PD::situation == PD::SITUATION_WAITREADY){

		for (int i = 0; i < enemy->size(); i++)
		if (enemy->at(i)->visible)
			enemy->at(i)->logic();
	}

	/*for (int i = tower->size() - 1; i >= 0; i--){
		if (tower->at(i)->visible)
			tower->at(i)->shoot();
		else{
			tower->at(i)->release();
			tower->at(i) = NULL;
			tower->erase(tower->begin() + i);
		}
	}

	for (int i = enemy->size() - 1; i >= 0; i--){
		if (enemy->at(i)->visible)
			enemy->at(i)->logic();
		else{
			enemy->at(i)->release();
			enemy->at(i) = NULL;
			enemy->erase(enemy->begin() + i);
		}
	}


	for (int i = bullet->size() - 1; i >= 0; i--){
		if (bullet->at(i)->visible)
			bullet->at(i)->logic();
		else{
			bullet->at(i)->release();
			bullet->at(i) = NULL;
			bullet->erase(bullet->begin() + i);
		}
	}*/

	
}


void ObjectManager::refreshStatus(){
	char str[50];
	sprintf(str, "$:%d", PD::status->money);
	label_money->setString(str);
	sprintf(str, "blood:%d", PD::status->blood);
	label_blood->setString(str);
}


void ObjectManager::refreshView(){
	for (int i = 0; i < sprite->size(); i++)
	if (sprite->at(i) != NULL)
		sprite->at(i)->refresh();

	for (int i = 0; i < rectangle->size(); i++)
	if (rectangle->at(i) != NULL)
		rectangle->at(i)->refresh();
}