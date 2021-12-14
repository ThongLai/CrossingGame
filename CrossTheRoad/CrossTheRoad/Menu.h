#pragma once

#include "Window.h"
#include "Alien.h"
#include "Bird.h"
#include "Car.h"
#include "Van.h"
#include "Player.h"

extern string title[];
extern int title_height;
extern int title_width;
extern string angel[];
extern int angel_height;
extern int angel_width;
extern string game_over[];
extern int game_over_height;
extern int game_over_width;

extern string MAINMENU[];
extern int MAINMENU_SIZE;
extern string INSTRUCTION[];
extern int INSTRUCTION_SIZE;
extern string SETTINGS[];
extern int SETTINGS_SIZE;
extern string CREDITS[];
extern int CREDITS_SIZE;
extern string YES_NO_SELECTION[];
extern int YES_NO_SELECTION_SIZE;
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

	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	string getContent() const;

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
	string title;
public:
	MENU();
	MENU(string title, string* content, int n, int x, int y, int width, int height, int text_color, int bg_color);
	~MENU();


	void setMenu(string title, string* content, int n, int x, int y, int width, int height, int text_color, int bg_color);
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
void displayScoreBoard(const Data&);
void displayLeaderBoard();
void drawInstruction();
void drawCredits();
void drawArt(string* art, int height, int x, int y, int text_color = WHITE, int bg_color = BLACK);

void Settings_Menu();
int Save_Menu();
int Load_Menu();
int Remove_Menu();

int Ask_ChangeWindowMode();
int Ask_NumberVolumes();
int Ask_SaveGame();
int Ask_PlayAgain();
int Ask_PlayerName();