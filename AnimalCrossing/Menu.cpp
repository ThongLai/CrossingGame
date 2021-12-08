#include "Menu.h"

string title[] =
{
	"    .,-::::: :::::::..       ...      .::::::.  .::::::.     :::::::::::: ::   .: .,::::::      :::::::..       ...       :::.   :::::::-.  ",
	"  ,;;;'````' ;;;;``;;;;   .;;;;;;;.  ;;;`    ` ;;;`    `     ;;;;;;;;'''',;;   ;;,;;;;''''      ;;;;``;;;;   .;;;;;;;.    ;;`;;   ;;,   `';,",
	"  [[[         [[[,/[[['  ,[[     \\[[,'[==/[[[[,'[==/[[[[,         [[    ,[[[,,,[[[ [[cccc        [[[,/[[['  ,[[     \\[[, ,[[ '[[, `[[     [[",
	"  $$$         $$$$$$c    $$$,     $$$  '''    $  '''    $         $$    \"$$$\"\"\"$$$ $$\"\"\"\"        $$$$$$c    $$$,     $$$c$$$cc$$$c $$,    $$",
	"  `88bo,__,o, 888b \"88bo,\"888,_ _,88P 88b    dP 88b    dP         88,    888   \"88o888oo,_       888b \"88bo,\"888,_ _,88P 888   888,888_,o8P'",
	"    \"YUMMMMMP\"MMMM   \"W\"   \"YMMMMMP\"   \"YMmMY\"   \"YMmMY\"          MMM    MMM    YMM\"\"YUMMM       MMMM   \"W\"   \"YMMMMMP\"  YMM   \"\"` MMMMP\"`"
};
int title_height = sizeof(title) / sizeof(string);
int title_width = artWidth(title, title_height);

string angel[] =
{
"            ,-.-.       ",
"           / ,-. \\      ",
"      ,-. ( |a a| ) ,-.     ",
"     :   `( : o ; )'   :       ",
" ____|____(_.>-<._)____|____",
"(_|        /     \\        |_)",
" ||      :  `.|,' :       ||",
"  |___..--|_\\_|_/_|-...___| ",
"    ;     | /SSt\\ | :",
"   /  ;  ;| ,'|`. |:  :  \\",
"  /  /| /|;._____.:|\\ |\\  \\",
" / ,' `' /  ;| |:  \\ `' `. \\",
" `'     /  / | | \\  \\     `'",
"       /  /  ; :  \\  \\",
"      /  /  /| |\\  \\  \\",
"     /  /  / | | \\  \\  \\",
"    /  /  /  ; :  \\  \\  \\",
"   /  /  /  /| |\\  \\  \\  \\",
"  (  /  /  / | | \\  \\  \\  )",
"   `(_ /  /  ; :  \\  \\ _)'",
"      `'.(_./___\\._).`'",
};
int angel_height = sizeof(angel) / sizeof(string);
int angel_width = artWidth(angel, angel_height);

string game_over[] =
{
"  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$",
" /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/",
"| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$      ",
"| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$   ",
"| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/   ",
"| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$      ",
"|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$",
" \\______/ |__/  |__/|__/     |__/|________/",
"  /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$ ",
" /$$__  $$| $$   | $$| $$_____/| $$__  $$",
"| $$  \\ $$| $$   | $$| $$      | $$  \\ $$",
"| $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/",
"| $$  | $$ \\  $$ $$/ | $$__/   | $$__  $$",
"| $$  | $$  \\  $$$/  | $$      | $$  \\ $$",
"|  $$$$$$/   \\  $/   | $$$$$$$$| $$  | $$",
" \\______/     \\_/    |________/|__/  |__/"
};
int game_over_height = sizeof(game_over) / sizeof(string);
int game_over_width = artWidth(game_over, game_over_height);

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

string YES_NO_SELECTION[] = {
	"Yes",
	"No",
};
int YES_NO_SELECTION_SIZE = sizeof(YES_NO_SELECTION) / sizeof(string);

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

int BOX::getWidth() const
{
	return width;
}

int BOX::getHeight() const
{
	return height;
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

void drawScoreBoard(const Data& data)
{
	int box_width = SCREEN_WIDTH / 3;
	int box_height = SCREEN_HEIGHT / 2;

	BOX scoreBoard[5];

	scoreBoard[0].setBox(midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT / 2, box_height), box_width, box_height, LIGHTGREEN, BLACK, "");

	scoreBoard[1].setContent("GAME OVER");
	scoreBoard[2].setContent("Score:          " + to_string(data.getScore()));
	scoreBoard[3].setContent("Level:          " + to_string(data.getLevel()));
	scoreBoard[4].setContent("Time:           " + to_string(data.getTime()));

	scoreBoard[1].setFormat(box_width - 2, 3, YELLOW, BLACK);
	scoreBoard[2].setFormat(scoreBoard[2].getContent().size() + 2, 3, LIGHTRED, BLACK);
	scoreBoard[3].setFormat(scoreBoard[2].getContent().size() + 2, 3, LIGHTMAGENTA, BLACK);
	scoreBoard[4].setFormat(scoreBoard[2].getContent().size() + 2, 3, LIGHTBLUE, BLACK);

	scoreBoard[1].setPosition(scoreBoard[0].getX() + midWidth(box_width, scoreBoard[1].getWidth()), scoreBoard[0].getY() + box_height / 10);

	for (int i = 2; i < 5; i++)
	{
		//scoreBoard[i].setFormat(scoreBoard[i].getContent().size(), 3, GREEN, BLACK);
		scoreBoard[i].setPosition(scoreBoard[0].getX() + midWidth(box_width, scoreBoard[i].getWidth()), scoreBoard[0].getY() + box_height * i / 6);
	}

	scoreBoard[0].printBox();
	scoreBoard[1].printContent();
	for (int i = 2; i < 5; i++)
		scoreBoard[i].printBox();
}

