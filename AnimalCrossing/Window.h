#pragma once WINDOW_H_
#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>
#pragma comment(lib, "Winmm.lib")
using namespace std;

#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13
#define ESC 27

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int GAMEPLAY_W;
extern int HIGHSCORE_W;
extern int ROAD_H;
extern int SIDEWALK_H;
extern int HIGHSCORE_H;
extern bool PLAYGAME;
extern bool MAINMENU;


void FixConsoleWindow();
void HideCursor();
void GotoXY(int x, int y);
void SetTextColor(WORD wColor);
WORD DefineColor(int t_color, int t_background);
void GetWindowSize();
void SetWindowSize(int width, int height);
void SetUpScreenSize();
void FullScreenMode();
void setRasterFonts();
bool GetXY(int& x, int& y);
bool GetColor(int& color);
void OpenSoundFiles();

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