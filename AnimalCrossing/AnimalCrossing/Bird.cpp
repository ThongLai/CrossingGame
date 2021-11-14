#include"Bird.h"

Bird::Bird() : CANIMAL(), direct(true), round(3)
{
	animal_table = table;
	height = sizeof(table) / sizeof(string);
	width = table[0].size();
}

Bird::Bird(int x, int y) : Bird()
{
	mX = x;
	mY = y;
}

Bird::~Bird()
{
	
}

void Bird::Move(int x, int y)
{
	int curr_round = 0;

	while(PLAYGAME)
	{
		Remove();

		if (direct)
			mX++;
		else
			mX--;

		if (mX >= GAMEPLAY_W || mX <= 0)
		{
			curr_round++;
			if (curr_round == round)
			{
				direct = !direct;
				curr_round = 0;
			}
			else
			{
				mX = direct ? 0 : GAMEPLAY_W;
			}
			setColor(rand() % 15 + 1, BLACK);
		}

		Draw();

		Sleep(20);
	}
}

bool Bird::isImpact(int x, int y)
{
	if (x <= X() - 3 || x >= X() + 15 || y <= Y() - 3 || y >= Y() + 5) return false;
	else
	{
		if (y == Y() - 2)
		{
			if (x <= X() + 3 || x >= X() + 10) return false;
			else return true;
		}

		if (y == Y() - 1)
		{
			if (x <= X() - 1 || x >= X() + 13) return false;
			else return true;
		}
		
		if (y == Y())
		{
			if (x <= X() - 2 || x >= X() + 14) return false;
			else return true;
		}

		if (y == Y() + 1) return true;

		if (y == Y() + 2) return true;

		if (y == Y() + 3) return true;

		if (y == Y() + 4)
		{
			if (x <= X() + 3 || x >= X() + 9) return false;
			else return true;
		}
	}
}