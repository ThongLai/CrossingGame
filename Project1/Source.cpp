#include <iostream>
#include <Windows.h>
#include "Window.h"
#include "Car.h"
#include <conio.h>
#include <string>
#include <cstdio>
#include <thread>
#include <cmath>
using namespace std;


void setRasterFonts()
{
	CONSOLE_FONT_INFOEX cf = { 0 };
	cf.cbSize = sizeof cf;
	cf.dwFontSize.X = 10;
	cf.dwFontSize.Y = 18;
	wcscpy_s(cf.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}



//People

class People
{
	int x, y;
	bool state;//1:live ; 0:die

	string table[3] = {
	 " ",
	 "ÄÛÄ",
	"/ \\"
	};


public:

	People();

	int X();
	int Y();

	void setX(int);
	void setY(int);

	void initDraw();
	void Clear();
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	bool isDead();

};


People::People()
{
	x = 20;
	y = 20;
	state = 1;
}

int People::X()
{
	return x;
}

int People::Y()
{
	return y;
}

void People::setX(int _x)
{
	x = _x;
}

void People::setY(int _y)
{
	y = _y;
}

void People::initDraw()
{
	int temp = y;

	for (int i = 0; i < 3; i++)
	{
		ConsoleTask::gotoXY(x, y, table[i]);
		y++;
		cout << endl;
	}

	y = temp;
}

void People::Clear()
{
	x = X();
	y = Y();

	int temp = y;

	for (int i = 0; i < 3; i++)
	{
		ConsoleTask::gotoXY(x, y, "   ");
		y++;
		cout << endl;
	}

	y = temp;
}

void People::UP()
{
	Clear();
	setY(y - 1);
	initDraw();
}

void People::DOWN()
{
	Clear();
	setY(y + 1);
	initDraw();
}

void People::LEFT()
{
	Clear();
	setX(x - 1);
	initDraw();
}

void People::RIGHT()
{
	Clear();
	setX(x + 1);
	initDraw();
}

int main()
{
	ConsoleTask::hideCursor();
	ConsoleTask::setConsoleWindow(1633, 900);
	setRasterFonts();
	Car mer;
	mer.setX(13);
	mer.setY(5);
	mer.initDraw();
	
	People player;
	player.setX(5);
	player.setY(5);
	player.initDraw();
	

	while (1)
	{
		char temp = _getwch();
		
		if (temp == 27) break;
		else if (temp == 119)
		{
			//a.initDraw();
			player.UP();
		}
		else if (temp == 115)
		{
			//a.initDraw();
			player.DOWN();
		}
		else if (temp == 97)
		{
			//a.initDraw();
			player.LEFT();
		}
		else if (temp == 100)
		{
			//a.initDraw();
			player.RIGHT();
		}
		if (mer.isImpact(player.X(), player.Y()) == TRUE) cout << "DEAD" << endl;
	}
	return 0;
}
