#include "Trafficlight.h"

void Trafficlight::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}

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
	Status SavedStatus;

	if (state==1)
	{
		SetTextColor(DefineColor(LIGHTGREEN, BLACK));
		GotoXY(x, y);
		cout << char(219);

		SetTextColor(DefineColor(DARKGRAY, BLACK));
		GotoXY(x+1, y);
		cout << char(219);
	}
	else
	{
		SetTextColor(DefineColor(RED, BLACK));
		GotoXY(x, y);
		cout << char(219);

		SetTextColor(DefineColor(DARKGRAY, BLACK));
		GotoXY(x + 1, y);
		cout << char(219);
	}
}

void Trafficlight::changeLight()
{
	Status SavedStatus;

	if (state)
	{
		SetTextColor(DefineColor(RED, BLACK));
		GotoXY(x, y);
		cout << char(219);

		SetTextColor(DefineColor(DARKGRAY, BLACK));
		GotoXY(x + 1, y);
		cout << char(219);

		state = 0;
	}
	else
	{
		SetTextColor(DefineColor(DARKGRAY, BLACK));
		GotoXY(x, y);
		cout << char(219);

		SetTextColor(DefineColor(LIGHTGREEN, BLACK));
		GotoXY(x + 1, y);
		cout << char(219);

		state = 1;
	}
}