#include "Player.h"

Player::Player() : mX(LAND[0] + ROAD_H), mY(midWidth(GAMEPLAY_W, width)), text_color(WHITE), bg_color(BLACK), mState(1)
{
	height = sizeof(table) / sizeof(string);
	width = table[0].size();
}

Player::~Player()
{
	height = width = 0;
	mX = mY = 0;
	text_color = bg_color = 0;
}

int Player::X()
{
	return mX;
}

int Player::Y()
{
	return mY;
}

void Player::setX(int x)
{
	mX = x;
}

void Player::setY(int x)
{
	mY = x;
}

void Player::setXY(int x, int y)
{
	mX = x;
	mY = y;
}

void Player::Draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
	{
		GotoXY(mX, iy);
		cout << table[i];
	}
}

void Player::Remove()
{
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	for (int iy = mY; iy < mY + height; iy++)
		for (int ix = mX; ix < mX + width; ix++)
		{
			GotoXY(ix, iy);
			cout << " ";
		}
}


void Player::UP()
{
	if (mY == SIDEWALK[1])
		return;
	else
	{
		Remove();
		setY(mY - 1);
		Draw();
	}
	
}

void Player::DOWN()
{
	if (mY == SIDEWALK[0])
		return;
	else
	{
		Remove();
		setY(mY + 1);
		Draw();
	}
}

void Player::LEFT()
{
	if (mX == 0)
		return;
	else
	{
		Remove();
		setX(mX - 1);
		Draw();
	}
}

void Player::RIGHT()
{
	if (mX + width == GAMEPLAY_W)
		return;
	else
	{
		Remove();
		setX(mX + 1);
		Draw();
	}
}

bool Player::isDead()
{
	return !mState;
}

bool Player::drawDead()
{

	string s[100] =
	{

"            ,-.-.       ",
"           / ,-. \\      ",
"      ,-. ( |a a| ) ,-.     ",
"     :   `( : o ; )'   :       ",
" ___|____(.>-<._)____|____",
"(|        /     \\        |)",
" ||      :  `.|,' :       ||",
"  |___..--|_\\_|_/_|-...___| ",
"    ;     | /SSt\\ | :",
"   /  ;  ;| ,'|`. |:  :  \\",
"  /  /| /|;._____.:|\\ |\\  \\",
" / ,' ' /  ;| |:  \\ ' `. \\",
" '     /  / | | \\  \\     '",
"       /  /  ; :  \\  \\",
"      /  /  /| |\\  \\  \\",
"     /  /  / | | \\  \\  \\",
"    /  /  /  ; :  \\  \\  \\",
"   /  /  /  /| |\\  \\  \\  \\",
"  (  /  /  / | | \\  \\  \\  )",
"   `(_ /  /  ; :  \\  \\ _)'",
"      '.(_./___\\._).'",
	};


	int box_width = 20;
	int box_height = 5;
	MENU DeadMenu("Do you want to play again?", DEADMENU_SIZE, DEADMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height) * 4 / 3, box_width, box_height, LIGHTGRAY, BLACK);

	int buf = 0;
	Status SavedState;

	system("cls");
	int y = 0;
	int x = SCREEN_HEIGHT + 19;
	for (int i = 0; i < 21; i++)
	{

		PrintString(x, y, s[i]);
		y++;
	}
	DeadMenu.printMenu();
	buf = DeadMenu.inputMenu();

	switch (buf)
	{
	case 0:
	{
		system("cls");
		printMessCenter(DEADMENU[0] + " is selected");
		Sleep(1000);
		SavedState.ResetToCurrent();
		//Neu chon muon choi lai
		return true;

		break;
	}
	case 1:
	{
		system("cls");
		printMessCenter(DEADMENU[1] + " is selected");
		Sleep(1000);
		SavedState.ResetToCurrent();
		//Neu chon khong muon choi lai
		return false;
		break;
	}
	}
	//nhan nut ESC
	if (buf == -1 || buf == 1)
		return false;
	system("pause");
	return true;
}