#include "Animal.h"

CANIMAL::CANIMAL() : mX(0), mY(0), width(0), height(0), text_color(WHITE), bg_color(BLACK) {}

CANIMAL::~CANIMAL()
{
	mX = mY = 0;
	width = height = 0;
	text_color = bg_color = 0;
}

void CANIMAL::Tell()
{
	//ANIMAL CRYING SOUND HERE
}

void CANIMAL::Remove()
{
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	if (mX >= 0 && mX + width <= GAMEPLAY_W)
	{
		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << string(width, ' ');
		};

		return;
	}
	else if (mX + width > GAMEPLAY_W)
	{
		int part2_length = (mX + width) - GAMEPLAY_W;
		int part1_length = width - part2_length;

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << string(part1_length, ' ');
		}

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(0, iy);
			cout << string(part2_length, ' ');
		}

		return;
	}
}

void CANIMAL::Draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	if (mX >= 0 && mX + width <= GAMEPLAY_W)
	{
		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << animal_table[i];
		};
	}
	else if (mX + width > GAMEPLAY_W)
	{
		int part2_length = (mX + width) - GAMEPLAY_W;
		int part1_length = width - part2_length;

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << animal_table[i].substr(0, part1_length);
		}

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(0, iy);
			cout << animal_table[i].substr(part1_length, part2_length);
		}
	}
}

int CANIMAL::X()
{
	return mX;
}

int CANIMAL::Y()
{
	return mY;
}

int CANIMAL::getHeight()
{
	return height;
}

int CANIMAL::getWidth()
{
	return width;
}

void CANIMAL::setX(int x)
{
	mX = x;
}

void CANIMAL::setY(int y)
{
	mY = y;
}

void CANIMAL::setXY(int x, int y)
{
	mX = x;
	mY = y;
}

void CANIMAL::setColor(int _text_color, int _bg_color)
{
	text_color = _text_color;
	bg_color = _bg_color;
}