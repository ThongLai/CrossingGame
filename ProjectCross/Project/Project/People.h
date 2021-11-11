#pragma once
#include<string>
using namespace std;

class People
{
	int x, y;
	bool state;//1:live ; 0:die

	string table[3]= {
	 " ",
	 "ÄÛÄ",
	"/ \\"
	};


public:

	People();

	int X();
	int Y();

	void setX(int);
	void setY(int);

	void initDraw();
	void Clear();
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	bool isDead();

};