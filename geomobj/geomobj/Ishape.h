//абстрактный базовый класс объектов
#pragma once
#include<iostream>
using namespace System::Drawing;
using namespace std;

class Ishape
{
protected:
	bool Active;
	bool Visible;

public:
	Ishape(bool v = true,bool n=false)
	{
		Active = v;
		Visible = n;
	}
	void setActive(bool n = true)
	{
		Active = n;
	}
	void setVisible(bool v = false)
	{
		Visible = v;
	}
	bool IsVisible()
	{
		return Visible;
	}
	bool IsActive()
	{
		return Active;
	}
	virtual void show(Graphics ^g) = 0;//показать объект
	virtual void hide(Graphics ^g) = 0;//скрыть
	virtual void move(Graphics ^g,int X, int Y) = 0;//двигать
};
