#include "MySprite.h"
#include "PD.h"
#include "CameraManager.h"
#include "MathMethod.h"

MySprite::MySprite(CCTexture2D* texture, bool inCamera){
	this->texture = texture;
	initWithTexture(texture);
	this->inCamera = inCamera;
}


MySprite::MySprite(CCTexture2D* texture, int frame, int frame_sum, bool inCamera){
	this->texture = texture;

	this->frame_sum = frame_sum;

	initWithSpriteFrame(CCSpriteFrame::createWithTexture(texture,
		CCRectMake(texture->getContentSize().width / (float)frame_sum * frame,
		0,
		texture->getContentSize().width / (float)frame_sum,
		texture->getContentSize().height)));

	//frame_sum = 0;

	this->inCamera = inCamera;
}


MySprite::MySprite(CCTexture2D* texture, double x, double y, double width, double height, bool inCamera){
	this->texture = texture;
	initWithTexture(texture);

	this->inCamera = inCamera;
	this->frame_sum = 0;

	setStatus(x, y, width, height);
	

	/*double bmp_width = texture->getContentSize().width;// sprite->getTextureRect().getMaxX();
	double bmp_height = texture->getContentSize().height; //sprite->getTextureRect().getMaxY();
	if (width == 0){
		double scale = height / bmp_height;
		setScale(scale);
		width = scale * bmp_width;
	}
	else if (height == 0){
		double scale = width / bmp_width;
		setScale(scale);
		height = scale * bmp_height;
	}
	else
		setSize(width, height);

	setPosition(ccp(PD::OX + x + width / 2, PD::OY + PD::screen_height - y - height / 2));*/

}

MySprite::MySprite(CCTexture2D* texture, int frame, double x, double y, double width, double height, bool inCamera){

	this->texture = texture;

	this->frame_sum = 0;

	initWithSpriteFrame(CCSpriteFrame::createWithTexture(texture,
		CCRectMake(texture->getContentSize().height * frame,
		0,
		texture->getContentSize().height,
		texture->getContentSize().height)));


	this->inCamera = inCamera;


	setStatus(x, y, width, height);
}



MySprite::MySprite(CCTexture2D* texture, int frame, int frame_sum, double x, double y, double width, double height, bool inCamera){

	this->texture = texture;

	this->frame_sum = frame_sum;

	initWithSpriteFrame(CCSpriteFrame::createWithTexture(texture,
		CCRectMake(texture->getContentSize().width / (float)frame_sum * frame,
		0,
		texture->getContentSize().width / (float)frame_sum,
		texture->getContentSize().height)));

	//frame_sum = 0;

	this->inCamera = inCamera;


	setStatus(x, y, width, height);
}

/*void MySprite::setX(double x){
	setPosition(ccp(PD::OX + x + width / 2, getPosition().y));
}
void MySprite::setY(double y){
	setPosition(ccp(getPosition().x, PD::OY + PD::screen_height - y - height / 2));
}
void MySprite::setXY(double x, double y){
	setPosition(ccp(PD::OX + x + width / 2, PD::OY + PD::screen_height - y - height / 2));
}

void MySprite::setSize(double width, double height){
	this->width = width;
	this->height = height;
	double bmp_width = getContentSize().width; //pSprite->getTextureRect().getMaxX();
	double bmp_height = getContentSize().height; //pSprite->getTextureRect().getMaxY();
	setScaleX(width / bmp_width);
	setScaleY(height / bmp_height);
}*/


void MySprite::setX(double x){
	this->x = x;

	//double view_x;

	if (inCamera && PD::cm->rate != 1){
		view_x = (x - PD::cm->scrx) / PD::cm->scrw * (PD::screen_width);
	}
	else{
		view_x = x;
	}

	setPosition(ccp(PD::OX + view_x + view_width / 2, getPosition().y));
}
void MySprite::setY(double y){
	this->y = y;

	//double view_y;

	if (inCamera && PD::cm->rate != 1){
		view_y = (y - PD::cm->scry) / PD::cm->scrh * (PD::screen_height);
	}
	else{
		view_y = y;
	}

	setPosition(ccp(getPosition().x, PD::OY + PD::screen_height - view_y - view_height / 2));
}
void MySprite::setXY(double x, double y){
	this->x = x;
	this->y = y;


	//double view_x, view_y;

	if (inCamera && PD::cm->rate != 1){

		view_x = (x - PD::cm->scrx) / PD::cm->scrw * (PD::screen_width);
		view_y = (y - PD::cm->scry) / PD::cm->scrh * (PD::screen_height);
	}
	else{
		view_x = x;
		view_y = y;
	}
	setPosition(ccp(PD::OX + view_x + view_width / 2, PD::OY + PD::screen_height - view_y - view_height / 2));
}

void MySprite::setSize(double width, double height){
	
	if (width == 0){
		width = MathMethod::getWidth(texture, height);
	}
	else if (height == 0){
		height = MathMethod::getHeight(texture, width);
	}

	this->width = width;
	this->height = height;


	//double view_width;
	//double view_height;

	if (inCamera && PD::cm->rate != 1){
		view_width = width * PD::cm->rate;
		view_height = height * PD::cm->rate;
	}
	else{
		view_width = width;
		view_height = height;
	}

	double bmp_width = getContentSize().width;
	double bmp_height = getContentSize().height;
	setScaleX(view_width / bmp_width);
	setScaleY(view_height / bmp_height);
}

void MySprite::setStatus(double x, double y, double width, double height){
	setSize(width, height);
	setXY(x, y);
}

void MySprite::setFrame(int frame){

	if (frame_sum == 0){
		setTextureRect(
			CCRectMake(getContentSize().height * frame,
			0,
			getContentSize().height,
			getContentSize().height));
	}
	else{
		setTextureRect(
			CCRectMake(texture->getContentSize().width / (float)frame_sum * frame,
			0,
			texture->getContentSize().width / (float)frame_sum,
			texture->getContentSize().height));
	}
}

void MySprite::refresh(){
	setStatus(x, y, width, height);
}