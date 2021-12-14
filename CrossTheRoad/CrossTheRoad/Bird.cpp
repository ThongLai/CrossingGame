#include"Bird.h"

bool Bird::direct = true;
int Bird::count = 0;

Bird::Bird() : CANIMAL()
{
	animal_table = table;

	height = sizeof(table) / sizeof(string);
	width = table[0].size();

	text_color = BROWN;
	bg_color = BLACK;
}

Bird::Bird(int x, int y, int text_color, int bg_color) : Bird()
{
	mX = x;
	mY = y;

	this->text_color = text_color;
	this->bg_color = bg_color;
}

Bird::Bird(const Bird& b) :Bird()
{
	mX = b.mX;
	mY = b.mY;
}

Bird::~Bird()
{
}

bool Bird::getDirect()
{
	return direct;
}

int Bird::getCount()
{
	return count;
}

void Bird::setDirect(bool b)
{
	direct = b;
}

void Bird::setCount(int i)
{
	count = i;
}

void Bird::Turn() 
{
	direct = !direct;
}

void Bird::Move() 
{
	//RemoveMoving will set direction for object and delete the shape at the old position
	RemoveMoving(direct); 
	
	if (direct) // We have to check direction before moving
	{
		++mX; // If the direction is right 
		++count; // Update number of steps 
		if (mX == GAMEPLAY_W) // If object goes to the end of the line, back to 0
			mX = 0;
	}
	else //Tuong tu o tren, direct = false => qua trai
	{
		--mX; // If the direction is left 
		++count;
		if (mX < 0) // If object goes to the start of the line, come to the end
			mX = GAMEPLAY_W - 1;
	}

	//Draw the object after RemoveMoving
	Draw(); 
}

bool Bird::isImpact(int x, int y) 
{	
	//	x, y will be the position of Player
	//	So use x,y to check each character in the shape of the object 
	//	If x,y is in the shape of the object => impact occurs 
	if (x <= X() - 3 || x >= X() + 15 || y <= Y() - 3 || y >= Y() + 5) return false;
	else
	{	
		if (y == Y() + 4)
		{
			if (x <= X() + 3 || x >= X() + 9) return false;
			else return true;
		}

		if (y == Y() + 3) return true;

		if (y == Y() + 2) return true;

		if (y == Y() + 1) return true;

		if (y == Y())
		{
			if (x <= X() - 2 || x >= X() + 14) return false;
			else return true;
		}

		if (y == Y() - 1)
		{
			if (x <= X() - 1 || x >= X() + 13) return false;
			else return true;
		}


		if (y == Y() - 2)
		{
			if (x <= X() + 3 || x >= X() + 10) return false;
			else return true;
		}	
	}
}

void Bird::Tell()
{
	// Play impact sound when Bird impact with Player
	mciSendString(TEXT("play Bird_Crash from 0"), NULL, 0, NULL);
}
