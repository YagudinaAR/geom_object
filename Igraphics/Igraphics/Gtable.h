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

	shape* findpoint(Tpoint *p)
	{

		shape *pnt = NULL;
		for (int i = 0; i < cnt; i++)
		{
			if(table[i]->cmp1(*p))//if (table[i]->getbasepoint()->compare(*p))
			{
				pnt = table[i];
				break;
			}
		}
		return pnt;
	}




	void show(Graphics ^g)
	{
		for (int i = 0; i < cnt; i++)
		{
			table[i]->Show(g);
		}
	}

	void del(Tpoint *tp)
	{
		for (int i = 0; i < cnt; i++)
		{
			if (table[i]->cmp1(*tp))
			{
				shape *s = table[i];
				table[i] = table[cnt - 1];
				table[cnt - 1] = s;
				delete table[cnt - 1];
				cnt--;
				if (i != 0)
					i--;
			}
		}
	}

	/*void draw(Panel ^p)
	{

		Graphics^ r = p->CreateGraphics();
		int y = 10;
		Font^ f = gcnew Font("Arial", 10);
		for (int i = 0; i < cnt; i++)
		{
			if (table[i]->getbasepoint())
			{
				String^ s = "x=" + ((Ipoint*)(table[i]))->getbasepoint()->x.ToString() + " y=" + ((Ipoint*)(table[i]))->getbasepoint()->y.ToString();
				r->DrawString(s, f, Brushes::Black, 10, y);
				y = y + 15;
			}
		}
	}*/

};