void drawLeaderBoard()
{
	int box_width = SCREEN_WIDTH / 2;
	int box_height = SCREEN_HEIGHT * 0.8;

	BOX border[4];
	border[0].setBox(midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height), box_width * 2 / 5, box_height, YELLOW, BLACK, "");
	border[1].setBox(border[0].getX() + border[0].getWidth(), midHeight(SCREEN_HEIGHT, box_height), box_width * 1 / 5, box_height, YELLOW, BLACK, "");
	border[2].setBox(border[1].getX() + border[1].getWidth(), midHeight(SCREEN_HEIGHT, box_height), box_width * 1 / 5, box_height, YELLOW, BLACK, "");
	border[3].setBox(border[2].getX() + border[2].getWidth(), midHeight(SCREEN_HEIGHT, box_height), box_width * 1 / 5, box_height, YELLOW, BLACK, "");

	vector <BOX> leaderBoard;
	leaderBoard.resize(LeaderBoard.size() + 1);

	string name, score, level, time;
	string sp1, sp2, sp3, sp4;
	for (int i = 0; i < LeaderBoard.size(); i++)
	{
		name = LeaderBoard[i].getName();
		score = to_string(LeaderBoard[i].getScore());
		level = to_string(LeaderBoard[i].getLevel());
		time = to_string(LeaderBoard[i].getTime() / 3600) + ":" + to_string((LeaderBoard[i].getTime() / 60) % 60) + ":" + to_string(LeaderBoard[i].getTime() % 60);

		sp1 = string((border[0].getWidth() - name.size()) / 2, ' ');
		sp2 = string((border[1].getWidth() - score.size()) / 2, ' ');
		sp3 = string((border[2].getWidth() - level.size()) / 2, ' ');
		sp4 = string((border[3].getWidth() - time.size()) / 2, ' ');

		leaderBoard[i].setPosition(border[0].getX(), border[0].getY() + (1+i)*3);
		leaderBoard[i].setFormat(box_width, 3, i < 3 ? LIGHTRED : (i > (LeaderBoard.size() - 3) / 2 ? LIGHTBLUE : LIGHTMAGENTA), BLACK);
		leaderBoard[i].setContent(sp1 + name + sp1 + sp2 + score + sp2 + sp3 + level + sp3 + sp4 + time + sp4);
	}

	name = "NAME";
	score = "SCORE";
	level = "LEVEL";
	time = "TIME";

	sp1 = string((border[0].getWidth() - name.size()) / 2, ' ');
	sp2 = string((border[1].getWidth() - score.size()) / 2, ' ');
	sp3 = string((border[2].getWidth() - level.size()) / 2, ' ');
	sp4 = string((border[3].getWidth() - time.size()) / 2, ' ');

	leaderBoard[LeaderBoard.size()].setPosition(border[0].getX(), border[0].getY());
	leaderBoard[LeaderBoard.size()].setFormat(box_width, 3, YELLOW, BLACK);
	leaderBoard[LeaderBoard.size()].setContent(sp1 + name + sp1 + sp2 + score + sp2 + sp3 + level + sp3 + sp4 + time + sp4);

	

	for (int i = 0; i < LeaderBoard.size(); i++)
		leaderBoard[i].printBox();
	for (int i = 0; i < 4; i++)
		border[i].printBorder();
	leaderBoard[LeaderBoard.size()].printBox();
}

void drawArt(string* art, int height, int x, int y, int text_color, int bg_color)
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int i = 0; i < height; i++)
	{
		GotoXY(x, y + i);
		cout << art[i];
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


int Ask_SaveGame()
{
	int box_width = 21;
	int box_height = 5;
	MENU askSave("Do you want to save your progress?", YES_NO_SELECTION_SIZE, YES_NO_SELECTION, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height), box_width, box_height, LIGHTGRAY, BLACK);

	askSave.printMenu();

	return askSave.inputMenu();
}

int Ask_PlayAgain()
{
	int box_width = 21;
	int box_height = 5;
	MENU askPlayAgain("Do you want to play again?", YES_NO_SELECTION_SIZE, YES_NO_SELECTION, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 4 / 3, box_height), box_width, box_height, LIGHTGRAY, BLACK);

	askPlayAgain.printMenu();

	return askPlayAgain.inputMenu();
}

int Ask_PlayerName()
{
	int box_width = 21;
	int box_height = 5;
	MENU askPlayAgain("Do you want to save your score?", YES_NO_SELECTION_SIZE, YES_NO_SELECTION, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 4 / 3, box_height) , box_width, box_height, LIGHTGRAY, BLACK);

	askPlayAgain.printMenu();

	return askPlayAgain.inputMenu();
}

