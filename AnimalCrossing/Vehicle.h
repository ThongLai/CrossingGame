#pragma once

#include "Window.h"

class CVEHICLE
{
protected:
	int mX, mY;
	int height, width;
	int text_color, bg_color;
	string *car_table;

public:
	CVEHICLE();
	~CVEHICLE();

	//Moving pattern for each vehicle
	virtual void Move() = 0;
	virtual void Tell();
	virtual void Draw();
	virtual void Remove();

	int X();
	int Y();
	int getHeight();
	int getWidth();

	void setX(int);
	void setY(int);
	void setXY(int, int);
	void setColor(int, int);
};