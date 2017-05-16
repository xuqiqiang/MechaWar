#include "CameraManager.h"
#include "PD.h"
#include "Math.h"
#include "ObjectManager.h"

CameraManager::CameraManager(){

	rate = 1;
	oldrate = rate;

	scrx = 0;
	scry = 0;
	scrw = PD::screen_width / rate;
	scrh = PD::screen_height / rate;

	isfirst = true;
	ismove = false;
}

void CameraManager::onTouch(CCSet *pTouches, int touch_event){
	//double X = event.getX();
	//double Y = event.getY();

	if (touch_event == PD::TOUCH_UP){
		isfirst = true;
		oldrate = rate;
		if (scrx<0 || scry<0){
			scrx = 0;
			scry = 0;
		}
		if (scrx + scrw>PD::screen_width || scry + scrh>PD::screen_height){
			scrx = PD::screen_width - scrw;
			scry = PD::screen_height - scrh;
		}
		if (rate<1){
			scrx = 0;
			scry = 0;
			scrw = PD::screen_width;
			scrh = PD::screen_height;
			rate = 1;
		}
		else if (rate>3){

			rate = 3;
			scrw = PD::screen_width / rate;
			scrh = PD::screen_height / rate;
			scrx = x4 - scrw*x3;
			scry = y4 - scrh*y3;
		}
		ismove = false;

		return;
	}


	if (pTouches->count() == 1){

		if (rate == 1)
			return;

		
		CCTouch *pTouch = (CCTouch*)(pTouches->anyObject());

		CCPoint touchPoint = PD::gs->convertTouchToNodeSpace(pTouch);

		double X = touchPoint.x;
		double Y = PD::screen_height - touchPoint.y;

		if (touch_event == PD::TOUCH_DOWN){
			if (!ismove){
				oldX = X;
				oldY = Y;
				oldscrx = scrx;
				oldscry = scry;
				ismove = true;
			}
		}

		if (ismove){
			if (touch_event == PD::TOUCH_MOVE){
				scrx = oldscrx - (X - oldX);
				scry = oldscry - (Y - oldY);
				if (scrx + scrw>PD::screen_width)
					scrx = PD::screen_width - scrw;
				else if (scrx<0)
					scrx = 0;
				if (scry + scrh>PD::screen_height)
					scry = PD::screen_height - scrh;
				else if (scry<0)
					scry = 0;

				/*for (Spirit s : PD::om.spirit){
					s.setVertices(s.x, s.y, s.w, s.h, true);
				}*/
				PD::om->refreshView();
			}
		}

	}
	else if (pTouches->count() == 2){


		CCSetIterator iterTouch = pTouches->begin();
		CCTouch *pCurTouch = (CCTouch*)(*iterTouch);

		CCPoint touchPoint1 = PD::gs->convertTouchToNodeSpace(pCurTouch);

		iterTouch++;
		pCurTouch = (CCTouch*)(*iterTouch);

		CCPoint touchPoint2 = PD::gs->convertTouchToNodeSpace(pCurTouch);

		double x1 = touchPoint1.x;
		double y1 = PD::screen_height - touchPoint1.y;
		double x2 = touchPoint2.x;
		double y2 = PD::screen_height - touchPoint2.y;



		if (isfirst){
			oldline = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

			x3 = (x1 + x2) / 2 / PD::screen_width;
			y3 = (y1 + y2) / 2 / PD::screen_height;
			x4 = x3*scrw + scrx;
			y4 = y3*scrh + scry;
			isfirst = false;
			ismove = false;
		}
		else{
			newline = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
			rate = oldrate*newline / oldline;
			//if(rate<1)
			//	rate=1;
			scrw = PD::screen_width / rate;
			scrh = PD::screen_height / rate;
			scrx = x4 - scrw*x3;
			scry = y4 - scrh*y3;
			if (scrx<0 || scry<0){
				scrx = 0;
				scry = 0;
			}
			if (scrx + scrw>PD::screen_width || scry + scrh>PD::screen_height){
				scrx = PD::screen_width - scrw;
				scry = PD::screen_height - scrh;
			}
			if (rate<1){
				scrx = 0;
				scry = 0;
				scrw = PD::screen_width;
				scrh = PD::screen_height;
				rate = 1;
			}
			else if (rate>3){

				rate = 3;
				scrw = PD::screen_width / rate;
				scrh = PD::screen_height / rate;
				scrx = x4 - scrw*x3;
				scry = y4 - scrh*y3;
			}

			/*for (Spirit s : PD::om.spirit){
				s.setVertices(s.x, s.y, s.w, s.h, true);
			}*/

			PD::om->refreshView();
		}
	}
}