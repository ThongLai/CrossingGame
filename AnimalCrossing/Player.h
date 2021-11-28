#pragma once

#include "Window.h"
#include"Menu.h"

class Player
{
	int mX, mY;
	int height, width;
	int text_color, bg_color;

	bool mState;	//1 is alive - 0 is dead
	string table[3]= {
	 "  ",
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

	void Draw();
	void Remove();
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();

	bool isDead();

	bool drawDead();
	
	template<class T>
	bool isImpact(vector<T> v, int objNum)
	{
		for (int i = 0; i < objNum; ++i)
			if (v[i].isImpact(mX, mY))
			{
				mState = 0;
				return true;
			}
		return false;
	}
};