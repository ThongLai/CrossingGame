#pragma once

#include "Window.h"

class CVEHICLE
{
protected:
	int mX, mY;
	int height, width;
	int text_color, bg_color;
public:
	CVEHICLE();
	~CVEHICLE();

	//Moving pattern for each vehicle
	virtual void Move(int, int) = 0;
	virtual void Tell();
	virtual void Draw() = 0;
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