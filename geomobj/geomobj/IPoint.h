#pragma once

#include <iostream>
#include"Ishape.h"
using namespace std;
using namespace System::Drawing;

struct TPoint
{
	int x;
	int y;
	TPoint *next;
};

class Ipoint: public Ishape
{
public:
	TPoint *p;
	Ipoint(TPoint *_p) :p(_p)
	{
		Active = false;
		Visible = false;
	}

	void setpoint(TPoint *pp)
	{
		p = pp;
	}
	void setpointcoord(int _x, int _y)
	{
		p->x = _x;
		p->y = _y;
		
	}
	TPoint* getpoint()
	{
		return p;
	}
	int getx()
	{
		return p->x;
	}
	int gety()
	{
		return p->y;
	}

	~Ipoint()
	{
		//delete p;
	}

	virtual void show(Graphics ^g)
	{
		if (!IsVisible() && IsActive())
		{
			g->DrawEllipse(Pens::Black,p->x - 2, p->y - 2, 4, 4);
			Visible = true;
		}
	}
	virtual void hide(Graphics ^g)
	{
		if (IsVisible() && IsActive())
		{
			g->DrawEllipse(Pens::White, p->x - 2, p->y - 2, 4, 4);
			Visible = false;
		}
	}
	virtual void move(Graphics ^g, int X, int Y)
	{
		hide(g);
		p->x += X;
		p->y += Y;
		show(g);

	}

};