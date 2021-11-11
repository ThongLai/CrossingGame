#pragma once
#include<string>
using namespace std;


class Vans
{
	string table[5] =
	{
		"  лпплллллллллл",
		"ллллллллллллллл",
		"ллллллллллллллл",
		"ллллллллллллллл",
		"O             O"
	};

	int x;
	int y;
	int height;
	int width;

public:

	Vans();
	Vans(int,int);

	int X();
	int Y();
	int H();
	int W();

	void setX(int _x);
	void setY(int _y);
	void setH(int _h);
	void setW(int _w);

	void initDraw();
	
	bool isImpact(int,int);

	void moveLeft();
};

