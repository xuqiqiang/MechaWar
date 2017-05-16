#include "HelloWorldScene.h"
#include "RoundSelectScene.h"
#include "MyRectangle.h"
#include "SpriteManager.h"
#include "MyPoint.h"
#include "MySprite.h"
#include "MyRect.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


	PD::init(visibleSize, origin);

	CCDirector* pDirector = CCDirector::sharedDirector();
	
	CCLog("%lf",1/pDirector->getAnimationInterval());
	CCLog("%lf", pDirector->getSecondsPerFrame());
    
	//CCLayerColor* layer = CCLayerColor::create(ccc4(0, 128, 128, 255));
	//layer->setContentSize(CCSize(PD::screen_width, PD::screen_height));// visibleSize);// CCSizeMake(120, 80));
	//layer->setPosition(CCPoint(origin.x, origin.y));
	//addChild(layer, 10);

	addChild(SpriteManager::newSprite("bkg.jpg", 0, 0, PD::screen_width, PD::screen_height), 0);


	//CCDictionary *strings = CCDictionary::createWithContentsOfFile("chinese.xml");
	//const char *charchinese = ((CCString*)strings->objectForKey("chinese"))->m_sString.c_str();

	//char str[10];
	//sprintf(str, "Round %d", selectround + 1);


	CCLabelTTF* pLabel = SpriteManager::newLabel("MechaWar", PD::W * 41, PD::H * 3.5, PD::W * 4, "Arial");
	addChild(pLabel, 1);


	CCMenuItemFont* start = CCMenuItemFont::create("START", this, menu_selector(HelloWorld::Handle));
	CCMenuItemFont* resume = CCMenuItemFont::create("RESUME", this, menu_selector(HelloWorld::Handle));

	start->setFontSizeObj(100);
	resume->setFontSizeObj(100);
	start->setFontNameObj("Arial");
	start->setTag(1);
	resume->setTag(2);
	resume->setFontNameObj("Arial");
	//创建菜单
	CCMenu* menu = CCMenu::create(start, resume, NULL);
	addChild(menu, 30);
	//对齐菜单项
	menu->alignItemsVertically();


	setKeypadEnabled(true);

	/*CCSprite* sprite = new CCSprite();
	sprite->initWithFile("house1.png");
	sprite->sett
	sprite->setPosition(ccp(200, 300));
	addChild(sprite, 160);
	char str[50];
	sprintf(str, "%f", sprite->getContentSize().width);
	CCMessageBox(str, "提示信息");*/

	/*CCSprite* sprite1 = CCSprite::create("house1.png");
	sprite1->setPosition(ccp(200, 300));
	addChild(sprite1, 160);
	//sprite1->setContentSize(ccp(30, 30));
	sprite1->setScale(2);
	sprite1->getContentSize

	CCSprite* sprite2 = CCSprite::create("house3.png");
	sprite2->setPosition(ccp(200, 300));
	addChild(sprite2, 60);
	//sprite2->setScaleX(2);
	//sprite2->setScaleY(2);

	char str[50];
	sprintf(str, "%f", sprite1->getOffsetPosition().x);
	CCMessageBox(str, "提示信息");*/

	//MyRectangle* r = new MyRectangle(PD::W*10, PD::H*10, PD::W*80, PD::H*80, ccc4f(0, 0, 1, 1));
	//addChild(r, 60);
	
	
	/*CCTexture2D* cache = CCTextureCache::sharedTextureCache()->addImage("bkg.jpg");
	

		char str[50];
		sprintf(str, "%f", cache->getContentSize().width);
	CCMessageBox(str, "提示信息");
	CCSprite* sprite1 = CCSprite::createWithTexture(cache);
	sprite1->setPosition(ccp(500, 300));
	addChild(sprite1, 60);*/

	//CCSize s = CCDirector::sharedDirector()->getWinSize();
	//#1：生成动画需要的数据类 
	/*CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("bkg.jpg");
	
	CCSpriteFrame *frame0 = CCSpriteFrame::createWithTexture(texture, CCRectMake(32 * 0, 48 * 0, 32, 48));
	CCSpriteFrame *frame1 = CCSpriteFrame::createWithTexture(texture, CCRectMake(32 * 1, 48 * 0, 32, 48));
	CCSpriteFrame *frame2 = CCSpriteFrame::createWithTexture(texture, CCRectMake(32 * 2, 48 * 0, 32, 48));
	CCSpriteFrame *frame3 = CCSpriteFrame::createWithTexture(texture, CCRectMake(32 * 3, 48 * 0, 32, 48));
	CCArray* animFrames = new CCArray();// <CCSpriteFrame*> *animFrames = new CCArray<CCSpriteFrame*>(4);
	animFrames->addObject(frame0);
	animFrames->addObject(frame1);
	animFrames->addObject(frame2);
	animFrames->addObject(frame3);
	CCAnimation *animation = CCAnimation::createWithSpriteFrames(animFrames, 0.5f);
	animFrames->release();
	//#2：初始化并设置Sprite 
	CCSprite *sprite = CCSprite::createWithSpriteFrame(CCSpriteFrame::createWithTexture(texture, CCRectMake(32 * 0, 48 * 0, 32, 48)));//设置一个初始frame 
	sprite->setPosition(ccp(300, 300));
	addChild(sprite,60);
	//#3：使用animation生成一个动画动作animate 
	CCAnimate *animate = CCAnimate::create(animation);// :actionWithAnimation(animation, false);
	sprite->runAction(CCRepeatForever::create(animate));// :actionWithAction(animate));//重复播放 
	*/


	

	/*char str[50];
	sprintf(str, "%f", CCRANDOM_0_1());
	CCMessageBox(str, "提示信息");*/

	MyRect r;
	//r.size.
    return true;
}


void HelloWorld::Handle(CCObject* sender)
{
	CCNode* node = (CCNode*)sender;

	switch (node->getTag()){
	case 1:
		//CCScene *scene = RoundSelectScene::scene();
		CCDirector::sharedDirector()->replaceScene(RoundSelectScene::scene());
		break;
	case 2:
		//CCDirector::sharedDirector()->retainCount
		CCDirector::sharedDirector()->popToRootScene();// > popScene();
		break;
	}
	//CCDirector::sharedDirector()->pushScene(scene);// ->replaceScene(scene);// CCTransitionJumpZoom::transitionWithDuration(1.2f, scene));
}



void HelloWorld::keyBackClicked()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
#else
	CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
#endif
}
void HelloWorld::keyMenuClicked()
{

}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif

	
}
