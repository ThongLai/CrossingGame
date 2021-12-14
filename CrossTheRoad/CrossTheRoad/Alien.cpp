#include "Alien.h"

bool Alien::direct = true;
int Alien::count = 0;

Alien::Alien() : CANIMAL()
{
	animal_table = table;

	height = sizeof(table) / sizeof(string);
	width = table[0].size();

	text_color = LIGHTGREEN;
	bg_color = BLACK;
}

Alien::Alien(int x, int y, int text_color, int bg_color) : Alien()
{
	mX = x;
	mY = y;
	count = 0;

	this->text_color = text_color;
	this->bg_color = bg_color;
}

Alien::Alien(const Alien& a) :Alien()
{
	mX = a.mX;
	mY = a.mY;
}

Alien::~Alien()
{
}

void Alien::Turn()
{
	direct = !direct;
}

void Alien::Move()
{
	//RemoveMoving will set direction for object and delete the shape at the old position
	RemoveMoving(direct);

	if (direct) // We have to check direction before moving
	{
		// If the direction is right 
		++mX;
		++count; // Update number of steps 
		if (mX == GAMEPLAY_W) // If object goes to the end of the line, back to 0
			mX = 0;
	}
	else
	{
		// If the direction is left
		--mX;
		++count; // Update number of steps
		if (mX < 0) // If object goes to the start of the line, come to the end
			mX = GAMEPLAY_W - 1;
	}

	//Draw the object after RemoveMoving
	Draw();
}

bool Alien::isImpact(int x, int y)
{
	//	x, y will be the position of Player
	//	So use x,y to check each character in the shape of the object 
	//	If x,y is in the shape of the object => impact occurs 
	if (x <= X() - 3 || x >= X() + 17 || y <= Y() - 3 || y >= Y() + 5) return false;
	else
	{
		if (y == Y() + 4)
		{
			if (x <= X() + 2 || x >= X() + 12) return false;
			else return true;
		}

		if (y == Y() + 3)
		{
			if (x <= X() - 1 || x >= X() + 15) return false;
			else return true;
		}

		if (y == Y() + 2) return true;

		if (y == Y() + 1) return true;

		if (y == Y()) return true;

		if (y == Y() - 1)
		{
			if (x <= X() - 2 || x >= X() + 15) return false;
			else return true;
		}

		if (y == Y() - 2)
		{
			if (x <= X() + 1 || x >= X() + 13) return false;
			else return true;
		}	
	}
}

void Alien::Tell()
{
	// Play impact sound when Alien impact with Player
	mciSendString(TEXT("play Alien_Crash from 0"), NULL, 0, NULL);
}


bool Alien::getDirect()
{
	return direct;
}

void Alien::setDirect(bool b)
{
	direct = b;
}

int Alien::getCount()
{
	return count;
}

void Alien::setCount(int i)
{
	count = i;
}