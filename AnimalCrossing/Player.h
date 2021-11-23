#pragma once

#include "Window.h"

class Player
{
	int mX, mY;
	int height, width;
	int text_color, bg_color;

	bool mState;	//1 is alive - 0 is dead
	string table[3]= {
	 " ",
	 "ÄÛÄ",
	"/ \\"
	};


public:

	Player();
	~Player();

	int X();
	int Y();

	void setX(int);
	void setY(int);
	void setXY(int x, int y);

	int getHeight();
	int getWidth();

	void Draw();
	void Remove();
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	bool isDead();
};