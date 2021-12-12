#include "Player.h"

Player::Player() : mX(LANE[0] + ROAD_H), mY(midWidth(GAMEPLAY_W, width)), text_color(WHITE), bg_color(BLACK), mState(1)
{
	height = sizeof(table) / sizeof(string);
	width = table[0].size();
}

Player::Player(int x, int y, int text_color, int bg_color) : Player()
{
	mX = x;
	mY = y;

	this->text_color = text_color;
	this->bg_color = bg_color;
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

int Player::getHeight()
{
	return height;
}

int Player::getWidth()
{
	return width;
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

void Player::setColor(int _text_color, int _bg_color)
{
	text_color = _text_color;
	bg_color = _bg_color;
}

void Player::Draw()
{
	//Get color
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));
	// Print each chars of Player shape 
	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			if (table[i][j] != ' ')
			{
				GotoXY(mX + j, mY + i);
				cout << table[i][j];
			}
}

void Player::Remove()
{
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	for (int i = 0; i < height; ++i)
		for (int j = 0; j < width; ++j)
			if (table[i][j] != ' ')
			{
				GotoXY(mX + j, mY + i);
				cout << " ";
			}
}


void Player::UP()
{
	// If Player is at finish line => Can't go up 
	if (mY == SIDEWALK[1])
		return;
	else
	{
		// Print Player going up animation
		Remove();
		setY(mY - 1);
		Draw();
	}
	
}

void Player::DOWN()
{
	// If Player is at start line => Can't go down 
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
	// If Player is at the left side of screen => Can't go left 
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
	// If Player is at the right side of screen => Can't go right
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
