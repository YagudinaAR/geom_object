#pragma once

#include <iostream>
#include"Ishape.h"
using namespace std;
using namespace System::Drawing;

/*struct TPoint
{
	int x;
	int y;
};*/

class Ipoint: public Ishape
{
public:
	int x, y;
	Ipoint()
	{
		x = 0;
		y = 0;
	}
	Ipoint(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void setcoord(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	/*TPoint *getPoint()
	{
	return p;
	}*/
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}

	~Ipoint()
	{
		//delete p;
	}
	Ipoint &operator=(const Ipoint &_p)
	{
		x = _p.x;
		y = _p.y;
		return *this;
	}
	virtual void show(Graphics ^g)
	{
		if (!IsVisible() && IsActive())
		{
			g->DrawEllipse(Pens::Black,x - 2, y - 2, 4, 4);
			Visible = true;
		}
	}
	virtual void hide(Graphics ^g)
	{
		if (IsVisible() && IsActive())
		{
			g->DrawEllipse(Pens::White, x - 2, y - 2, 4, 4);
			Visible = false;
		}
	}
	virtual void move(Graphics ^g, int X, int Y)
	{
		hide(g);
		x += X;
		y += Y;
		show(g);

	}

};