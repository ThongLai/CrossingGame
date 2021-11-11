#include "Vans.h"
#include <iostream>
#include <string>
#include "ConsoleTask.h"
using namespace std;

Vans::Vans()
{
	x = 0;
	y = 0;

	height = sizeof(table) / sizeof(string);

	int max_width = table[0].size();
	for (int i = 0; i < height; i++)
		if (max_width < table[i].size())
			max_width = table[i].size();

	width = max_width;
}

Vans::Vans(int _x, int _y) : Vans()
{
	x = _x;
	y = _y;
}

int Vans::X()
{
	return x;
}

int Vans::Y()
{
	return y;
}

void Vans::setX(int _x)
{
	x = _x;
}

void Vans::setY(int _y)
{
	y = _y;
}

void Vans::initDraw()
{
	int temp = y;

	for (int i = 0; i < 5; i++)
	{
		ConsoleTask::gotoXY(x, y);
		cout << table[i];
		y++;

		cout << endl;
	}
	
	y = temp;
}

void Vans::moveLeft()
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

bool Vans::isImpact(int x, int y)
{
	//xet ngoai hcn
	if (x <= X() - 3 || x >= X() + 15 || y <= Y() - 3 || y >= Y() + 5) return false;
	else 
	{
		//xet ngay lo dau
		if (y == Y() - 2)
		{
			//cout << "1\n";
			if (x == X()-1 || x == X() -2) return false;
			else return true;
		}
		//than xe
		else if (y == Y() + 1 || y == Y() + 2 || y == Y() + 3 || y==Y()) return true;
		//2 banh xe 
		else if (y == Y() + 4)
		{
			if (x == X()-1 || x == X() + 13) return true;
			else return false;
		}
	}
}