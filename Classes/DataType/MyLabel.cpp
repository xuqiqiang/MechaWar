#include "MyLabel.h"
#include "PD.h"

CCLabelTTF* MyLabel::getLabel(double size, const char* font){
	cocos2d::CCLabelTTF* pLabel = CCLabelTTF::create("", font, size);
	pLabel->setAnchorPoint(ccp(0, 0));
	return pLabel;
}
CCLabelTTF* MyLabel::getLabel(const char* text, double x, double y, double size, const char* font){
	cocos2d::CCLabelTTF* pLabel = CCLabelTTF::create(text, font, size);
	pLabel->setAnchorPoint(ccp(0, 0));
	pLabel->setPosition(ccp(PD::OX + x, PD::OY + PD::screen_height - y - size));
	return pLabel;
}

CCLabelTTF* MyLabel::getLabel(int number, double x, double y, double size, const char* font){
	char str[50];
	sprintf(str, "%d", number);
	cocos2d::CCLabelTTF* pLabel = CCLabelTTF::create(str, font, size);
	pLabel->setAnchorPoint(ccp(0, 0));
	pLabel->setPosition(ccp(PD::OX + x, PD::OY + PD::screen_height - y - size));
	return pLabel;
}

void MyLabel::setXY(CCLabelTTF* label, double x, double y){
	label->setPosition(ccp(PD::OX + x, PD::OY + PD::screen_height - y - label->getFontSize()));
}

void MyLabel::setNumber(CCLabelTTF* label, int number){
	char str[30];
	sprintf(str, "%d", number);
	label->setString(str);
}