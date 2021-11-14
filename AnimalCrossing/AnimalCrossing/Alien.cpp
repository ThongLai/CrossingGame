#include "Alien.h"

Alien::Alien() : CANIMAL()
{
	animal_table = table;
	height = sizeof(table) / sizeof(string);
	width = table[2].size();
}

Alien::Alien(int x, int y) : Alien()
{
	mX = x;
	mY = y;
}

Alien::~Alien()
{

}

void Alien::Move(int x, int y)
{
	Remove();

	if (mX < x) mX++;
	else if (mX > x) mX--;

	if (mY < y) mY++;
	else if (mY > y) mY--;

	Draw();
}