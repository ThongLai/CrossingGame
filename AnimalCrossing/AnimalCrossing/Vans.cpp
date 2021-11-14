#include "Vans.h"

Vans::Vans()
{
	height = sizeof(table) / sizeof(string);

	int max_width = table[0].size();
	for (int i = 0; i < height; i++)
		if (max_width < table[i].size())
			max_width = table[i].size();

	width = max_width;
}

Vans::Vans(int _x, int _y) : Vans()
{
	mX = _x;
	mY = _y;
}

void Vans::Move(int, int)
{

}

void Vans::Draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
	{
		GotoXY(mX, iy);
		cout << table[i];
	}

}

void Vans::moveLeft()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	mX--;
	int x = mX;
	int y = mY;

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
			GotoXY(x + 15 - 125, j);
			cout << char(32);
		}

		//Them
		int count = 0;
		for (int i = x; i <= 124; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				GotoXY(i, j);
				cout << char(table[j - y][i - x]);
			}
			++count;
		}

		for (int i = 0; i < x + 14 - 124; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				GotoXY(i, j);
				cout << char(table[j - y][count]);
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
			GotoXY(x + 15, j);
			cout << char(32);
		}

		//Them
		for (int i = x; i <= x + 14; ++i)
		{
			for (int j = y; j <= y + 4; ++j)
			{
				GotoXY(i, j);
				cout << char(table[j - y][i - x]);
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