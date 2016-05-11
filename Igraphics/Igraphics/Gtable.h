#pragma once

#include <iostream>
#include"shape.h"
#include <math.h>
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Gtable
{
	shape **table;
	int cnt;
public:
	Gtable() :cnt(0)
	{
		table = new shape*[100];
		for (int i = 0; i < 100; i++)
		{
			table[i] = NULL;
		}
	}

	Gtable(const Gtable &Itable)
	{
		cnt = Itable.cnt;
		for (int i = 0; i < cnt; i++)
		{
			table[i] = Itable.table[i];
		}

	}

	~Gtable()
	{
		delete[] table;
	}

	void add(shape *s)
	{
		table[cnt] = s;
		cnt++;
	}

	Tpoint* findpoint(int x, int y)
	{
		double min = 10;
		int indx = -1;
		Tpoint *pnt = NULL;
		for (int i = 0; i < cnt; i++)
		{
			if (table[i]->isPoint())
			{
				int _x = ((Ipoint*)(table[i]))->p->x;
				int _y = ((Ipoint*)(table[i]))->p->y;
				double Tmin = sqrt((double)(_x - x)*(_x - x) + (_y - y)*(_y - y));
				if (Tmin < min)
				{
					indx = i;
					min = Tmin;
					pnt = ((Ipoint*)(table[i]))->p;
					pnt->x = _x;
					pnt->y = _y;
				}
			}
		}
		if (indx > 0)
			return pnt;
		else return NULL;
	}


	Iline *findline(int _x, int _y)
	{
		double min = 10;
		int indx = -1;
		Iline *pnt = NULL;
		for (int i = 0; i < cnt; i++)
		{
			if (table[i]->isPoint())
				continue;
			if (table[i]->isLine())
			{
				int x1 = ((Iline*)(table[i]))->l->x;
				int y1= ((Iline*)(table[i]))->l->y;
				int x2 = ((Iline*)(table[i]))->r->x;
				int y2 = ((Iline*)(table[i]))->r->y;
				double Tmin1 = sqrt((double)(x1 - _x)*(x1 - _x) + (y1 - _y)*(y1 - _y));
				double Tmin2 = sqrt((double)(x2 - _x)*(x2 - _x) + (y2 - _y)*(y2 - _y));
				if (Tmin1 < min || Tmin2<min)
				{
					indx = i;
					pnt = ((Iline*)(table[i]));
				}
			}
		}
		if (indx > 0)
			return pnt;
		else return NULL;
	}

	int findindx(Tpoint *tmp)
	{
		int indx = -1;
		for (int i = 0; i < cnt; i++)
		{
			if (table[i]->isPoint())
			{
				if (tmp == ((Ipoint*)(table[i]))->p)
				{
					indx = i;
					break;
				}
			}
		}
		if (indx < 0)
			throw"error";
		else return indx;
	}

	void show(Graphics ^g)
	{
		for (int i = 0; i < cnt; i++)
		{
			table[i]->Show(g);
		}
	}

	void insert(Tpoint *pnt, int _x, int _y)//исправить
	{
		int indx = findindx(pnt);
		shape *s;
		Tpoint *pnt2 = NULL;
		pnt2->x = _x;
		pnt2->y = _y;
		if (table[indx]->isPoint())
		{
			((Iline*)table[indx])->l = pnt;
			((Iline*)table[indx])->r = pnt2;
		}
		if (table[indx]->isLine())
		{
			add(s);
            ((Iline*)(table[cnt - 1]))->l=pnt;
			((Iline*)(table[cnt - 1]))->r = pnt2;
		}

	}

	void delline(Iline *l, Graphics ^g)
	{
		for (int i = 0; i < cnt; i++)
		{
			if (table[i]->isPoint())
				continue;
			if (table[i]->isLine())
			{
				if (((Iline*)(table[i])) == l)
					l->Hide(g);
			}
		}
	}

	void delpoint(int x, int y,Graphics ^g)
	{
		Tpoint *p = findpoint(x, y);
		Iline *ln;
		int k = findindx(p);
		if (table[k]->isPoint())
			table[k]->Hide(g);
		if (k == cnt - 1)
			return;
		for (int i = k; i < cnt; i++)
		{
			if (table[i]->isLine())
			{
				ln = ((Iline*)(table[i]));
				if ((ln->l->x == x && ln->l->y == y) || (ln->r->x == x && ln->r->y == y))
				{
					table[i] = table[i + 1];
					cnt--;
				}
			}
		}
	}

	void draw(Panel ^p)
	{

		Graphics^ r = p->CreateGraphics();  
		int y = 10;
		Font^ f = gcnew Font("Arial", 10);
		for (int i = 0; i < cnt; i++)
		{
			if (table[i]->isPoint())
			{
				String^ s = "x=" + ((Ipoint*)(table[i]))->p->x.ToString() + " y=" + ((Ipoint*)(table[i]))->p->y.ToString();
				r->DrawString(s, f, Brushes::Black, 10, y);
				y = y + 15;
			}
		}
	}
//удаление
};