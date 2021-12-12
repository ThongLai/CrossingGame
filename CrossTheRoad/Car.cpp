#include "Car.h"
#include <iostream>
#include <string>
#include "Window.h"
using namespace std;

Car::Car() : CVEHICLE()
{
	vehicle_table = table;

	height = sizeof(table) / sizeof(string);
	width = table[0].size();

	text_color = LIGHTCYAN;
	bg_color = BLACK;
}

Car::Car(int x, int y, int text_color, int bg_color) : Car()
{
	mX = x;
	mY = y;

	this->text_color = text_color;
	this->bg_color = bg_color;
}

Car::Car(const Car& v) : Car()
{
	mX = v.mX;
	mY = v.mY;
}

Car::~Car()
{}

void Car::Move()
{
	//RemoveMoving will set direction for object and delete the shape at the old position
	RemoveMoving(true);
	
	//Increase x position by 1 unit
	mX++;

	//If the object come to the end of the line => start again at 0
	if (mX == GAMEPLAY_W)
		mX = 0;

	//Draw the object after RemoveMoving
	Draw();
}

void Car::Tell()
{
	// Play impact sound when Car impact with Player
	mciSendString(TEXT("play Car_Crash from 0"), NULL, 0, NULL);
}


bool Car::isImpact(int x, int y)
{
	//	x, y will be the position of Player
	//	So use x,y to check each character in the shape of the object 
	//	If x,y is in the shape of the object => impact occurs 
	if ((y == Y() + 1) && (x + 1 == X() - 1)) {
		return false;
	}
	if ((y == Y() + 1) && (x + 1 == X() + 15)) {
		return false;
	}
	if (x + 2 <= X() - 1 || x >= X() + 15 || y + 3 <= Y() || y >= Y() + 3) return false;
	else
	{
		if ((y + 2 == Y()) && (x + 2 < X() + 2)) return false;
		else if ((y + 2 == Y()) && (x >= X() + 12)) {
			return false;
		}
		else if ((y == Y() + 2) && (x + 1 <= X())) {
			return false;
		}
		else if ((y == Y() + 2) && (x + 1  != X() + 1 && x + 1 != X() + 12)) {
			return false;
		}
		else if ((y == Y() + 2) && (x >= X() + 13)) {
			return false;
		}
	}
	return true;
}