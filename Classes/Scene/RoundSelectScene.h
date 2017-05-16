#ifndef __RoundSelectScene_H__
#define __RoundSelectScene_H__

#include "cocos2d.h"

USING_NS_CC;

class RoundSelectScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
	CREATE_FUNC(RoundSelectScene);

	int selectround;

	cocos2d::CCLabelTTF* pLabel;
	//int time;
	//void update(float dt);

	cocos2d::CCSprite* last_btn;
	cocos2d::CCSprite* next_btn;

	CCLayer* select_bar;

	void refresh_select_bar();

	//virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void registerWithTouchDispatcher(void);

	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);


	virtual void keyBackClicked();
	virtual void keyMenuClicked();
};

#endif // __HELLOWORLD_SCENE_H__
