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

string MAINMENU[] = 
{
	"Play",
	"Load Game",
	"Leader Board",
	"Instruction",
	"Settings",
	"Credits",
	"Quit",
};
int MAINMENU_SIZE = sizeof(MAINMENU) / sizeof(string);

string INSTRUCTION[] =
{
	"Use <W / A / S / D> to move the PLAYER UP / LEFT / DOWN / RIGHT around the map to dodge the obstacles.",
	"Press <P> to PAUSE the game.",
	"Press <R> to RESET the game",
	"Press <M> to SAVE the process.",
	"Press <L> to LOAD a game",
};
int INSTRUCTION_SIZE = sizeof(INSTRUCTION) / sizeof(string);

string SETTINGS[] =
{
	"Window",
	"Audio",
	"Return"
};
int SETTINGS_SIZE = sizeof(SETTINGS) / sizeof(string);

string CREDITS[] =
{
	"CROSS THE ROAD",
	"-----A Game Project made by HCMUS students-----",
	"Lai Minh Thong - 20127635",
	"Tran Nguyen Anh Tai - 20127319",
	"Nguyen Le Hoang Thong - 20127078",
	"Dao Dai Hai - 20127016",
	"--Instructors--",
	"Mr. Truong Toan Thinh",
	"Mr. Nguyen Hai Dang",
	"Mr. Do Trong Le",
	"Mr. Nguyen Thanh An"
};
int CREDITS_SIZE = sizeof(CREDITS) / sizeof(string);

string YES_NO_SELECTION[] = {
	"Yes",
	"No",
};
int YES_NO_SELECTION_SIZE = sizeof(YES_NO_SELECTION) / sizeof(string);

string GUIDEBUTTONS[] =
{
	"<P> - Pause/Continue",
	"<R> - Reset Game",
	"<M> - Save Game",
	"<L> - Load Game",
	"<Esc> - Return to Main Menu"

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
MENU::MENU() : n(1), title("") {
	nBox = new BOX[n];
}

MENU::MENU(string _title, string* content, int _n, int _x, int _y, int _width, int _height, int _text_color, int _bg_color) : n(_n)
{
	nBox = new BOX[n];
	setMenu(_title, content, _n, _x, _y, _width, _height, _text_color, _bg_color);
}

MENU::~MENU()
{
	delete[]nBox;
}

void MENU::setMenu(string _title, string* _content, int _n, int _x, int _y, int _width, int _height, int _text_color, int _bg_color)
{
	n = _n;
	setBox(_x, _y, _width, _height, _text_color, _bg_color);
	setBoxContent(_content);
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
			mciSendString(TEXT("play Menu_Select from 0"), NULL, 0, NULL);

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

void displayScoreBoard(const Data& data)
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

void displayLeaderBoard()
{
	string leaderBoard_title = "LEADER BOARD";
	string continue_title = "<PRESS ANY KEY TO CONTINUE>";

	BOX Title[2];
	Title[0].setBox(midWidth(SCREEN_WIDTH, leaderBoard_title.size() + 10), SCREEN_HEIGHT / 20, leaderBoard_title.size() + 10, 3, YELLOW, BLACK, leaderBoard_title);
	Title[1].setBox(midWidth(SCREEN_WIDTH, continue_title.size()), SCREEN_HEIGHT * 18 / 20, continue_title.size(), 3, LIGHTGREEN, BLACK, continue_title);

	int box_width = SCREEN_WIDTH / 2;
	int box_height = SCREEN_HEIGHT * 0.8;

	BOX border[4];
	border[0].setBox(midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height), box_width * 2 / 5, box_height, YELLOW, BLACK, "");
	border[1].setBox(border[0].getX() + border[0].getWidth(), midHeight(SCREEN_HEIGHT, box_height), box_width * 1 / 5, box_height, YELLOW, BLACK, "");
	border[2].setBox(border[1].getX() + border[1].getWidth(), midHeight(SCREEN_HEIGHT, box_height), box_width * 1 / 5, box_height, YELLOW, BLACK, "");
	border[3].setBox(border[2].getX() + border[2].getWidth(), midHeight(SCREEN_HEIGHT, box_height), box_width * 1 / 5, box_height, YELLOW, BLACK, "");

	vector <BOX> content;
	content.resize(LeaderBoard.size() + 1);

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

		content[i].setContent(sp1 + name + sp1 + sp2 + score + sp2 + sp3 + level + sp3 + sp4 + time + sp4);
		content[i].setPosition(border[0].getX(), border[0].getY() + (1 + i) * 3);
		content[i].setFormat(box_width, 3, i < 3 ? LIGHTRED : (i > (LeaderBoard.size() - 3) / 2 ? LIGHTBLUE : LIGHTMAGENTA), BLACK);
	}

	name = "NAME";
	score = "SCORE";
	level = "LEVEL";
	time = "TIME";

	sp1 = string((border[0].getWidth() - name.size()) / 2, ' ');
	sp2 = string((border[1].getWidth() - score.size()) / 2, ' ');
	sp3 = string((border[2].getWidth() - level.size()) / 2, ' ');
	sp4 = string((border[3].getWidth() - time.size()) / 2, ' ');

	content[LeaderBoard.size()].setContent(sp1 + name + sp1 + sp2 + score + sp2 + sp3 + level + sp3 + sp4 + time + sp4);
	content[LeaderBoard.size()].setPosition(border[0].getX(), border[0].getY());
	content[LeaderBoard.size()].setFormat(box_width, 3, YELLOW, BLACK);

	
	Title[0].printBox();
	Title[1].printContent();
	for (int i = 0; i < LeaderBoard.size(); i++)
		content[i].printBox();
	for (int i = 0; i < 4; i++)
		border[i].printBorder();
	content[LeaderBoard.size()].printBox();
}

