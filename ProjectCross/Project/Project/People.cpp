#include"ConsoleTask.h"
#include"People.h"
#include<iostream>
#include<string>

using namespace std;

People::People()
{
	x = 20; 
	y = 20;
	state = 1;
}

int People::X()
{
	return x;
}

int People::Y()
{
	return y;
}

void People::setX(int _x)
{
	x = _x;
}

void People::setY(int _y)
{
	y = _y;
}

void People::initDraw()
{
	int temp = y;

	for (int i = 0; i < 3; i++)
	{
		ConsoleTask::gotoXY(x, y, table[i]);
		y++;
		cout << endl;
	}

	y = temp;
}

void People::Clear()
{
	x = X();
	y = Y();

	int temp = y;

	for (int i = 0; i < 3; i++)
	{
		ConsoleTask::gotoXY(x, y, "   ");
		y++;
		cout << endl;
	}

	y = temp;
}

void People::UP()
{
	Clear();
	setY(y - 1);
	initDraw();
}

void People::DOWN()
{
	Clear();
	setY(y + 1);
	initDraw();
}

void People::LEFT()
{
	Clear();
	setX(x - 1);
	initDraw();
}

void People::RIGHT()
{
	Clear();
	setX(x + 1);
	initDraw();
}