#include "RoundSelectScene.h"
#include "HelloWorldScene.h"
#include "SpriteManager.h"
#include "RoundManager.h"
#include "GameScene.h"

USING_NS_CC;

CCScene* RoundSelectScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
	RoundSelectScene *layer = RoundSelectScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool RoundSelectScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	/*CCSprite* bkg_Sprite = CCSprite::create("bkg.jpg");
	SpriteManager::setSize(bkg_Sprite, PD::screen_width, PD::screen_height);
	//pSprite->setScale(2);
	//pSprite->setContentSize(CCSize(PD::screen_width,PD::screen_height));
	bkg_Sprite->setAnchorPoint(ccp(0, 0));
	// position the sprite on the center of the screen
	bkg_Sprite->setPosition(ccp(PD::OX, PD::OY));

	// add the sprite as a child to this layer
	this->addChild(bkg_Sprite, 0);



	CCSprite* background_Sprite = CCSprite::create("background.jpg");
	SpriteManager::setSize(background_Sprite, PD::W * 80, PD::H * 80);
	//pSprite->setScale(2);
	//pSprite->setContentSize(CCSize(PD::screen_width,PD::screen_height));
	background_Sprite->setAnchorPoint(ccp(0, 0));
	// position the sprite on the center of the screen
	background_Sprite->setPosition(ccp(PD::OX + PD::W * 80, PD::OY));

	// add the sprite as a child to this layer
	this->addChild(background_Sprite, 0);*/

	
	addChild(SpriteManager::newSprite("bkg.jpg", 0, 0, PD::screen_width, PD::screen_height),0);



	last_btn = SpriteManager::newSprite_rotate("promote.png", 0, PD::H * 40, PD::W * 8, PD::W * 8, 270);
	next_btn = SpriteManager::newSprite_rotate("promote.png", PD::W * 92, PD::H * 40, PD::W * 8, PD::W * 8, 90);
	//next_btn->setTag();
	addChild(next_btn, 0);

	addChild(last_btn, 0);

	selectround = 0;

	refresh_select_bar();


	setTouchEnabled(true);

	setKeypadEnabled(true);

	
	//CCLayer* 
	//select_bar->setPosition(ccp(PD::W * 10, PD::H * 10));
	//select_bar->setContentSize(ccp(PD::W * 80, PD::H * 80));
	//select_bar->addChild(SpriteManager::newSprite("background.jpg", PD::W * 10, PD::H * 10, PD::W * 10, PD::H * 10), 50);
	
	/*if (selectround<PD::rm->roundallow)
		Drawer.DrawImage_rotate(PD.resm.probmp, (float)(W * 92), (float)(H * 40), (float)(W * 8), (float)(W * 8), 90, false);
	else
		Drawer.DrawImage_rotate(PD.resm.unallowbmp, (float)(W * 92), (float)(H * 40), (float)(W * 8), (float)(W * 8), 90, false);

	if (selectround>0)
		Drawer.DrawImage_rotate(PD.resm.probmp, 0, (float)(H * 40), (float)(W * 8), (float)(W * 8), 270, false);
	else
		Drawer.DrawImage_rotate(PD.resm.unallowbmp, 0, (float)(H * 40), (float)(W * 8), (float)(W * 8), 270, false);
	*/

    /*CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
										menu_selector(RoundSelectScene::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

	time = 0;
    
    pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
	//pLabel->setString("ds%d");
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
	pSprite->setScale(2);
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

	scheduleUpdate();*/
    
    return true;
}