void drawInstruction()
{
	int content_height = 3 * (INSTRUCTION_SIZE + 5);

	string instruction_title = "HOW TO PLAY";
	string return_title = "ESC/ENTER - Back";
	BOX Title[2];
	Title[0].setBox(midWidth(SCREEN_WIDTH, instruction_title.size() + 10), SCREEN_HEIGHT / 20, instruction_title.size() + 10, 3, YELLOW, BLACK, instruction_title);
	Title[1].setBox(midWidth(SCREEN_WIDTH, return_title.size()), SCREEN_HEIGHT * 18 / 20, return_title.size(), 3, WHITE, BLACK, return_title);



	vector <BOX> content;
	content.resize(INSTRUCTION_SIZE);
	
	content[0].setBox(midWidth(SCREEN_WIDTH, INSTRUCTION[0].size()), midHeight(SCREEN_HEIGHT, content_height), INSTRUCTION[0].size(), 3, LIGHTCYAN, BLACK, INSTRUCTION[0]);
	for (int i = 1; i < content.size(); i++)
		content[i].setBox(midWidth(SCREEN_WIDTH, INSTRUCTION[i].size()), midHeight(SCREEN_HEIGHT, content_height) + (i + 5) * 3, INSTRUCTION[i].size(), 3, LIGHTCYAN, BLACK, INSTRUCTION[i]);
	


	Player player(midWidth(SCREEN_WIDTH, Player().getWidth()), midHeight(SCREEN_HEIGHT, content_height) + 4);

	int total_width_objects = Van().getWidth() + Car().getWidth() + Bird().getWidth() + Alien().getWidth();
	int gap = (SCREEN_WIDTH / 2 - total_width_objects) / 3;

	Van van(midWidth(SCREEN_WIDTH, total_width_objects + gap * 3), midHeight(SCREEN_HEIGHT, content_height) + 10);
	Car car(van.X() + Van().getWidth() + gap, midHeight(SCREEN_HEIGHT, content_height) + 10);
	Bird bird(car.X() + Car().getWidth() + gap, midHeight(SCREEN_HEIGHT, content_height) + 10);
	Alien alien(bird.X() + Bird().getWidth() + gap, midHeight(SCREEN_HEIGHT, content_height) + 10);

	player.Draw();
	van.Draw();
	car.Draw();
	bird.Draw();
	alien.Draw();

	Title[0].printBox();
	Title[1].printContent();
	for (int i = 0; i < content.size(); i++)
		content[i].printContent();
}

