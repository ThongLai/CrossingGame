#include "Player.h"

Player::Player() : mX(10), mY(10), text_color(WHITE), bg_color(BLACK), mState(1)
{
	height = sizeof(table) / sizeof(string);

	int max_width = table[0].size();
	for (int i = 0; i < height; i++)
		if (max_width < table[i].size())
			max_width = table[i].size();

	width = max_width;
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

void Player::draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
	{
		GotoXY(mX, iy);
		cout << table[i];
	}
}

void Player::remove()
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
	remove();
	setY(mY - 1);
	draw();
}

void Player::DOWN()
{
	remove();
	setY(mY + 1);
	draw();
}

void Player::LEFT()
{
	remove();
	setX(mX - 1);
	draw();
}

void Player::RIGHT()
{
	remove();
	setX(mX + 1);
	draw();
}

