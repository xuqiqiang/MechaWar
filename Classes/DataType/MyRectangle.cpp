#include "MyRectangle.h"
#include "PD.h"

MyRectangle::MyRectangle(double x, double y, double width, double height, ccColor4F color, bool inCamera){

	this->inCamera = inCamera;



	this->color = color;


	setRectSize(width, height);
	
	setRectPosition(x, y);
	//visible = true;
}
void MyRectangle::draw()
{
	// ���ƶ�����߿�
	/*ccDrawColor4B(255, 255, 0, 255);
	glLineWidth(10);
	CCPoint vertices[] = { ccp(150, 150), ccp(100, 150), ccp(100, 100), ccp(150, 100) };
	//������ƶ�����߿�����ʹ������Ķ���������Ϊ������߿�Ķ���λ�ã��ڶ�������Ϊ��������������������ָ���Ƿ���β�Զ������γɷ���߿�
	//ע����ʵ�������������������ȽϺ�,һ����ȥ�����һ��������ccDrawPoly�����ڻ���Ĭ�Ϸ�յĶ�����߿���һ��ccDrawLineList���ڻ����߶��С�
	ccDrawPoly(vertices, 4, true);
	//�������
	CHECK_GL_ERROR_DEBUG();*/
	//ccDrawColor4B(0, 255, 0, 50);
	//����ʵ������
	glLineWidth(1);

	//CCPoint filledVertices1[] = { ccp(x, y), ccp(x + 2*width, y), ccp(x + 2*width, y + 2*height), ccp(x, y + 2*height) };
	///��������ڲ����ָ��ɫ�ʵĶ����
	//ccDrawSolidPoly(filledVertices1, 4, ccc4f(0, 0, 1, 1));

	double show_x, show_y;
	show_x = PD::OX + view_x;
	show_y = PD::OY + PD::screen_height - view_y - view_height;

	CCPoint filledVertices[] = { ccp(show_x, show_y), ccp(show_x + view_width, show_y),
		ccp(show_x + view_width, show_y + view_height), ccp(show_x, show_y + view_height) };
	//��������ڲ����ָ��ɫ�ʵĶ����
	ccDrawSolidPoly(filledVertices, 4, color);// ccc4f(0.5f, 0.5f, 1, 1));


	CHECK_GL_ERROR_DEBUG();

}


void MyRectangle::setRectPosition(double x, double y){
	this->x = x;// PD::OX + x;
	this->y = y;// PD::OY + PD::screen_height - y - height;

	if (inCamera && PD::cm->rate != 1){

		view_x = (x - PD::cm->scrx) / PD::cm->scrw * (PD::screen_width);
		view_y = (y - PD::cm->scry) / PD::cm->scrh * (PD::screen_height);
	}
	else{
		view_x = x;
		view_y = y;
	}
}

void MyRectangle::setRectSize(double width, double height){
	this->width = width;
	this->height = height;

	if (inCamera && PD::cm->rate != 1){
		view_width = width * PD::cm->rate;
		view_height = height * PD::cm->rate;
	}
	else{
		view_width = width;
		view_height = height;
	}
}

void MyRectangle::setRectColor(ccColor4F color){
	this->color = color;
}

void MyRectangle::refresh(){
	setRectSize(width, height);
	setRectPosition(x, y);
}