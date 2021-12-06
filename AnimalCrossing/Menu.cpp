#include "Menu.h"

string MAINMENU[] = {
	"Play",
	"Continue",
	"Leader Board",
	"Load Games",
	"Instructions",
	"Settings",
	"Credits",
	"Exit",
};
int MAINMENU_SIZE = sizeof(MAINMENU) / sizeof(string);

string DEADMENU[] = {
	"Yes",
	"No",
};
int DEADMENU_SIZE = sizeof(DEADMENU) / sizeof(string);

string GUIDEBUTTONS[] =
{
	"P - Pause/Continue",
	"R - Reset Game",
	"M - Save Game",
	"L - Load Game",
	"Esc - Return to Main Menu"

};
int GUIDEBUTTONS_SIZE = sizeof(GUIDEBUTTONS) / sizeof(string);

string STATUSVAR[] = {
	"Time: ",
	"Level: ",
	"Scores: "
};
int STATUSVAR_SIZE = sizeof(STATUSVAR) / sizeof(string);



//BOX
BOX::BOX()
{
	setBox(0, 0, 0, 0, WHITE, BLACK, "");
}

BOX::BOX(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content)
{
	setBox(_x, _y, _width, _height, _text_color, _bg_color, _content);
}

BOX::BOX(int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	setBox(_x, _y, _width, _height, _text_color, _bg_color, "");
}

void BOX::setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content)
{
	setPosition(_x, _y);
	setFormat(_width, _height, _text_color, _bg_color);
	setContent(_content);

}

void BOX::setPosition(int _x, int _y)
{
	x = _x; y = _y;
}

void BOX::setFormat(int _w, int _h, int _text_color, int _bg_color)
{
	width = _w; height = _h;
	text_color = _text_color; bg_color = _bg_color;
}

void BOX::setContent(string _content)
{
	content = _content;
}

void BOX::printBox()
{
	printBorder();
	printContent();
}

void BOX::printBorder()
{
	if (height <= 1 || width <= 1) return;
	Status SavedState;
	SetTextColor(DefineColor(text_color, bg_color));

	GotoXY(x, y);
	cout << char(201);
	GotoXY(x, y + height - 1);
	cout << char(200);

	GotoXY(x + width - 1, y);
	cout << char(187);
	GotoXY(x + width - 1, y + height - 1);
	cout << char(188);


	for (int ix = x + 1; ix < x + width - 1; ix++)
	{
		GotoXY(ix, y);
		cout << char(205);
		GotoXY(ix, y + height - 1);
		cout << char(205);
	}

	for (int iy = y + 1; iy < y + height - 1; iy++)
	{
		GotoXY(x, iy);
		cout << char(186);
		GotoXY(x + width - 1, iy);
		cout << char(186);
	}
}

void BOX::printContent()
{
	if (height <= 1 || width <= 1) return;
	Status SavedState;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int iy = y + 1; iy < y + height - 1; iy++) {
		for (int ix = x + 1; ix < x + width - 1; ix++)
		{
			GotoXY(ix, iy);
			cout << " ";
		}
	}

	GotoXY(x + midWidth(width, content), y + midHeight(height, 1));
	cout << content;
}

void BOX::printContent(int _text_color, int _bg_color)
{
	if (height <= 1 || width <= 1) return;
	Status SavedState;
	SetTextColor(DefineColor(_text_color, _bg_color));

	for (int iy = y + 1; iy < y + height - 1; iy++) {
		for (int ix = x + 1; ix < x + width - 1; ix++)
		{
			GotoXY(ix, iy);
			cout << " ";
		}
	}

	GotoXY(x + midWidth(width, content), y + midHeight(height, 1));
	cout << content;
}

void BOX::removeBox()
{
	if (height <= 1 || width <= 1) return;
	Status SavedState;
	SetTextColor(SavedState.getColor());

	for (int ix = x; ix < x + width; ix++)
	{
		for (int iy = y; iy < y + height; iy++) {
			GotoXY(ix, iy);
			cout << " ";
		}
	}
}


//MENU
MENU::MENU() : n(1), trench(0), title("") {
	nBox = new BOX[n];
}

