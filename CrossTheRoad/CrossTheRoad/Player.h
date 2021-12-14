#pragma once

#include "Window.h"

class Player
{
private:
	//Current position of player (x,y) <-> (mX, mY)
	int mX, mY;

	//Height and width of objects
	int height, width;

	//Color of objects
	int text_color, bg_color;

	//State of player => 1 is alive - 0 is dead
	bool mState;	

	//An one dimensional array that keeps the shape of Player
	string table[3]= {
	 "  ",
	 "ÄÛÄ",
	 "/ \\"
	};

public:
	//Constructor and Destructor 
	Player();
	Player(int x, int y, int text_color = WHITE, int bg_color = BLACK);
	~Player();

	//Getter of some properties
	int X();
	int Y();
	int getHeight();
	int getWidth();

	//Setter of some properties
	void setX(int);
	void setY(int);
	void setXY(int x, int y);
	void setColor(int _text_color, int _bg_color);

	//Draw method is used for draw Player picture at its position (mX, mY)
	void Draw();

	//Draw method is used for remove Player picture at its position (mX, mY)
	void Remove();

	//Draw animation when Player go up
	void UP();

	//Draw animation when Player go down
	void DOWN();

	//Draw animation when Player go left
	void LEFT();

	//Draw animation when Player go right
	void RIGHT();

	//Check if Player dead
	bool isDead();

	//This Player's isImpact function will call the vector of obstacles isImpact 
	//function to check if the collision between Player and obstacles occurs
	template<class T>
	bool isImpact(vector<T> v)
	{
		for (int i = 0; i < v.size(); ++i)
			// We use template so this will call isImpact function of its appropriate v[i]
			if (v[i].isImpact(mX, mY)) 
			{
				mState = 0;
				v[i].Tell(); 
				// If impact, call Tell function of its appropriate v[i]
				// to make sound
				return true;
			}
		return false;
	}
};