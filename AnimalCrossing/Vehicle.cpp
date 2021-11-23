#include "Vehicle.h"

CVEHICLE::CVEHICLE() : mX(0), mY(0), width(0), height(0), text_color(WHITE), bg_color(BLACK) {}

CVEHICLE::~CVEHICLE()
{
	mX = mY = 0;
	width = height = 0;
	text_color = bg_color = 0;
}

void CVEHICLE::Tell()
{
	//ANIMAL CRYING SOUND HERE
}

void CVEHICLE::Remove()
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

void CVEHICLE::Draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	if (mX >= 0 && mX + width <= GAMEPLAY_W)
	{
		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << vehicle_table[i];
		};
	}
	else if (mX + width > GAMEPLAY_W)
	{
		int part2_length = (mX + width) - GAMEPLAY_W;
		int part1_length = width - part2_length;

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << vehicle_table[i].substr(0, part1_length);
		}

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(0, iy);
			cout << vehicle_table[i].substr(part1_length, part2_length);
		}
	}
}

int CVEHICLE::X()
{
	return mX;
}

int CVEHICLE::Y()
{
	return mY;
}

int CVEHICLE::getHeight()
{
	return height;
}

int CVEHICLE::getWidth()
{
	return width;
}

void CVEHICLE::setX(int x)
{
	mX = x;
}

void CVEHICLE::setY(int y)
{
	mY = y;
}

void CVEHICLE::setXY(int x, int y)
{
	mX = x;
	mY = y;
}

void CVEHICLE::setColor(int _text_color, int _bg_color)
{
	text_color = _text_color;
	bg_color = _bg_color;
}