MENU::MENU(string _title, int _n, string* content, int _x, int _y, int _width, int _height, int _text_color, int _bg_color) : n(_n), trench(0)
{
	nBox = new BOX[n];
	setMenu(_title, content, _x, _y, _width, _height, _text_color, _bg_color);
}

MENU::~MENU()
{
	delete[]nBox;
}

void MENU::setMenu(string _title, string* content, int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	setBox(_x, _y, _width, _height, _text_color, _bg_color);
	setBoxContent(content);
	setTitle(_title);
}

void MENU::setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	setFormat(_width, _height, _text_color, _bg_color);
	setPosition(_x, _y);

	for (int i = 0; i < n; i++)
	{
		setBoxPosition(i, _x, _y + i * (_height));
		setBoxFormat(i, _width, _height, _text_color, _bg_color);
	}
}

void MENU::setBoxPosition(int box_index, int _x, int _y)
{
	nBox[box_index].setPosition(_x, _y);
}

void MENU::setBoxFormat(int box_index, int _width, int _height, int _text_color, int _bg_color)
{
	nBox[box_index].setFormat(_width, _height, _text_color, _bg_color);
}

void MENU::setBoxContent(string* content)
{
	for (int i = 0; i < n; i++)
		nBox[i].setContent(content[i]);
}

void MENU::setTitle(string _title)
{
	title = _title;
}

void MENU::printMenu()
{
	printTitle();

	for (int i = 0; i < n; i++)
		nBox[i].printBox();
}

void MENU::printTitle()
{
	Status SavedState;
	SetTextColor(DefineColor(text_color, bg_color));

	GotoXY(x + midWidth(width, title), y - height);
	cout << title;
}

void MENU::selectedBox(int index)
{
	nBox[index].printContent(BLACK, LIGHTGRAY);
}

int MENU::inputMenu()
{
	int i = 0;
	char input;
	bool isPress = false;
	while (true)
	{
		if (isPress) {
			selectedBox(i);
			isPress = false;
		}

		if (_kbhit())
		{
			isPress = true;
			input = toupper(_getch());

			if (input == -32)
				input = toupper(_getch());

			if (input == KEY_UP || input == 'W')
			{
				nBox[i].printContent();
				i = (i == 0) ? i = n - 1 : i -= 1;
			}
			else if (input == KEY_DOWN || input == 'S')
			{
				nBox[i].printContent();
				i = (i == n - 1) ? i = 0 : i += 1;
			}
			else if (input == ENTER)
			{
				return i;
			}
			else if (input == ESC)
			{
				return -1;
			}
		}
	}
}


void drawStartFinishLine()
{
	BOX side[2];

	side[0].setBox(0, SIDEWALK[0], GAMEPLAY_W, SIDEWALK_H, GREEN, BLACK, "START");
	side[0].printBox();

	side[1].setBox(0, SIDEWALK[1], GAMEPLAY_W, SIDEWALK_H, GREEN, BLACK, "FINISH");
	side[1].printBox();
}

void drawStatusBox()
{
	BOX StatusBox(GAMEPLAY_W, 0, STATUS_W, SCREEN_HEIGHT, LIGHTMAGENTA, BLACK);
	StatusBox.printBox();

	for (int i = 0; i < STATUSVAR_SIZE; i++)
	{
		GotoXY(GAMEPLAY_W + midWidth(STATUS_W, STATUSVAR[0].size() + 10), midHeight(SCREEN_HEIGHT, STATUSVAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + i * 2);
		cout << STATUSVAR[i];
	}

	for (int i = 0; i < GUIDEBUTTONS_SIZE; i++)
	{
		GotoXY(GAMEPLAY_W + midWidth(STATUS_W, GUIDEBUTTONS[GUIDEBUTTONS_SIZE - 1]), midHeight(SCREEN_HEIGHT, STATUSVAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 2 + i * 2);
		cout << GUIDEBUTTONS[i];
	}

}


int DeadMenu()
{
	int box_width = 21;
	int box_height = 5;
	MENU DeadMenu("Do you want to play again?", DEADMENU_SIZE, DEADMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height) * 4 / 3, box_width, box_height, LIGHTGRAY, BLACK);

	int buf = 0;
	DeadMenu.printMenu();

	do {
		buf = DeadMenu.inputMenu();
	} while (buf != 0 && buf != 1 && buf != -1);

	return buf;
}