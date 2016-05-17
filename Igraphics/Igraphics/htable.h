#pragma once
#include"Gtable.h"

using namespace std;

struct node
{
	Tpoint *p;
	int hkey;
	node *next;
};

class htable
{
	int cnt;
	node **table;
public:
	htable(int _cnt = 0) : cnt(_cnt)
	{
		table = new node*[100];
		for (int i = 0; i < 100; i++)
			table[i] = NULL;
			
	}
	~htable()
	{
		for (int i = 0; i < 100; i++)
			delete table[i];
		delete[]table;
	}

	int gethkey(Ipoint *pn)
	{
		return((pn->getbasepoint()->x + pn->getbasepoint()->y) % 100);
	}

	void addpoint( Ipoint *pnt)
	{
		node *obj = new node;
			obj->next = NULL;
			obj->hkey = gethkey(pnt);
			obj->p = pnt->getbasepoint();
			table[cnt] = obj;
			cnt++;

	}
	void add(Ipoint *p1, Tpoint *pn)
	{
		node *obj = new node;
		obj->next = NULL;
		obj->hkey = gethkey(p1);
		obj->p = pn;
		int index = findkey(gethkey(p1));
		if (index<0)
			throw"dont add point";
		else
		{
			
			if (table[index] == NULL)
			{
				table[index] = obj;
			}
			else
			{
				node *d = table[index];
				while (d->next != NULL)
				{
					d = d->next;
				}
				d->next = obj;
			}

		}

	}
	int findkey(int hkey)
	{
		int indx=-1;
		for (int i = 0; i < cnt; i++)
		{
			if (table[i]->hkey == hkey)
			{
				indx = i;
				break;
			}
		}
		return indx;
	}
	node* findpoint(int key,Tpoint *tp)
	{
		int indx = findkey(key);
		node *t = table[indx];
		while (t->p != tp)
			t = t->next;
		return t;
	}
	void delTpoint(Ipoint *p1, Tpoint *tp)
	{
		int indx = findkey(gethkey(p1));
		node *t = table[indx];
		node *cur = findpoint(gethkey(p1), tp);
		while (t->next!= cur)
			t = t->next;
		t->next = cur->next;
		delete cur;
	}
	void delIpoint(Ipoint *p1)
	{
		int indx = findkey(gethkey(p1));
		node *t = table[indx];
		table[indx] = table[cnt - 1];
		table[cnt-1] = t;
		delete table[cnt - 1];
		cnt--;

	}
	void show(Panel ^p1,Panel ^p2)
	{

		Graphics^ r = p1->CreateGraphics();
		Graphics^ p = p2->CreateGraphics();
		int y = 10;
		Font^ f = gcnew Font("Arial", 10);
		for (int i = 0; i < cnt; i++)
		{
			node *t = table[i]->next;
			while (t != NULL)
			{
				String^ s = "x=" + t->p->x.ToString() + " y=" + t->p->y.ToString();
				r->DrawString(s, f, Brushes::Black, 10, y);
				y = y + 15;
				t = t->next;
			}
			String^ s1 = "x=" + table[i]->p->x.ToString() + " y=" + table[i]->p->y.ToString();
			r->DrawString(s1, f, Brushes::Black, 10, y);
			y = y + 15;
		}
	}
};