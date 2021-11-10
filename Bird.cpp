#include"Bird.h"

Bird::Bird(int x, int y)
{
	setX(x);
	setY(y);
}

void Bird::initDraw()
{
	int x = X();
	int y = Y();
	ConsoleTask::ConsoleTask::gotoXY(x, y);
	for (int i = x; i <= x + 14; ++i)
	{
		for (int j = y; j <= y + 4; ++j)
		{
			ConsoleTask::gotoXY(i, j, char(table[j - y][i - x]));
		}
	}
}

void Bird::drawMoveLeft()
{
	setX(X() - 1);
	int x = X();
	int y = Y();
	
	if (x == -1)
	{
		x = 124;
		setX(x);
	}
	
	if (x + 14 >= 124)
	{
		//Xoa
		for (int j = y; j <= y + 4; ++j)
		{
			ConsoleTask::gotoXY(x + 15 - 125, j, char(32));
		}

		//Them
		int count = 0;
		for (int i = x; i <= 124; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				ConsoleTask::gotoXY(i, j, char(table[j - y][i - x]));
			}
			++count;
		}

		for (int i = 0; i < x + 14 - 124; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				ConsoleTask::gotoXY(i, j, char(table[j - y][count]));
			}
			++count;
			if (count > 14)
				break;
		}
		
	}
	else
	{
		//Xoa
		for (int j = y; j <= y + 4; ++j)
		{
			ConsoleTask::gotoXY(x + 15, j, char(32));
		}

		//Them
		for (int i = x; i <= x + 14; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				ConsoleTask::gotoXY(i, j, char(table[j - y][i - x]));
			}
		}
	}
}
		
void Bird::drawMoveRight()
{
	setX(X() + 1);
	int x = X();
	int y = Y();

	if (x == 125)
	{
		x = 0;
		setX(x);
	}

	if (x + 14>= 124)
	{
		//Xoa
		for (int j = y; j <= y + 4; ++j)
		{
			ConsoleTask::gotoXY(x - 1, j, char(32));
		}

		//Them
		int count = 0;
		for (int i = x; i <= 124; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				ConsoleTask::gotoXY(i, j, char(table[j - y][i - x]));
			}
			++count;
		}

		for (int i = 0; i < x + 14 - 124; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				ConsoleTask::gotoXY(i, j, char(table[j - y][count]));
			}
			++count;
			if (count > 14)
				break;
		}

	}
	else
	{
		//Xoa
		for (int j = y; j <= y + 4; ++j)
		{
			if (x == 0)
			{
				ConsoleTask::gotoXY(124, j, char(32));
			}
			else ConsoleTask::gotoXY(x - 1, j, char(32));
			
		}

		//Them
		for (int i = x; i <= x + 14; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				ConsoleTask::gotoXY(i, j, char(table[j - y][i - x]));
			}
		}
	}
}
