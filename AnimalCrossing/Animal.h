#pragma once

#include "Window.h"

class CANIMAL
{
protected:
	int mX, mY;
	int height, width;
	int text_color, bg_color;
	string *animal_table;

	

public:
	CANIMAL();
	~CANIMAL();

	//Moving pattern for each animal
	virtual void Move() = 0;
	virtual void Draw();
	virtual void Remove();
	virtual void Tell();
	virtual bool isImpact(int,int) = 0;

	int X();
	int Y();
	int getHeight();
	int getWidth();
	
	void setX(int);
	void setY(int);
	void setXY(int, int);
	void setColor(int, int);
};