void RoundSelectScene::refresh_select_bar(){

	double startX = PD::W * 10;
	double startY = PD::H * 10;
	double fieldW = PD::W * 80;
	double fieldH = PD::H * 80;
	double width = fieldW / (PD::COL - 2);
	double height = fieldH / (PD::ROW - 2);

	select_bar = CCLayer::create();

	select_bar->addChild(SpriteManager::newSprite("background.jpg", startX, startY, fieldW, fieldH), 0);

	



	int i, j;
	for (i = 0; i < PD::ROW - 2; i++)
	for (j = 0; j < PD::COL - 2; j++)
	if (PD::rm->map[selectround][i + 1][j + 1] == 2){
		select_bar->addChild(SpriteManager::newSprite("house1.png", startX + j*width, startY + i*height, 0, height), 0);
		select_bar->addChild(SpriteManager::newSprite_transparent("houseshadow1.png", startX + j*width, startY + i*height, 0, height, 150), 0);
	}
	else if (PD::rm->map[selectround][i + 1][j + 1] == 5){
		select_bar->addChild(SpriteManager::newSprite("house2.png", startX + j*width, startY + (i - 1)*height, 0, height * 3), 0);
		select_bar->addChild(SpriteManager::newSprite_transparent("houseshadow2.png", startX + j*width, startY + (i - 1)*height, 0, height * 3, 150), 0);
	}
	else if (PD::rm->map[selectround][i + 1][j + 1] == 4){
		select_bar->addChild(SpriteManager::newSprite("house3.png", startX + j*width, startY + (i - 1)*height, 0, height * 2), 0);
		select_bar->addChild(SpriteManager::newSprite_transparent("houseshadow3.png", startX + j*width, startY + (i - 1)*height, 0, height * 2, 150), 0);

	}
	else if (PD::rm->map[selectround][i + 1][j + 1] == 3){
		select_bar->addChild(SpriteManager::newSprite("house4.png", startX + j*width, startY + (i - 1)*height, 0, height * 2), 0);
		select_bar->addChild(SpriteManager::newSprite_transparent("houseshadow4.png", startX + j*width, startY + (i - 1)*height, 0, height * 2, 150), 0);

	}

	char str[10];
	sprintf(str, "Round %d", selectround + 1);


	pLabel = SpriteManager::newLabel(str, PD::W * 44, PD::H * 3.5, PD::W * 4, "Arial");
	// add the label as a child to this layer
	select_bar->addChild(pLabel, 1);


	addChild(select_bar, 0);

	
}


//注册标准触摸事件
void RoundSelectScene::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
}


void RoundSelectScene::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent){
	
}

void RoundSelectScene::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent){
	

}
void RoundSelectScene::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	// 单点
	CCTouch *pTouch = (CCTouch*)(pTouches->anyObject());

	// 所有点
	for (CCSetIterator iterTouch = pTouches->begin(); iterTouch != pTouches->end(); iterTouch++) {
		CCTouch *pCurTouch = (CCTouch*)(*iterTouch);
	}
	CCPoint touchPoint = convertTouchToNodeSpace(pTouch);
	if (last_btn->boundingBox().containsPoint(touchPoint))
	{
		if (selectround > 0){
			selectround--;
			select_bar->removeAllChildren();
			this->removeChild(select_bar);
			refresh_select_bar();
		}
	}
	else if (next_btn->boundingBox().containsPoint(touchPoint))
	{
		//CCMessageBox("点击了我", "提示信息");
		if (selectround < PD::rm->roundallow){
			selectround++;
			select_bar->removeAllChildren();
			this->removeChild(select_bar);
			refresh_select_bar();
		}
	}
	else if (select_bar->boundingBox().containsPoint(touchPoint))
	{
		PD::round = selectround;
		CCScene *scene = GameScene::scene();
		CCDirector::sharedDirector()->replaceScene(scene);
	}
}

void RoundSelectScene::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent){

}

void RoundSelectScene::menuCloseCallback(CCObject* pSender)
{
	CCScene *scene = HelloWorld::scene();
	CCDirector::sharedDirector()->pushScene(scene);
}

/*void RoundSelectScene::update(float dt){
	time += 1;// dt;
	char str[10];
	sprintf(str,"%d",time);
	pLabel->setString(str);
}*/


void RoundSelectScene::keyBackClicked()
{
	CCScene *scene = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(scene);
}
void RoundSelectScene::keyMenuClicked()
{

}