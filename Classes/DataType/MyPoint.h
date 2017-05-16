#ifndef __MyPoint_H__
#define __MyPoint_H__

//namespace MyNameSpace{


#define Point_null MyPoint(-1,-1)

	class MyPoint
	{
	public:
		MyPoint();
		MyPoint(int i, int j);
		//~MyPoint();

		bool operator== (const MyPoint& p) const
		{
			return (i == p.i&&j == p.j);
		}

		bool operator!= (const MyPoint& p) const
		{
			return !(i == p.i&&j == p.j);
		}

		MyPoint operator+ (const int n) const
		{
			return MyPoint(i + n, j + n);
		}

		//static MyPoint newMyPoint(int i, int j);

		int i, j;

		MyPoint getTruePoint();

		MyPoint getMapPoint();

		MyPoint clone();
	};


#endif