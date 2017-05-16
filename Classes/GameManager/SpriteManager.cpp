#include "SpriteManager.h"
#include "PD.h"
#include "MathMethod.h"
#include "Math.h"


CCSprite* SpriteManager::newSprite(CCTexture2D* texture, double x, double y, double width, double height){
	CCSprite* sprite = CCSprite::createWithTexture(texture);
	
	double bmp_width = sprite->getContentSize().width;// sprite->getTextureRect().getMaxX();
	double bmp_height = sprite->getContentSize().height; //sprite->getTextureRect().getMaxY();
	if (width == 0){
		double scale = height / bmp_height;
		sprite->setScale(scale);
		//width = scale * bmp_width;
	}
	else if (height == 0){
		double scale = width / bmp_width;
		sprite->setScale(scale);
		//height = scale * bmp_height;
	}
	else
		setSize(sprite, width, height);
	//sprite->setAnchorPoint(ccp(0, 0));
	//sprite->setPosition(ccp(PD::OX + x, PD::OY + PD::screen_height - y - height));


	//sprite->setContentSize(ccp(width, height));

	//sprite->setAnchorPoint(ccp(0.5, 0.5));

	sprite->setPosition(ccp(PD::OX + x + width / 2, PD::OY + PD::screen_height - y - height / 2));

	return sprite;
}

CCSprite* SpriteManager::newSprite_frame(CCTexture2D* texture, int frame, double x, double y, double width, double height){
	//int frame_sum = (int)(texture->getContentSize().width / texture->getContentSize().height);
	CCSprite* sprite = CCSprite::createWithSpriteFrame(CCSpriteFrame::createWithTexture(texture, 
		CCRectMake(texture->getContentSize().height * frame,
		0,
		texture->getContentSize().height,
		texture->getContentSize().height)));//设置一个初始frame 
	
	double bmp_width = sprite->getContentSize().width;// sprite->getTextureRect().getMaxX();
	double bmp_height = sprite->getContentSize().height; //sprite->getTextureRect().getMaxY();
	if (width == 0){
		double scale = height / bmp_height;
		sprite->setScale(scale);
		//width = scale * bmp_width;
	}
	else if (height == 0){
		double scale = width / bmp_width;
		sprite->setScale(scale);
		//height = scale * bmp_height;
	}
	else
		setSize(sprite, width, height);
	//sprite->setAnchorPoint(ccp(0, 0));
	//sprite->setPosition(ccp(PD::OX + x, PD::OY + PD::screen_height - y - height));
	sprite->setPosition(ccp(PD::OX + x + width / 2, PD::OY + PD::screen_height - y - height / 2));
	//sprite->setContentSize(ccp(width, height));
	//sprite->setOpacity(0;)
	return sprite;
}

CCSprite* SpriteManager::newSprite_transparent(CCTexture2D* texture, double x, double y, double width, double height, int opacity){
	CCSprite* sprite = newSprite(texture, x, y, width, height);
	sprite->setOpacity(opacity);
	return sprite;
}

CCSprite* SpriteManager::newSprite_rotate(CCTexture2D* texture, double x, double y, double width, double height, double angle){
	CCSprite* sprite = newSprite(texture, x, y, width, height);
	sprite->setRotation(angle);
	return sprite;
}

/*CCSprite* SpriteManager::newSprite_rotate(CCTexture2D* texture, double x, double y, double width, double height, double angle){
	//CCSprite* sprite = newSprite(bmp, x, y, width, height);
	//sprite->setRotation(angle);
	CCSprite* sprite = CCSprite::createWithTexture(texture);

	double bmp_width = sprite->getContentSize().width; //sprite->getTextureRect().getMaxX();
	double bmp_height = sprite->getContentSize().height; //sprite->getTextureRect().getMaxY();
	//sprite->setRotation()
	if (width == 0){
		int scale = height / bmp_height;
		sprite->setScale(scale);
		width = scale*bmp_width;
	}
	else if (height == 0){
		int scale = width / bmp_width;
		sprite->setScale(scale);
		height = scale*bmp_height;
	}
	else
		setSize(sprite, width, height);
	sprite->setAnchorPoint(ccp(0, 0));

	double pre_x = PD::OX + x;
	double pre_y = PD::OY + PD::screen_height - y - height;
	double bevel = MathMethod::getBevel(width, height);
	double pre_rad = MathMethod::getRad(pre_x + width, pre_y + height, pre_x, pre_y, bevel);
	double new_rad = pre_rad - MathMethod::angle2Rad(angle);
	double new_x = pre_x + width / 2 + bevel / 2 * cos(new_rad);
	double new_y = pre_y + height / 2 + bevel / 2 * sin(new_rad);
	sprite->setPosition(ccp(new_x, new_y));
	sprite->setRotation(angle);
	sprite->setContentSize(ccp(width, height));
	return sprite;
}*/
//////////////////////////////////////////////////////


