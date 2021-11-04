#include "Vans.h"
#include <iostream>
#include <string>
#include "ConsoleTask.h"
using namespace std;

Vans::Vans()
{
	x = 50;
	y = 50;
}

Vans::Vans(int _x, int _y)
{
	x = _x;
	y = _y;
}

int Vans::X()
{
	return x;
}

int Vans::Y()
{
	return y;
}

void Vans::setX(int _x)
{
	x = _x;
}

void Vans::setY(int _y)
{
	y = _y;
}

void Vans::initDraw()
{
	int temp = y;

	for (int i = 0; i < 5; i++)
	{
		ConsoleTask::gotoXY(x, y);
		cout << table[i];
		y++;

		cout << endl;
	}
	
	y = temp;
}