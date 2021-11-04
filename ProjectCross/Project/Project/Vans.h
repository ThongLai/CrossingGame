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

public:

	Vans();
	Vans(int,int);

	int X();
	int Y();

	void setX(int _x);
	void setY(int _y);

	void initDraw();
	
};

