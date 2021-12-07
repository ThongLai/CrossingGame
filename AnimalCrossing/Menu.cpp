#include "Menu.h"

string MAINMENU[] = {
	"Play",
	"Load Games",
	"Leader Board",
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

int BOX::getX() const
{
	return x;
}

int BOX::getY() const
{
	return y;
}

string BOX::getContent() const
{
	return content;
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

int Save_Menu()
{
	string* NameList = ExtractPlayerName();
	string* SAVEMENU = new string[SavedPlayers.size() + 3];

	for (int i = 0; i < SavedPlayers.size(); i++)
		SAVEMENU[i] = NameList[i];
	SAVEMENU[SavedPlayers.size()] = "< New Player >";
	SAVEMENU[SavedPlayers.size() + 1] = "< Delete Player >";
	SAVEMENU[SavedPlayers.size() + 2] = "Return";

	delete[]NameList;

	int box_width = 21;
	int box_height = 5;
	MENU saveMenu("Save Game Menu", SavedPlayers.size() + 3, SAVEMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * SavedPlayers.size()), box_width, box_height, LIGHTGRAY, BLACK);

	saveMenu.printMenu();
	int buf = saveMenu.inputMenu();

	delete[]SAVEMENU;

	return buf;
}

int Load_Menu()
{
	if (SavedPlayers.size() <= 0)
	{
		printMessCenter("EMPTY!");
		Sleep(1000);
		return -2;
	}

	string* NameList = ExtractPlayerName();
	string* LOADMENU = new string[SavedPlayers.size() + 2];

	for (int i = 0; i < SavedPlayers.size(); i++)
		LOADMENU[i] = NameList[i];
	LOADMENU[SavedPlayers.size()] = "< Delete Player >";
	LOADMENU[SavedPlayers.size() + 1] = "Return";

	delete[]NameList;

	int box_width = 21;
	int box_height = 5;
	MENU loadMenu("Load Game Menu", SavedPlayers.size() + 2, LOADMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * SavedPlayers.size()), box_width, box_height, LIGHTGRAY, BLACK);

	loadMenu.printMenu();
	int buf = loadMenu.inputMenu();

	delete[]LOADMENU;

	return buf;
}

int Remove_Menu()
{
	if (SavedPlayers.size() <= 0)
	{
		printMessCenter("EMPTY!");
		Sleep(1000);
		return -2;
	}

	string* NameList = ExtractPlayerName();
	string* REMOVEMENU = new string[SavedPlayers.size() + 1];

	for (int i = 0; i < SavedPlayers.size(); i++)
		REMOVEMENU[i] = NameList[i];
	REMOVEMENU[SavedPlayers.size()] = "Cancel";

	delete[]NameList;

	int box_width = 21;
	int box_height = 5;
	MENU removeMenu("Choose the Player want to delete: ", SavedPlayers.size() + 1, REMOVEMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * SavedPlayers.size()), box_width, box_height, LIGHTGRAY, BLACK);

	removeMenu.printMenu();
	int buf = removeMenu.inputMenu();

	delete[]REMOVEMENU;

	return buf;
}

void Score_Board(const Data& data)
{
	int box_width = SCREEN_HEIGHT;
	int box_height = SCREEN_HEIGHT - 2 * 5;

	BOX scoreBoard[5];
	scoreBoard[0].setBox(midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height), box_width, box_height, LIGHTGREEN, BLACK, "");

	scoreBoard[1].setContent("Score: " + to_string(data.getScore()));
	scoreBoard[2].setContent("Level: " + to_string(data.getScore()));
	scoreBoard[3].setContent("Time: " + to_string(data.getTime()));


	for (int i = 1; i < 4; i++)
	{
		scoreBoard[i].setFormat(scoreBoard[i].getContent().size(), 3, LIGHTGREEN, BLACK);
		scoreBoard[i].setPosition(scoreBoard[0].getX() + midWidth(box_width, scoreBoard[i].getContent()), scoreBoard[0].getY() + box_height * (1 + i) / 6);
	}

	scoreBoard[0].printBorder();
	for (int i = 1; i < 4; i++)
		scoreBoard[i].printContent();
}

int Ask_SaveGame()
{
	int box_width = 21;
	int box_height = 5;
	MENU askSave("Do you want to save your progress?", DEADMENU_SIZE, DEADMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height) * 4 / 3, box_width, box_height, LIGHTGRAY, BLACK);

	askSave.printMenu();

	return askSave.inputMenu();
}

int Ask_PlayAgain()
{
	int box_width = 21;
	int box_height = 5;
	MENU askPlayAgain("Do you want to play again?", DEADMENU_SIZE, DEADMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height) * 4 / 3, box_width, box_height, LIGHTGRAY, BLACK);

	askPlayAgain.printMenu();

	return askPlayAgain.inputMenu();
}

void Title()
{
	string title[] =
	{
		"    .,-::::: :::::::..       ...      .::::::.  .::::::.     :::::::::::: ::   .: .,::::::      :::::::..       ...       :::.   :::::::-.  ",
		"  ,;;;'````' ;;;;``;;;;   .;;;;;;;.  ;;;`    ` ;;;`    `     ;;;;;;;;'''',;;   ;;,;;;;''''      ;;;;``;;;;   .;;;;;;;.    ;;`;;   ;;,   `';,",
		"  [[[         [[[,/[[['  ,[[     \\[[,'[==/[[[[,'[==/[[[[,         [[    ,[[[,,,[[[ [[cccc        [[[,/[[['  ,[[     \\[[, ,[[ '[[, `[[     [[",
		"  $$$         $$$$$$c    $$$,     $$$  '''    $  '''    $         $$    \"$$$\"\"\"$$$ $$\"\"\"\"        $$$$$$c    $$$,     $$$c$$$cc$$$c $$,    $$",
		"  `88bo,__,o, 888b \"88bo,\"888,_ _,88P 88b    dP 88b    dP         88,    888   \"88o888oo,_       888b \"88bo,\"888,_ _,88P 888   888,888_,o8P'",
		"    \"YUMMMMMP\"MMMM   \"W\"   \"YMMMMMP\"   \"YMmMY\"   \"YMmMY\"          MMM    MMM    YMM\"\"YUMMM       MMMM   \"W\"   \"YMMMMMP\"  YMM   \"\"` MMMMP\"`"
	};

	int height = sizeof(title) / sizeof(string);

	Status SavedStatus;
	SetTextColor(DefineColor(rand() % (15) + 1, BLACK));
	
	for (int i = 0; i < height; i++)
	{
		GotoXY(midWidth(SCREEN_WIDTH, title[0].size()), midHeight(SCREEN_HEIGHT / 2, height) + i);
		cout << title[i] << endl;
	}
}