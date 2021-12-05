#pragma once

#include "Window.h"
#include <conio.h>

extern string MAINMENU[];
extern int MAINMENU_SIZE;
extern string DEADMENU[];
extern int DEADMENU_SIZE;
extern string GUIDEBUTTONS[];
extern int GUIDEBUTTONS_SIZE;
extern string STATUSVAR[];
extern int STATUSVAR_SIZE;


class BOX
{
private:
	string content;
protected:
	int x, y;
	int width, height;
	int text_color, bg_color;
public:
	BOX();
	BOX(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content);
	BOX(int _x, int _y, int _width, int _height, int _text_color, int _bg_color);

	void setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content);
	void setPosition(int _x, int _y);
	void setFormat(int _w, int _h, int _text_color, int _bg_color);
	void setContent(string _content);


	void printBox();
	void printBorder();
	void printContent();
	void printContent(int _text_color, int _bg_color);
	void removeBox();
};

class MENU : public BOX
{
private:
	BOX* nBox;
	int n;
	int trench;
	string title;
public:
	MENU();
	MENU(string _title, int _n, string* content, int _x, int _y, int _width, int _height, int _text_color, int _bg_color);
	~MENU();


	void setMenu(string _title, string* content, int _x, int _y, int _width, int _height, int _text_color, int _bg_color);
	void setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color);
	void setBoxPosition(int box_index, int _x, int _y);
	void setBoxFormat(int box_index, int _width, int _height, int _text_color, int _bg_color);
	void setBoxContent(string* content);
	void setTitle(string _title);


	void printMenu();
	void printTitle();
	void selectedBox(int index);

	int inputMenu();
};

void drawStartFinishLine();
void drawStatusBox();

int DeadMenu();