void drawCredits()
{
	int content_height = 2 * (CREDITS_SIZE + 2);

	string credits_title = "CREDITS";
	string return_title = "ESC/ENTER - Back";
	BOX Title[2];
	Title[0].setBox(midWidth(SCREEN_WIDTH, credits_title.size() + 10), SCREEN_HEIGHT / 20, credits_title.size() + 10, 3, YELLOW, BLACK, credits_title);
	Title[1].setBox(midWidth(SCREEN_WIDTH, return_title.size()), SCREEN_HEIGHT * 18 / 20, return_title.size(), 3, WHITE, BLACK, return_title);


	vector <BOX> content;
	content.resize(CREDITS_SIZE);

	content[0].setBox(midWidth(SCREEN_WIDTH, CREDITS[0].size()), midHeight(SCREEN_HEIGHT, content_height), CREDITS[0].size(), 3, rand() % (15) + 1, BLACK, CREDITS[0]);
	content[1].setBox(midWidth(SCREEN_WIDTH, CREDITS[1].size()), midHeight(SCREEN_HEIGHT, content_height) + 2 * 2, CREDITS[1].size(), 3, LIGHTBLUE, BLACK, CREDITS[1]);
	content[6].setBox(midWidth(SCREEN_WIDTH, CREDITS[6].size()), midHeight(SCREEN_HEIGHT, content_height) + 8 * 2, CREDITS[6].size(), 3, LIGHTBLUE, BLACK, CREDITS[6]);

	for (int i = 2; i < 6; i++)
		content[i].setBox(midWidth(SCREEN_WIDTH, CREDITS[i].size()), midHeight(SCREEN_HEIGHT, content_height) + (1+i) * 2, CREDITS[i].size(), 3, LIGHTCYAN, BLACK, CREDITS[i]);

	for (int i = 7; i < content.size(); i++)
		content[i].setBox(midWidth(SCREEN_WIDTH, CREDITS[i].size()), midHeight(SCREEN_HEIGHT, content_height) + (2+i) * 2, CREDITS[i].size(), 3, LIGHTCYAN, BLACK, CREDITS[i]);


	Title[0].printBox();
	Title[1].printContent();
	for (int i = 0; i < content.size(); i++)
		content[i].printContent();
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


void Settings_Menu()
{
	int box_width = 21;
	int box_height = 5;
	MENU settingsMenu("SETTINGS", SETTINGS, SETTINGS_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * SETTINGS_SIZE), box_width, box_height, WHITE, BLACK);

	while (true)
	{
		system("cls");
		settingsMenu.printMenu();
		int buf = settingsMenu.inputMenu();

		switch (buf)
		{
		case 0:
		{
			// MENU SETTINGS
			buf = Ask_ChangeWindowMode();
			if (buf == 0)
				FullScreenMode();
			else if (buf == 1)
			{
				WindowedMode();
				SetWindowSize(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL);
			}
			else
				break;

			FixConsoleWindow();
			HideCursor();
			SetUpParameters();
			settingsMenu.setMenu("SETTINGS", SETTINGS, SETTINGS_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * SETTINGS_SIZE), box_width, box_height, WHITE, BLACK);

			break;
		}
		case 1:
		{
			// AUDIO SETTINGS
			buf = Ask_NumberVolumes();

			SetAllVolumes(buf);

			break;
		}
		case 2:
		case -1:
			return;
		}
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
	MENU saveMenu("SAVE GAME", SAVEMENU, SavedPlayers.size() + 3, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * (SavedPlayers.size() + 3)), box_width, box_height, WHITE, BLACK);

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
	MENU loadMenu("LOAD GAME", LOADMENU, SavedPlayers.size() + 2, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * (SavedPlayers.size() + 2)), box_width, box_height, WHITE, BLACK);

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
	MENU removeMenu("Choose the Player want to delete: ", REMOVEMENU, SavedPlayers.size() + 1, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * SavedPlayers.size()), box_width, box_height, LIGHTGRAY, BLACK);

	removeMenu.printMenu();
	int buf = removeMenu.inputMenu();

	delete[]REMOVEMENU;

	return buf;
}



