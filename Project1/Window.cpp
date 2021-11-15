#include "Window.h"
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include<iostream>

void ConsoleTask::setConsoleWindow(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, w, h, TRUE);
}

void ConsoleTask::fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void ConsoleTask::removeConsoleScrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

/*void ConsoleTask::setConsoleTitle()
{
	SetConsoleTitle("BT-DICTIONARY-1712168");
}*/

void ConsoleTask::clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void ConsoleTask::showCursor()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO* cci = new CONSOLE_CURSOR_INFO;
	cci->dwSize = 1;
	cci->bVisible = TRUE;

	SetConsoleCursorInfo(hstdout, cci);
}

void ConsoleTask::hideCursor()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO* cci = new CONSOLE_CURSOR_INFO;
	cci->dwSize = 1;
	cci->bVisible = FALSE;

	SetConsoleCursorInfo(hstdout, cci);
}

void ConsoleTask::gotoXY(int pX, int pY)
{
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleTask::gotoXY(int pX, int pY, string text)
{
	gotoXY(pX, pY);
	cout << text;
}

void ConsoleTask::gotoXY(int pX, int pY, string text, int color)
{
	gotoXY(pX, pY);
	setTextColor(color);
	cout << text;
	setTextColor(7);
}

void ConsoleTask::gotoXY(int pX, int pY, int number, int color)
{
	gotoXY(pX, pY);
	setTextColor(color);
	cout << number;
	setTextColor(7);
}

void ConsoleTask::gotoXY(int pX, int pY, char c, int color)
{
	gotoXY(pX, pY);
	setTextColor(color);
	cout.put(char(c)).flush();
	setTextColor(7);
}

void ConsoleTask::gotoXY(int pX, int pY, char ch)
{
	gotoXY(pX, pY);
	cout.put(char(ch)).flush();
}

void ConsoleTask::setTextColor(int code)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), code);
}
