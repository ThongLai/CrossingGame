#pragma once WINDOW_H_
#include<windows.h>
#include<iostream>
#include<string>
using namespace std;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

void FixConsoleWindow();
void HideCursor();
void GotoXY(int x, int y);
void SetTextColor(WORD wColor);
WORD DefineColor(int t_color, int t_background);
void GetWindowSize(int& width, int& height);
void SetWindowSize(int width, int height);
void FullScreenMode();
void setRasterFonts();
bool GetXY(int& x, int& y);
bool GetColor(int& color);

void PrintChar(int x, int y, char ch);
void PrintString(int x, int y, string S);
void printMessCenter(string message);
int midWidth(int width, string content);
int midWidth(int width, int content_width);
int midHeight(int height, int content_height);


//Save status of coordinates and text/background color
class Status
{
private:
	int _X, _Y;
	int _COLOR;
public:
	Status()
	{
		GetXY(_X, _Y);
		GetColor(_COLOR);
	}
	~Status()
	{
		ResetToCurrent();
	}
	int getX();
	int getY();
	int getColor();

	void ResetToCurrent()
	{
		GotoXY(_X, _Y);
		SetTextColor(_COLOR);
	}
};