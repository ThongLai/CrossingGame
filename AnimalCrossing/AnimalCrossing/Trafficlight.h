#pragma once

#include "Window.h"

class Trafficlight
{
	int x, y;
	bool state;// 1: green ; 0: red
public:

	Trafficlight();
	Trafficlight(int, int, bool);

	void initDraw();
	void changeLight();
};