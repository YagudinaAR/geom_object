#pragma once

#include<iostream>
using namespace System::Drawing;
using namespace std;

struct Tpoint
{
	int x;
	int y;
	Tpoint() :x(0), y(0){};
	Tpoint(int _x,int _y) :x(_x), y(_y){};
	void setcoord(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

class shape
{
public:
	bool isVisible;
	bool isActive;
	shape() :isVisible(false), isActive(false){};
	virtual void Show(Graphics ^g) = 0;
	virtual void Hide(Graphics ^g) = 0;
	//virtual int cntPoint() = 0;
	virtual bool isPoint() = 0;
	virtual bool isLine() = 0;
	virtual bool isCircle() = 0;
	//virtual Tpoint *getbasepoint() = 0;
};

class Ipoint : public shape
{
public:
	Tpoint *p;
	Ipoint(Tpoint *_p) : p(_p) {}
	void Show(Graphics ^g)
	{
		g->DrawEllipse(Pens::Black, p->x - 2, p->y - 2, 4, 4);
		isVisible = true;
		isActive = true;

	}
	void Hide(Graphics ^g)
	{
		g->DrawEllipse(Pens::DarkTurquoise, p->x - 2, p->y - 2, 4, 4);
		isVisible = false;
		isActive = false;
	}

	void setmove(int _x, int _y)
	{
		p->x = _x;
		p->y = _y;
	}

	bool isPoint()
	{
			return true;
	}

	bool isLine()
	{
		return false;
	}

	bool isCircle()
	{
		return false;
	}
};

class Iline : public shape
{
public:
	Tpoint *l, *r;
	Iline(Tpoint *_l, Tpoint *_r) :l(_l), r(_r){};
	void Show(Graphics ^g)
	{
		g->DrawLine(Pens::Black, l->x, l->y, r->x, r->y);
		isActive = true;
		isVisible = true;
	}
	void Hide(Graphics ^g)
	{
		g->DrawLine(Pens::DarkTurquoise, l->x, l->y, r->x, r->y);
		isActive = false;
		isVisible = false;
	}

	void setmove(Tpoint *p, int _x, int _y)
	{
		if (l == p)
		{
			l->x = _x;
			l->y = _y;
		}
		if (r == p)
		{
			r->x = _x;
			r->y = _y;
		}
	}

	bool isPoint()
	{
		return false;
	}

	bool isLine()
	{
		return true;
	}

	bool isCircle()
	{
		return false;
	}
};

