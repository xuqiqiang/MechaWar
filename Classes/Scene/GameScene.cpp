#include "GameScene.h"
#include "HelloWorldScene.h"
#include "GameManager.h"
#include "PD.h"
#include "Map.h"
#include "ObjectManager.h"
#include "SpriteManager.h"

#include "String.h"

USING_NS_CC;

/*#include<jni.h>
#define TAG "log_jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
*/
CCScene* GameScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameScene *layer = GameScene::create();

	//layer->addChild(SpriteManager::newSprite("background.jpg", 0, 0, 200, 200), 0);
	PD::initGame(layer);

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!CCLayer::init())
	{
		return false;
	}

	//scheduleUpdate();
	schedule(schedule_selector(GameScene::updateCustom), PD::delay/1000.0f);

	//unschedule(schedule_selector(GameScene::updateCustom));

	setTouchEnabled(true);

	setKeypadEnabled(true);
	//CCTimer
	//initGame();

	/*Map map;

	vector<Point> point = map.getPath(map.pos.getMapPoint(), map.des.getMapPoint());

	char str[50] = { '\0' };
	int data[PD::ROW][PD::COL], i, j;
	for (i = 0; i < PD::ROW;i++)
	for (j = 0; j < PD::COL; j++)
		data[i][j] = map.map_data[i][j];

	for (i = 0; i < point.size(); i++){
		data[point.at(i).i+1][point.at(i).j+1] = 6;
	}
	for (i = 0; i < PD::ROW; i++){
		for (j = 0; j < PD::COL; j++)
			sprintf(str, "%s%d",str, data[i][j]);

		sprintf(str, "%s\n", str);
	}

	CCMessageBox(str, "提示信息");*/

	
	

	return true;
}


void GameScene::initGame(){
	
}


//注册标准触摸事件
void GameScene::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
}


void GameScene::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
	// 单点
	CCTouch *pTouch = (CCTouch*)(pTouches->anyObject());

	// 所有点
	for (CCSetIterator iterTouch = pTouches->begin(); iterTouch != pTouches->end(); iterTouch++) {
		CCTouch *pCurTouch = (CCTouch*)(*iterTouch);
	}
	CCPoint touchPoint = convertTouchToNodeSpace(pTouch);

	if (!PD::om->onTouch(ccp(touchPoint.x, PD::screen_height - touchPoint.y), PD::TOUCH_DOWN))
		PD::cm->onTouch(pTouches, PD::TOUCH_DOWN);



	/*if (pTouches->count() == 1){
		// 单点
		CCTouch *pTouch = (CCTouch*)(pTouches->anyObject());

		CCPoint touchPoint = convertTouchToNodeSpace(pTouch);

		PD::om->onTouch(ccp(touchPoint.x, PD::screen_height - touchPoint.y), PD::TOUCH_DOWN);

		//CCLog("1");
		PD::om->pLabel_money->setString("1 Began");
	}
	else if (pTouches->count() == 2){
		CCSetIterator iterTouch = pTouches->begin();
		CCTouch *pCurTouch = (CCTouch*)(*iterTouch);

		CCPoint touchPoint1 = convertTouchToNodeSpace(pCurTouch);

		iterTouch++;
		pCurTouch = (CCTouch*)(*iterTouch);

		CCPoint touchPoint2 = convertTouchToNodeSpace(pCurTouch);

		//CCLog("2");

		PD::om->pLabel_money->setString("2 Began");

		//LOGD("2 Began");
	}*/
	//unschedule(schedule_selector(GameScene::updateCustom));
	//schedule(schedule_selector(GameScene::updateCustom), 1);

	
}

