#pragma once
#include"IPoint.h"
#include"Ishape.h"
#include"ILine.h"
#include"stack.h"

class Plex:public Ishape
{
public:
	Ishape *root;
	Plex()
	{
		root=NULL;
	}
	bool isPoint(Ishape *obj)
	{

	}
	bool isLine(Ishape *obj)
	{

	}
	bool isCircle(Ishape *obj)
	{

	}
	void addfig(Ishape *obj)
	{
	}
	Ipoint* searchpoint(int x, int y)
	{
	}
	ILine* searchline(int x, int y)
	{

	}
	void delpoint(int x, int y)
	{

	}
	void delLine()
	{

	}
};