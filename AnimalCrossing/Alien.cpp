#include "Alien.h"

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
}

Alien::~Alien()
{

}

void Alien::Move()
{
	Remove();

	Draw();
}