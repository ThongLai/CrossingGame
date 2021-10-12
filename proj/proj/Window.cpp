#include "Window.h"
#include<iostream>
using namespace std;

void Window::gotoXY(int x, int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = x;
    Position.Y = y;

    SetConsoleCursorPosition(hStdout, Position);
}

void Window::gotoXY_Char(int x, int y,char ch)
{
    gotoXY(x, y);
    cout << ch;
}

void Window::gotoXY_String(int x, int y, string S)
{
    gotoXY(x, y);
    cout << S;
}


