#pragma once PEOPLE_H_
#include "Window.h"

class People
{
	int mX, mY;
	int height, width;
	int text_color, bg_color;

	bool mState;	//1 is alive - 0 is dead
	string PEOPLE[3]= {
	 " ",
	 "ÄÛÄ",
	"/ \\"
	};


public:

	People();
	~People();

	int X();
	int Y();

	void setX(int);
	void setY(int);
	void setXY(int x, int y);

	void draw();
	void remove();
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	bool isDead();

};