#pragma once window
#include<windows.h>
#include<iostream>
#include<string>
using namespace std;

#ifndef _WINDOW_H
#define _WINDOW_H

class Window
{

public:

	//move to point(x, y)
	static void gotoXY(int, int);

	//move to point (x,y) to output character
	static void gotoXY_Char(int, int, char);

	//move to point (x,y) to output string
	static void gotoXY_String(int, int, string);

};

#endif // !_WINDOW_HH

