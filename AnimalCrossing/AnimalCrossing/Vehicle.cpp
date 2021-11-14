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