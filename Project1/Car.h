#pragma once
#include<string>
using namespace std;

class Car
{
	string CAR[3] =
	{
		"  млппплпплм   ",
		"ллллллллллллллл",
		" O          O  ",
	};

	int x;
	int y;
	int height;
	int width;

public:

	Car();
	Car(int, int);

	int X();
	int Y();
	int H();
	int W();

	void setX(int _x);
	void setY(int _y);
	void setH(int _h);
	void setW(int _w);

	void initDraw();

	bool isImpact(int, int);

	void move();
};
