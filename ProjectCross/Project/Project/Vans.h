#pragma once
#include<string>
using namespace std;


class Vans
{
	string table[5] =
	{
		"  �������������",
		"���������������",
		"���������������",
		"���������������",
		"O             O"
	};

	int x;
	int y;

public:

	Vans();
	Vans(int,int);

	int X();
	int Y();

	void setX(int _x);
	void setY(int _y);

	void initDraw();
	
};

