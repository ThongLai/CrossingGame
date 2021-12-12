#pragma once

#include "Window.h"

class CANIMAL
{
protected:
	//Current position of objects (x,y) <-> (mX, mY)
	int mX, mY;

	//Height and width of objects
	int height, width;

	//Color of objects
	int text_color, bg_color;

	//An one dimensional array that keeps the shape of the vehicle objects (Alien or Bird)
	string *animal_table;

public:
	//Constructor and Destructor 
	CANIMAL();
	~CANIMAL();

	//Draw method is used for draw Animal picture at its position (mX, mY) - virtual method 
	virtual void Draw();

	//Remove method is used for remove Animal picture at its position (mX, mY) - virtual method
	virtual void Remove();

	//Move method is used for draw moving animation for Animal
	//Move is a pure virtual method for class Vehicle because Alien and Bird will have their own Move method 
	virtual void Move() = 0;

	//Tell method is used for play a sound when Player - Vehicle(Alien or Bird) impact occurs
	//Tell is a pure virtual method because Alien and Bird will have their own Tell method
	virtual void Tell() = 0;


	//Remove object animation (go to the end of the lane) and set direction for objects
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