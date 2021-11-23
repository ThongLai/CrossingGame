#include"People.h"


People::People()
{
	height = sizeof(PEOPLE) / sizeof(string);

	int max_width = PEOPLE[0].size();
	for (int i = 0; i < height; i++)
		if (max_width < PEOPLE[i].size())
			max_width = PEOPLE[i].size();

	width = max_width;

	mX = 0;
	mY = 0;
	mState = 1;
	text_color = WHITE;
	bg_color = BLACK;
}

People::~People()
{
	height = width = 0;
	mX = mY = 0;
}

int People::X()
{
	return mX;
}

int People::Y()
{
	return mY;
}

void People::setX(int x)
{
	mX = x;
}

void People::setY(int x)
{
	mY = x;
}

void People::setXY(int x, int y)
{
	mX = x;
	mY = y;
}

void People::draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
	{
		GotoXY(mX, iy);
		cout << PEOPLE[i];
	}
}

void People::remove()
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


void People::UP()
{
	remove();
	setY(mY - 1);
	draw();
}

void People::DOWN()
{
	remove();
	setY(mY + 1);
	draw();
}

void People::LEFT()
{
	remove();
	setX(mX - 1);
	draw();
}

void People::RIGHT()
{
	remove();
	setX(mX + 1);
	draw();
}