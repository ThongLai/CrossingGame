#include "Van.h"

Van::Van() : CVEHICLE()
{
	vehicle_table = table;

	height = sizeof(table) / sizeof(string);
	width = table[0].size();

	text_color = BLUE;
	bg_color = BLACK;
}

Van::Van(int x, int y, int text_color, int bg_color) : Van()
{
	mX = x;
	mY = y;

	this->text_color = text_color;
	this->bg_color = bg_color;
}

Van::Van(const Van& v) :Van()
{
	mX = v.mX;
	mY = v.mY;
}

Van::~Van()
{}

void Van::Move()
{
	//RemoveMoving will set direction for object and delete the shape at the old position
	RemoveMoving(false);

	//Increase x position by 1 unit
	mX--;

	//If the object come to the end of the line => start again at 0
	if (mX < 0)
		mX = GAMEPLAY_W - 1;

	//Draw the object after RemoveMoving
	Draw();
}


bool Van::isImpact(int x, int y)
{
	//	x, y will be the position of Player
	//	So use x,y to check each character in the shape of the object 
	//	If x,y is in the shape of the object => impact occurs 
	if (x <= X() - 3 || x >= X() + 15 || y <= Y() - 3 || y >= Y() + 5) return false;
	else 
	{
		if (y == Y() - 2)
		{
			if (x == X() - 1 || x == X() - 2) return false;
			else return true;
		}

		if (y == Y() - 1) return true;

		if (y == Y()) return true;

		if (y == Y() + 1) return true;

		if (y == Y() + 2) return true;

		if (y == Y() + 3) return true;
		
		if (y == Y() + 4)
		{
			if (x == X() - 1 || x == X() + 13) return true;
			else return false;
		}
	}
	return true;
}

void Van::Tell()
{
	// Play impact sound when Van impact with Player
	mciSendString(TEXT("play Van_Crash from 0"), NULL, 0, NULL);
}
