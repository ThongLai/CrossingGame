#include "Car.h"
#include <iostream>
#include <string>
#include "Window.h"
using namespace std;



Car::Car()
{
	x = 0;
	y = 0;

	height = sizeof(CAR) / sizeof(string);

	int max_width = CAR[0].size();
	for (int i = 0; i < height; i++)
		if (max_width < CAR[i].size())
			max_width = CAR[i].size();

	width = max_width;
}

Car::Car(int _x, int _y) : Car()
{
	x = _x;
	y = _y;
}

int Car::X()
{
	return x;
}

int Car::Y()
{
	return y;
}

void Car::setX(int _x)
{
	x = _x;
}

void Car::setY(int _y)
{
	y = _y;
}

void Car::initDraw()
{
	int temp = y;

	for (int i = 0; i < 3; i++)
	{
		ConsoleTask::gotoXY(x, y);
		cout << CAR[i];
		y++;
		cout << endl;
	}

	y = temp;
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