int Ask_ChangeWindowMode()
{
	string window_title = "WINDOW SETTINGS";
	BOX Title;
	Title.setBox(midWidth(SCREEN_WIDTH, window_title.size() + 10), SCREEN_HEIGHT / 20, window_title.size() + 10, 3, YELLOW, BLACK, window_title);

	int box_width = 21;
	int box_height = 5;
	string windowModes[] =
	{
		"FullScreen Mode",
		"Windowed Mode",
		"Cancel"
	};
	int size = sizeof(windowModes) / sizeof(string);

	MENU askWindow("Select Mode", windowModes, size, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * size), box_width, box_height, WHITE, BLACK);
	askWindow.setBoxFormat(0, box_width, box_height, LIGHTGREEN, BLACK);
	askWindow.setBoxFormat(1, box_width, box_height, LIGHTBLUE, BLACK);

	Title.printBox();
	askWindow.printMenu();

	return askWindow.inputMenu();
}
int Ask_NumberVolumes()
{
	string audio_title = "AUDIO SETTINGS";
	string guide1 = "-----Volume Range: [1 - 1000]-----";
	string guide2 = "--Type [-1] to Cancel--";
	BOX Title[3];
	Title[0].setBox(midWidth(SCREEN_WIDTH, audio_title.size() + 10), SCREEN_HEIGHT / 20, audio_title.size() + 10, 3, YELLOW, BLACK, audio_title);
	Title[1].setBox(midWidth(SCREEN_WIDTH, guide1.size()), SCREEN_HEIGHT * 4 / 20, guide1.size(), 3, LIGHTCYAN, BLACK, guide1);
	Title[2].setBox(midWidth(SCREEN_WIDTH, guide2.size()), SCREEN_HEIGHT * 6 / 20, guide2.size(), 3, LIGHTCYAN, BLACK, guide2);

	int volume = 0;
	
	string input;
	while(true) {
		system("cls");

		Title[0].printBox();
		Title[1].printContent();
		Title[2].printContent();

		GotoXY(midWidth(SCREEN_WIDTH, "Enter Volume Number: "), midHeight(SCREEN_HEIGHT, 1));
		cout << "Enter Volume Number: ";

		getline(cin, input);
		char* flag = NULL;
		volume = strtol(input.c_str(), &flag, 10);
		
		if (*flag != NULL)
		{
			system("cls");
			printMessCenter("Wrong format! Please type in a number", WHITE, RED);
			toupper(_getch());
		}
		else
			break;
	}


	return volume;
}
int Ask_SaveGame()
{
	int box_width = 21;
	int box_height = 5;
	MENU askSave("Do you want to save your progress?", YES_NO_SELECTION, YES_NO_SELECTION_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height), box_width, box_height, LIGHTGRAY, BLACK);

	askSave.printMenu();

	return askSave.inputMenu();
}

int Ask_PlayAgain()
{
	int box_width = 21;
	int box_height = 5;
	MENU askPlayAgain("Do you want to play again?", YES_NO_SELECTION, YES_NO_SELECTION_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 4 / 3, box_height), box_width, box_height, LIGHTGRAY, BLACK);

	askPlayAgain.printMenu();

	return askPlayAgain.inputMenu();
}

int Ask_PlayerName()
{
	int box_width = 21;
	int box_height = 5;
	MENU askPlayAgain("Do you want to save your score?", YES_NO_SELECTION, YES_NO_SELECTION_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 4 / 3, box_height) , box_width, box_height, LIGHTGRAY, BLACK);

	askPlayAgain.printMenu();

	return askPlayAgain.inputMenu();
}