void GameScene::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){
	// 单点
	CCTouch *pTouch = (CCTouch*)(pTouches->anyObject());

	// 所有点
	for (CCSetIterator iterTouch = pTouches->begin(); iterTouch != pTouches->end(); iterTouch++) {
		CCTouch *pCurTouch = (CCTouch*)(*iterTouch);
	}
	CCPoint touchPoint = convertTouchToNodeSpace(pTouch);

	//PD::om->onTouch(ccp(touchPoint.x, PD::screen_height - touchPoint.y), PD::TOUCH_MOVE);
	if (!PD::om->onTouch(ccp(touchPoint.x, PD::screen_height - touchPoint.y), PD::TOUCH_MOVE))
		PD::cm->onTouch(pTouches, PD::TOUCH_MOVE);


	/*if (pTouches->count() == 1){
		// 单点
		CCTouch *pTouch = (CCTouch*)(pTouches->anyObject());

		CCPoint touchPoint = convertTouchToNodeSpace(pTouch);

		PD::om->onTouch(ccp(touchPoint.x, PD::screen_height - touchPoint.y), PD::TOUCH_MOVE);

		//CCLog("1");
		PD::om->pLabel_money->setString("1 Moved");
	}
	else if (pTouches->count() == 2){
		CCSetIterator iterTouch = pTouches->begin();
		CCTouch *pCurTouch = (CCTouch*)(*iterTouch);

		CCPoint touchPoint1 = convertTouchToNodeSpace(pCurTouch);

		iterTouch++;
		pCurTouch = (CCTouch*)(*iterTouch);

		CCPoint touchPoint2 = convertTouchToNodeSpace(pCurTouch);

		//CCLog("2");

		PD::om->pLabel_money->setString("2 Moved");

		//LOGD("2 Moved");
	}*/

}
void GameScene::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	// 单点
	CCTouch *pTouch = (CCTouch*)(pTouches->anyObject());

	// 所有点
	for (CCSetIterator iterTouch = pTouches->begin(); iterTouch != pTouches->end(); iterTouch++) {
		CCTouch *pCurTouch = (CCTouch*)(*iterTouch);
	}
	CCPoint touchPoint = convertTouchToNodeSpace(pTouch);

	//PD::om->onTouch(ccp(touchPoint.x, PD::screen_height - touchPoint.y), PD::TOUCH_UP);
	if (!PD::om->onTouch(ccp(touchPoint.x, PD::screen_height - touchPoint.y), PD::TOUCH_UP))
		PD::cm->onTouch(pTouches, PD::TOUCH_UP);


	/*if (pTouches->count() == 1){
		// 单点
		CCTouch *pTouch = (CCTouch*)(pTouches->anyObject());

		CCPoint touchPoint = convertTouchToNodeSpace(pTouch);

		PD::om->onTouch(ccp(touchPoint.x, PD::screen_height - touchPoint.y), PD::TOUCH_UP);

		//CCLog("1");
		PD::om->pLabel_money->setString("1 Ended");
	}
	else if (pTouches->count() == 2){
		CCSetIterator iterTouch = pTouches->begin();
		CCTouch *pCurTouch = (CCTouch*)(*iterTouch);

		CCPoint touchPoint1 = convertTouchToNodeSpace(pCurTouch);

		iterTouch++;
		pCurTouch = (CCTouch*)(*iterTouch);

		CCPoint touchPoint2 = convertTouchToNodeSpace(pCurTouch);

		//CCLog("2");

		PD::om->pLabel_money->setString("2 Ended");

		//LOGD("2 Ended");
	}*/
	
}

void GameScene::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent){

}

void GameScene::updateCustom(float dt){
/*time += 1;// dt;
char str[10];
sprintf(str,"%d",time);
pLabel->setString(str);*/
	PD::pm->logic();
	PD::om->logic();

	CCDirector* pDirector = CCDirector::sharedDirector();
	CCLog("%lf", 1 / pDirector->getAnimationInterval());
	//CCLog("update");
}


void GameScene::keyBackClicked()
{
	CCScene *scene = HelloWorld::scene();
	CCDirector::sharedDirector()->pushScene(scene);
}
void GameScene::keyMenuClicked()
{

}