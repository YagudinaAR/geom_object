#pragma once
#include"Ishape.h"
#include"IPoint.h"
using namespace std;

class Icircle: public Ishape
{
protected:
	Ipoint p;
	Ipoint t;

public:
	Icircle(Ipoint _p, Ipoint _t)
	{
		p = _p;
		t = _t;
	}
	~Icircle()
	{

	}

	void setpointP(Ipoint _p)
	{
		p = _p;
	}

	void setpointT(Ipoint _t)
	{
		t = _t;
	}

	Ipoint getpointP()
	{
		return p;
	}
	Ipoint getpointT()
	{
		return t;
	}

	virtual void show(Graphics ^g)
	{
		if (!IsVisible() && IsActive())
		{
			g->DrawEllipse(Pens::Black,p.x-t.x,p.y-t.y,2*t.x,2*t.y);
			Visible = true;
		}
	}
	virtual void hide(Graphics ^g)
	{
		if (IsVisible() && IsActive())
		{
			g->DrawEllipse(Pens::White, p.x - t.x, p.y - t.y, 2 * t.x, 2 * t.y);
			Visible = false;
		}
	}
	virtual void move(Graphics ^g, int X, int Y)
	{
		hide(g);
		t.x += X;
		t.y += Y;
		show(g);
	}

};