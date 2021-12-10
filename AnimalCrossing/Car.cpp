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
	RemoveMoving(true);

	//Remove();

	mX++;
	if (mX == GAMEPLAY_W)
		mX = 0;

	Draw();
}

void Car::Tell()
{
	mciSendString(TEXT("play Car_Crash from 0"), NULL, 0, NULL);
}

void Car::SurroundingSound()
{
	mciSendString(TEXT("play Car_SD from 0"), NULL, 0, NULL);
}

bool Car::isImpact(int x, int y)
{
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