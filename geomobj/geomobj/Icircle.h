#pragma once
#include"Ishape.h"
#include"IPoint.h"
using namespace std;

class Icircle: public Ishape
{
protected:
	TPoint *l;
	TPoint *r;
public:
	Icircle()
	{
		l = NULL;
		r = NULL;
		Active = false;
		Visible = false;
	}
	~Icircle();
	void setcircle(TPoint *l1, TPoint *r1)
	{
		l->x = l1->x;
		l->y = l1->y;
		r->x = r1->x;
		r->y = r1->y;
	}
	TPoint *getLcircle()
	{
		return l;
	}
	TPoint *getRcircle()
	{
		return r;
	}
	virtual void show(Graphics ^g)
	{
		if (!IsVisible() && IsActive())
		{
			g->DrawEllipse(Pens::Black,r->x-l->x,r->y-l->y,2*r->x,2*r->y);
			Visible = true;
		}
	}
	virtual void hide(Graphics ^g)
	{
		if (IsVisible() && IsActive())
		{
			g->DrawEllipse(Pens::White, r->x - l->x, r->y - l->y, 2 * r->x, 2 * r->y);
			Visible = false;
		}
	}
	virtual void move(Graphics ^g, int X, int Y)
	{
		hide(g);
		r->x += X;
		r->y += Y;
		show(g);
	}

};