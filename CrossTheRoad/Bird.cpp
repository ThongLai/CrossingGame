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
	RemoveMoving(direct); //Xoa object
	
	if (direct) //Bien direct quyet dinh huong di chuyen cua object, direct = true => qua phai
	{
		++mX; //Tang toa do de object di chuyen qua phai
		++count; //Tang bien dem count de tinh so buoc da di tu lan cuoi doi huong
		if (mX == GAMEPLAY_W) //Neu toi bien phai, gan toa do X = 0
			mX = 0;
	}
	else //Tuong tu o tren, direct = false => qua trai
	{
		--mX;
		++count;
		if (mX < 0)
			mX = GAMEPLAY_W - 1;
	}

	Draw(); //Ve object
}

bool Bird::isImpact(int x, int y) 
{	
	//Nam ngoai table
	if (x <= X() - 3 || x >= X() + 15 || y <= Y() - 3 || y >= Y() + 5) return false;
	else
	{	
		//Kiem tra phan chan
		if (y == Y() + 4)
		{
			if (x <= X() + 3 || x >= X() + 9) return false;
			else return true;
		}

		//Kiem tra phan canh chim

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

		//Kiem tra phan dau
		if (y == Y() - 2)
		{
			if (x <= X() + 3 || x >= X() + 10) return false;
			else return true;
		}	
	}
}

void Bird::Tell()
{
	mciSendString(TEXT("play Bird_Crash from 0"), NULL, 0, NULL);
}

void Bird::SurroundingSound()
{
	mciSendString(TEXT("play Bird_SD from 0"), NULL, 0, NULL);
}

//void Bird::moveLeft()
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

//void Bird::moveRight()
//{
//	setX(X() + 1);
//	int x = X();
//	int y = Y();
//
//	if (x == 125)
//	{
//		x = 0;
//		setX(x);
//	}
//
//	if (x + 14 >= 124)
//	{
//		//Xoa
//		for (int j = y; j <= y + 4; ++j)
//		{
//			GotoXY(x - 1, j);
//			cout << char(32);
//		}
//
//		//Them
//		int count = 0;
//		for (int i = x; i <= 124; ++i)
//		{
//			for (int j = y; j <= y + 4; ++j)
//			{
//				GotoXY(i, j, char(table[j - y][i - x]));
//			}
//			++count;
//		}
//
//		for (int i = 0; i < x + 14 - 124; ++i)
//		{
//			for (int j = y; j <= y + 4; ++j)
//			{
//				ConsoleTask::gotoXY(i, j, char(table[j - y][count]));
//			}
//			++count;
//			if (count > 14)
//				break;
//		}
//	}
//	else
//	{
//		//Xoa
//		for (int j = y; j <= y + 4; ++j)
//		{
//			if (x == 0)
//			{
//				ConsoleTask::gotoXY(124, j, char(32));
//			}
//			else ConsoleTask::gotoXY(x - 1, j, char(32));
//
//		}
//
//		//Them
//		for (int i = x; i <= x + 14; ++i)
//		{
//			for (int j = y; j <= y + 4; ++j)
//			{
//				ConsoleTask::gotoXY(i, j, char(table[j - y][i - x]));
//			}
//		}
//	}
//}