#pragma once
#include"Ishape.h"
#include"IPoint.h"
#include<iostream>

using namespace std;

class ILine:public Ishape
{
protected:
	TPoint *l;
	TPoint *r;
public:

	ILine(TPoint *l1, TPoint *r1) :l(l1), r(r1)
	{
	    Active=false;
		Visible=false;
	}
	~ILine();
	void setline(TPoint *l1, TPoint *r1)
	{
		l->x = l1->x;
		l->y = l1->y;
		r->x = r1->x;
		r->y = r1->y;
		l->next = NULL;
		r->next = NULL;
	}
	TPoint *getLline()
	{
		return l;
	}
	TPoint *getRline()
	{
		return r;
	}
	virtual void show(Graphics ^g)
	{
		if (!IsVisible() && IsActive())
		{
			g->DrawLine(Pens::Black, l->x, l->y, r->x, r->y);
			Visible = true;
		}
	}
	virtual void hide(Graphics ^g)
	{
		if (IsVisible() && IsActive())
		{
			g->DrawLine(Pens::White, l->x, l->y, r->x, r->y);
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