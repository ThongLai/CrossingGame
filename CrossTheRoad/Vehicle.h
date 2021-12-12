#pragma once

#include "Window.h"

class CVEHICLE
{
protected:
	//Current position of objects (x,y) <-> (mX, mY)
	int mX, mY;

	//Height and width of objects
	int height, width;

	//Color of objects
	int text_color, bg_color;

	//An one dimensional array that keeps the shape of 
	//the vehicle objects (Car or Van).
	string* vehicle_table;

public:
	//Constructor and Destructor 
	CVEHICLE();
	~CVEHICLE();

	//Draw method is used for draw Vehicle shape 
	//at its position (mX, mY).
	virtual void Draw();

	//Remove method is used for remove Vehicle shape
	//at its position (mX, mY).
	virtual void Remove();

	//Move method is used for draw moving animation for Vehicle.
	//Move is a pure virtual method for class Vehicle because 
	//Car and Van will have their own Move method.
	virtual void Move() = 0;

	//Tell method is used for play a sound when Player - Vehicle(Car or Van) impact occurs
	//Tell is a pure virtual method because Car and Van will have their own Tell method
	virtual void Tell() = 0;

	//Remove object animation (go to the end of the lane) and
	//set direction for objects, better UX for user
	virtual void RemoveMoving(bool);

	//Getter of some properties
	int X();
	int Y();
	int getHeight();
	int getWidth();
	string* getFigure();

	//Setter of some properties
	void setX(int);
	void setY(int);
	void setXY(int, int);
	void setColor(int, int);
};