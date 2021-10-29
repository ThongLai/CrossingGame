#include "Menu.h"

string MENU[] = {
	"Play",
	"Continue",
	"Leader Board",
	"Load Games",
	"Instructions",
	"Settings",
	"Credits",
	"Exit",
};
int MENU_SIZE = sizeof(MENU) / sizeof(string);


//BOX
Box::Box()
{
	setBox(0, 0, 0, 0, WHITE, BLACK, "");
}

Box::Box(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content)
{
	setBox(_x, _y, _width, _height, _text_color, _bg_color, _content);
}

Box::Box(int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	setBox(_x, _y, _width, _height, _text_color, _bg_color, "");
}

void Box::setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color, string _content)
{
	setPosition(_x, _y);
	setFormat(_width, _height, _text_color, _bg_color);
	setContent(_content);

}

void Box::setPosition(int _x, int _y)
{
	x = _x; y = _y;
}

void Box::setFormat(int _w, int _h, int _text_color, int _bg_color)
{
	width = _w; height = _h;
	text_color = _text_color; bg_color = _bg_color;
}

void Box::setContent(string _content)
{
	content = _content;
}

void Box::printBox()
{
	printBorder();
	printContent();
}

void Box::printBorder()
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

void Box::printContent()
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

void Box::printContent(int _text_color, int _bg_color)
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

void Box::removeBox()
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
Menu::Menu() : n(1), trench(0), title("") {
	nBox = new Box[n];
}

Menu::Menu(string _title, int _n, string* content, int _x, int _y, int _width, int _height, int _text_color, int _bg_color) : n(_n), trench(0)
{
	nBox = new Box[n];
	setMenu(_title, content, _x, _y, _width, _height, _text_color, _bg_color);
}

Menu::~Menu()
{
	delete[]nBox;
}

void Menu::setMenu(string _title, string* content, int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	setBox(_x, _y, _width, _height, _text_color, _bg_color);
	setBoxContent(content);
	setTitle(_title);
}

void Menu::setBox(int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	setFormat(_width, _height, _text_color, _bg_color);
	setPosition(_x, _y);

	for (int i = 0; i < n; i++)
	{
		setBoxPosition(i, _x, _y + i * (_height));
		setBoxFormat(i, _width, _height, _text_color, _bg_color);
	}
}

void Menu::setBoxPosition(int box_index, int _x, int _y)
{
	nBox[box_index].setPosition(_x, _y);
}

void Menu::setBoxFormat(int box_index, int _width, int _height, int _text_color, int _bg_color)
{
	nBox[box_index].setFormat(_width, _height, _text_color, _bg_color);
}

void Menu::setBoxContent(string* content)
{
	for (int i = 0; i < n; i++)
		nBox[i].setContent(content[i]);
}

void Menu::setTitle(string _title)
{
	title = _title;
}

void Menu::printMenu()
{
	printTitle();

	for (int i = 0; i < n; i++)
		nBox[i].printBox();
}

void Menu::printTitle()
{
	Status SavedState;

	SetTextColor(DefineColor(text_color, bg_color));

	GotoXY(x + midWidth(width, title), y - height);
	cout << title;
}

void Menu::selectedBox(int index)
{
	nBox[index].printContent(BLACK, LIGHTGRAY);
}

int Menu::inputMenu()
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