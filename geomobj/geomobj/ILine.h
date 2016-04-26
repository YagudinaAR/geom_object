#pragma once
#include"Ishape.h"
#include"IPoint.h"
#include<iostream>

using namespace std;

class ILine:public Ishape
{
protected:
	Ipoint bpoint, fpoint;
public:

	ILine(Ipoint _x, Ipoint _y)
	{
		bpoint = _x;
		fpoint = _y;
	    Active=false;
		Visible=false;
	}
	~ILine();
	void setline(Ipoint _x, Ipoint _y)
	{
		bpoint = _x;
		fpoint = _y;
	}
	Ipoint getbpoint()
	{
		return bpoint;
	}
	Ipoint getfpoint()
	{
		return fpoint;
	}
	virtual void show(Graphics ^g)
	{
		if (!IsVisible() && IsActive())
		{
			g->DrawLine(Pens::Black, bpoint.x, bpoint.y, fpoint.x, fpoint.y);
			Visible = true;
		}
	}
	virtual void hide(Graphics ^g)
	{
		if (IsVisible() && IsActive())
		{
			g->DrawLine(Pens::White, bpoint.x, bpoint.y, fpoint.x, fpoint.y);
			Visible = false;
		}
	}
	virtual void move(Graphics ^g, int X, int Y)
	{
		hide(g);
		fpoint.x += X;
		fpoint.y += Y;
		show(g);
	}


};