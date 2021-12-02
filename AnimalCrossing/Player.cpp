#include "Player.h"

Player::Player() : mX(LANE[0] + ROAD_H), mY(midWidth(GAMEPLAY_W, width)), text_color(WHITE), bg_color(BLACK), mState(1)
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

void Player::setColor(int _text_color, int _bg_color)
{
	text_color = _text_color;
	bg_color = _bg_color;
}

void Player::Draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

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

void Player::drawDead()
{





}