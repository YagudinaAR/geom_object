#pragma once

#include<iostream>
using namespace System::Drawing;
using namespace std;

struct Tpoint
{
	int x;
	int y;
	Tpoint() :x(0), y(0){};
	Tpoint(int _x, int _y) :x(_x), y(_y){};
	bool compare(const Tpoint &p)//поиск точки в окрестности
	{
		return (x - 10 > p.x) && (x + 10 < p.x) && (y - 10 > p.y) && (y + 10 < p.y);
	}
};

class shape
{
public:
	bool isVisible;
	bool isActive;
	shape() :isVisible(false), isActive(false){};//false
	virtual void Show(Graphics ^g) = 0;
	virtual void Hide() = 0;
	virtual bool isPoint() = 0;
	virtual bool isLine() = 0;
	virtual bool isCircle() = 0;
	virtual bool cmp1(const Tpoint &pn1) = 0;
	virtual bool cmp2(const Tpoint &pn1, const Tpoint &pn2) = 0;
	virtual Tpoint *getbasepoint() = 0;
};

class Ipoint : public shape
{
	Tpoint *p;
public:
	Ipoint(Tpoint *_p) : p(_p) {}
	void Show(Graphics ^g)
	{
		isVisible = true;
		g->DrawEllipse(Pens::Black, p->x - 2, p->y - 2, 4, 4);

	}
	void Hide()
	{
		isVisible = false;
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

	bool cmp1(const Tpoint &pn1)
	{
		return p->compare(pn1);
	}

	bool cmp2(const Tpoint &pn1, const Tpoint &pn2)
	{
		return false;
	}

	Tpoint *getbasepoint()
	{
		return p;
	}
};

class Iline : public shape
{
	Tpoint *l, *r;
public:
	Iline(Tpoint *_l, Tpoint *_r) :l(_l), r(_r){};
	void Show(Graphics ^g)
	{
		g->DrawLine(Pens::Black, l->x, l->y, r->x, r->y);
		isActive = true;
		isVisible = true;
	}
	void Hide()
	{
		isVisible = false;
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
	bool cmp1(const Tpoint &pn1)
	{
		return false;
	}

	bool cmp2(const Tpoint &pn1, const Tpoint &pn2)//левая точка или правая точка
	{
		return (l->compare(pn1) && r->compare(pn2));

	}
	Tpoint *getbasepoint()
	{
		return NULL;
	}
};


