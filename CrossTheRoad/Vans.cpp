#include "Vans.h"

Van::Van() : CVEHICLE()
{
	vehicle_table = table;

	height = sizeof(table) / sizeof(string);
	width = table[0].size();
}

Van::Van(int x, int y) : Van()
{
	mX = x;
	mY = y;
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
	RemoveMoving(false);

	//Remove();
	mX--;
	if (mX < 0)
		mX = GAMEPLAY_W - 1;

	Draw();
}

//void Vans::moveLeft()
//{
//	Status SavedStatus;
//	SetTextColor(DefineColor(text_color, bg_color));
//
//	mX--;
//	int x = mX;
//	int y = mY;
//
//	if (x == -1)
//	{
//		x = 124;
//		setX(x);
//	}
//
//	if (x + 14 >= 124)
//	{
//		//Xoa
//		for (int j = y; j <= y + 4; ++j)
//		{
//			GotoXY(x + 15 - 125, j);
//			cout << char(32);
//		}
//
//		//Them
//		int count = 0;
//		for (int i = x; i <= 124; ++i)
//		{
//			for (int j = y; j <= y + 4; ++j)
//			{
//				GotoXY(i, j);
//				cout << char(table[j - y][i - x]);
//			}
//			++count;
//		}
//
//		for (int i = 0; i < x + 14 - 124; ++i)
//		{
//			for (int j = y; j <= y + 4; ++j)
//			{
//				GotoXY(i, j);
//				cout << char(table[j - y][count]);
//			}
//			++count;
//			if (count > 14)
//				break;
//		}
//
//	}
//	else
//	{
//		//Xoa
//		for (int j = y; j <= y + 4; ++j)
//		{
//			GotoXY(x + 15, j);
//			cout << char(32);
//		}
//
//		//Them
//		for (int i = x; i <= x + 14; ++i)
//		{
//			for (int j = y; j <= y + 4; ++j)
//			{
//				GotoXY(i, j);
//				cout << char(table[j - y][i - x]);
//			}
//		}
//	}
//}

bool Van::isImpact(int x, int y)
{
	//xet ngoai hcn
	if (x <= X() - 3 || x >= X() + 15 || y <= Y() - 3 || y >= Y() + 5) return false;
	else 
	{
		//xet dau xe
		if (y == Y() - 2)
		{
			if (x == X() - 1 || x == X() - 2) return false;
			else return true;
		}

		//than xe
		if (y == Y() - 1) return true;

		if (y == Y()) return true;

		if (y == Y() + 1) return true;

		if (y == Y() + 2) return true;

		if (y == Y() + 3) return true;
		
		//2 banh xe 
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
	mciSendString(TEXT("play Van_Crash from 0"), NULL, 0, NULL);
}

void Van::SurroundingSound()
{
	mciSendString(TEXT("play Van_SD from 0"), NULL, 0, NULL);
}