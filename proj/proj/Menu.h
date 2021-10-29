#pragma once MENU_H_

#include "Window.h"
#include <conio.h>


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

extern string MENU[];
extern int MENU_SIZE;



class Box
{
private:
	string content;
protected:
	int x, y;
	int width, height;
	int text_color, bg_color;
public:
	Box();
	Box(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content);
	Box(int _x, int _y, int _width, int _height, int _text_color, int _bg_color);


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

class Menu : public Box
{
private:
	Box* nBox;
	int n;
	int trench;
	string title;
public:
	Menu();
	Menu(string _title, int _n, string* content, int _x, int _y, int _width, int _height, int _text_color, int _bg_color);
	~Menu();


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