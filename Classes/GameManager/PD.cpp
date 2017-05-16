#include "PD.h"
#include "RoundManager.h"
#include "ObjectManager.h"
#include "Tower.h"
#include "Enemy.h"
#include "Plane.h"
#include "Tank.h"
#include "Bullet.h"
#include "Blast.h"
#include "MainTarget.h"

double PD::OX, PD::OY;
double PD::W, PD::H;
int PD::screen_width, PD::screen_height;

int PD::situation, PD::presituation;

int PD::round;

RoundManager* PD::rm;
ProgressMananger* PD::pm;
ObjectManager* PD::om;
//GameManager* PD::gm;
ResourceManager* PD::resm;
CameraManager* PD::cm;
GameScene* PD::gs;

Status* PD::status;

double PD::lengthX;
double PD::lengthW;
double PD::lengthH;

double PD::delay;

void PD::init(CCSize visibleSize, CCPoint origin)
{
	OX = origin.x;
	OY = origin.y;
	screen_width = visibleSize.width - OX * 2;
	screen_height = visibleSize.height - OY * 2;
	W = screen_width / 100.0;
	H = screen_height / 100.0;
	rm = new RoundManager();
	resm = new ResourceManager();

	lengthH = H * 10;
	lengthW = W*6.25;
	lengthX = lengthH;

	delay = 30;// 0.03f;


	cc_timeval psv;
	CCTime::gettimeofdayCocos2d(&psv, NULL);    // 计算时间种子   
	unsigned int tsrans = psv.tv_sec * 1000 + psv.tv_usec / 1000;    // 初始化随机数
	srand(tsrans);


	cm = new CameraManager();

	Tower::initData();
	Enemy::initData();
	Plane::initData();
	Tank::initData();
	Bullet::initData();
	Blast::initData();
	MainTarget::initData();
}

void PD::initGame(GameScene *gameScene){

	

	gs = gameScene;

	status = new Status();

	om = new ObjectManager();
	om->init();
	om->show();
	//gm = new GameManager(0);
	pm = new ProgressMananger(round);

	
	situation = SITUATION_STARTING;
}

void PD::setsituation(int s){
	presituation = situation;
	situation = s;
}



