#pragma once
#include "ConsoleTask.h"

class Bird
{
private:
	/*const int table[5][15] = { 219, 219, 219, 219, 32, 32, 219, 219, 223, 32, 32, 219, 219, 219, 219,
							   219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219,
							   219, 219, 219, 32, 219, 219, 219, 219, 219, 219, 219, 32, 219, 219, 219,
							   219, 219, 32, 32, 32, 32, 219, 219, 219, 32, 32, 32, 32, 219, 219,
							   219, 32, 32, 32, 32, 32, 32, 219, 32, 32, 32, 32, 32, 32, 219 };*/

	string table[5] =
	{
		"      /'{>     ",
		"  ____) (____  ",
		" //'-;   ;-'\\\\ ",
		"//////\\_/\\\\\\\\\\\\",
		"      m m      ",
	};

	int x, y;
public:
	Bird(int, int);

	int X() { return x; }
	int Y() { return y; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void initDraw();
	void drawMoveLeft();
	void drawMoveRight();
	void drawMove() {};
	bool isImpact(int, int);
};