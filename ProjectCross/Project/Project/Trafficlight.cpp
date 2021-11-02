#include "Trafficlight.h"
#include<iostream>
#include<string>
#include"ConsoleTask.h"
using namespace std;

Trafficlight::Trafficlight()
{
	x = 50;
	y = 50;
	state = 1;
}

Trafficlight::Trafficlight(int _x, int _y, bool _state)
{
	x = _x;
	y = _y;
	state = _state;
}

void Trafficlight::initDraw()
{
	if (state==1)
	{
		ConsoleTask::gotoXY(x, y, char(219), 10);
		ConsoleTask::gotoXY(x+1, y, char(219), 8);
	}
	else
	{
		ConsoleTask::gotoXY(x, y, char(219), 4);
		ConsoleTask::gotoXY(x + 1, y, char(219), 8);
	}
}

void Trafficlight::changeLight()
{
	if (state)
	{
		ConsoleTask::gotoXY(x, y, char(219), 4);
		ConsoleTask::gotoXY(x + 1, y, char(219), 8);
		state = 0;
	}
	else
	{
		ConsoleTask::gotoXY(x, y, char(219), 8);
		ConsoleTask::gotoXY(x + 1, y, char(219), 10);
		state = 1;
	}
}