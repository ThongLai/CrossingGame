#include "Animal.h"






CANIMAL::CANIMAL() : mX(0), mY(0), width(0), height(0), text_color(WHITE), bg_color(BLACK) {}

void CANIMAL::Tell()
{
	//ANIMAL CRYING SOUND HERE
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



void CALIEN::Move(int x, int y)
{
	while ((mX != x || mY != y) && PLAYGAME)
	{
		remove();

		if (mX < x) mX++;
		else if (mX > x) mX--;

		if (mY < y) mY++;
		else if (mY > y) mY--;

		draw();
	}
}

CALIEN::CALIEN() : CANIMAL()
{
	height = sizeof(ALIEN) / sizeof(string);

	int max_width = ALIEN[0].size();
	for (int i = 0; i < height; i++)
		if (max_width < ALIEN[i].size())
			max_width = ALIEN[i].size();

	width = max_width;
}

CALIEN::~CALIEN()
{
	height = 0;
	width = 0;
	mX = mY = 0;
}

void CALIEN::draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
	{
		GotoXY(mX, iy);
		cout << ALIEN[i];
	}
}

void CALIEN::remove()
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