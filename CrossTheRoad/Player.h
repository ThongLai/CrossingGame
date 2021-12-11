#pragma once

#include "Window.h"

class Player
{
private:
	int mX, mY;
	int height, width;
	int text_color, bg_color;

	bool mState;	//1 is alive - 0 is dead
	string table[3]= {
	 "  ",
	 "���",
	 "/ \\"
	};

public:

	Player();
	Player(int x, int y, int text_color = WHITE, int bg_color = BLACK);
	~Player();

	int X();
	int Y();
	int getHeight();
	int getWidth();

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
				v[i].Tell();
				return true;
			}
		return false;
	}
};