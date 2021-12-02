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

	void setColor(int _text_color, int _bg_color);

	void Draw();
	void Remove();
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();

	bool isDead();

	void drawDead();
	
	template<class T>
	bool isImpact(vector<T> v)
	{
		for (int i = 0; i < v.size(); ++i)
			if (v[i].isImpact(mX, mY))
			{
				mState = 0;
				return true;
			}
		return false;
	}
};