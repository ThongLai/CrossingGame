#include "Alien.h"

bool Alien::direct = true;
int Alien::count = 0;

Alien::Alien() : CANIMAL()
{
	animal_table = table;

	height = sizeof(table) / sizeof(string);
	width = table[0].size();
}

Alien::Alien(int x, int y) : Alien()
{
	mX = x;
	mY = y;
	count = 0;
}

Alien::Alien(const Alien& a) :Alien()
{
	mX = a.mX;
	mY = a.mY;
}

Alien::~Alien()
{
}

//void Alien::Move(int x, int y)
//{
//	Remove();
//
//	if (mX < x) mX++;
//	else if (mX > x) mX--;
//
//	if (mY < y) mY++;
//	else if (mY > y) mY--;
//
//	Draw();
//}

void Alien::Turn()
{
	if (direct == true)
		direct = false;
	else direct = true;
}

void Alien::Move()
{
	//Xoa object
	RemoveMoving(direct);

	if (direct)
	{
		++mX;
		++count;
		if (mX == GAMEPLAY_W) //Neu toi bien phai, gan toa do X = 0
			mX = 0;
	}
	else
	{
		--mX;
		++count;
		if (mX < 0)
			mX = GAMEPLAY_W - 1;
	}

	Draw();
}

bool Alien::isImpact(int x, int y)
{
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