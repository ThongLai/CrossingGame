#pragma once

#include "Window.h"

class Trafficlight
{
	//Position of the Traffic Light
	int x, y;

	//State of the Traffic Light: 1: green ; 0: red
	bool state;

public:
	//Constructor
	Trafficlight();
	Trafficlight(int, int, bool);

	//Getter state 
	bool getState();

	//Setter x and y
	void setXY(int, int);
	
	//Draw the traffic light at position x, y
	void Draw();

	//Change state of the traffic light (0 -> 1), (1 -> 0) and Draw the new traffic light state at position x, y
	void changeLight();
};