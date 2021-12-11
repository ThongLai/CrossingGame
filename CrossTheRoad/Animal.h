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
	virtual void Tell() = 0;
	virtual bool isImpact(int,int) = 0;
	virtual void RemoveMoving(bool);
	virtual void SurroundingSound() = 0;


	int X();
	int Y();
	int getHeight();
	int getWidth();
	string* getFigure();

	void setX(int);
	void setY(int);
	void setXY(int, int);
	void setColor(int, int);
};