CCSprite* SpriteManager::newSprite(const char* bmp, double x, double y, double width, double height){
	CCSprite* sprite = CCSprite::create(bmp);
	//sprite->setRotation()
	double bmp_width = sprite->getContentSize().width;// sprite->getTextureRect().getMaxX();
	double bmp_height = sprite->getContentSize().height; //sprite->getTextureRect().getMaxY();
	if (width == 0){
		double scale = height / bmp_height;
		sprite->setScale(scale);
		width = scale * bmp_width;
	}
	else if (height == 0){
		double scale = width / bmp_width;
		sprite->setScale(scale);
		height = scale * bmp_height;
	}
	else
		setSize(sprite, width, height);
	sprite->setAnchorPoint(ccp(0, 0));
	sprite->setPosition(ccp(PD::OX + x, PD::OY + PD::screen_height - y - height));

	sprite->setContentSize(ccp(width, height));
	//sprite->setOpacity(0;)
	return sprite;
}

CCSprite* SpriteManager::newSprite_transparent(const char* bmp, double x, double y, double width, double height, int opacity){
	CCSprite* sprite = newSprite(bmp, x, y, width, height);
	sprite->setOpacity(opacity);
	return sprite;
}

CCSprite* SpriteManager::newSprite_rotate(const char* bmp, double x, double y, double width, double height, double angle){
	//CCSprite* sprite = newSprite(bmp, x, y, width, height);
	//sprite->setRotation(angle);
	CCSprite* sprite = CCSprite::create(bmp);

	double bmp_width = sprite->getContentSize().width; //sprite->getTextureRect().getMaxX();
	double bmp_height = sprite->getContentSize().height; //sprite->getTextureRect().getMaxY();
	//sprite->setRotation()
	if (width == 0){
		int scale = height / bmp_height;
		sprite->setScale(scale);
		width = scale*bmp_width;
	}
	else if (height == 0){
		int scale = width / bmp_width;
		sprite->setScale(scale);
		height = scale*bmp_height;
	}
	else
		setSize(sprite, width, height);
	sprite->setAnchorPoint(ccp(0, 0));

	double pre_x = PD::OX + x;
	double pre_y = PD::OY + PD::screen_height - y - height;
	double bevel = MathMethod::getBevel(width, height);
	double pre_rad = MathMethod::getRad(pre_x + width, pre_y + height, pre_x, pre_y, bevel);
	double new_rad = pre_rad - MathMethod::angle2Rad(angle);
	double new_x = pre_x + width / 2 + bevel / 2 * cos(new_rad);
	double new_y = pre_y + height / 2 + bevel / 2 * sin(new_rad);
	sprite->setPosition(ccp(new_x, new_y));
	sprite->setRotation(angle);
	sprite->setContentSize(ccp(width, height));
	return sprite;
}

void SpriteManager::setSize(CCSprite* pSprite, double width, double height){
	double bmp_width = pSprite->getContentSize().width; //pSprite->getTextureRect().getMaxX();
	double bmp_height = pSprite->getContentSize().height; //pSprite->getTextureRect().getMaxY();
	pSprite->setScaleX(width / bmp_width);
	pSprite->setScaleY(height / bmp_height);
}

void SpriteManager::setPosition(CCSprite* pSprite, CCPoint point){
	//pSprite->setPosition(ccp(PD::OX + point.x, PD::OY + PD::screen_height - point.y - pSprite->getContentSize().height));
	//pSprite->setPosition(ccp(PD::OX + point.x + width / 2, PD::OY + PD::screen_height - point.y - height / 2));
}

void SpriteManager::setRotation(CCSprite* pSprite, double angle){
	double pre_x = pSprite->getPosition().x;
	double pre_y = pSprite->getPosition().y;
	double width = pSprite->getContentSize().width;
	double height = pSprite->getContentSize().height;
	double bevel = MathMethod::getBevel(width, height);
	double pre_rad = MathMethod::getRad(pre_x + width, pre_y + height, pre_x, pre_y, bevel);
	double new_rad = pre_rad - MathMethod::angle2Rad(angle);
	double new_x = pre_x + width / 2 + bevel / 2 * cos(new_rad);
	double new_y = pre_y + height / 2 + bevel / 2 * sin(new_rad);
	pSprite->setPosition(ccp(new_x, new_y));
	pSprite->setRotation(angle);
}

double SpriteManager::width_div_height(CCTexture2D* texture){
	return texture->getContentSize().width / texture->getContentSize().height;
}

double SpriteManager::height_div_width(CCTexture2D* texture){
	return texture->getContentSize().height / texture->getContentSize().width;
}

cocos2d::CCLabelTTF* SpriteManager::newLabel(const char* text, double x, double y, double size, const char* font){
	cocos2d::CCLabelTTF* pLabel = CCLabelTTF::create(text, font, size);
	//new CCLabel
	pLabel->setAnchorPoint(ccp(0, 0));
	pLabel->setPosition(ccp(PD::OX + x, PD::OY + PD::screen_height - y - size));
	return pLabel;
}