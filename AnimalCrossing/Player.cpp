#include "Player.h"

Player::Player() : mX(0), mY(0), text_color(WHITE), bg_color(BLACK), mState(1)
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

int Player::getHeight()
{
	return height;
}

int Player::getWidth()
{
	return width;
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
	Remove();
	setY(mY - 1);
	Draw();
}

void Player::DOWN()
{
	Remove();
	setY(mY + 1);
	Draw();
}

void Player::LEFT()
{
	Remove();
	setX(mX - 1);
	Draw();
}

void Player::RIGHT()
{
	Remove();
	setX(mX + 1);
	Draw();
}