#pragma once ANIMAL_H_
#include "Window.h"

extern string ALIEN[];

class CANIMAL
{
protected:
	int mX, mY;
	int height, width;
	int text_color, bg_color;

	string ALIEN[5] =
	{
		"    .-\"\"`\"\"-.",
		" _/`oOoOoOoOo`\\_",
		"'.-=-=-=-=-=-=-.'",
		"  `-=.=-.-=.=-'",
		"     ^  ^  ^"
	};

public:
	CANIMAL();

	//Moving pattern for each animal
	virtual void Move(int, int) = 0;
	virtual void Tell();
	
	int X();
	int Y();
	int getHeight();
	int getWidth();

	void setXY(int, int);
	void setColor(int, int);
};

class CALIEN : public CANIMAL
{
public:
	CALIEN();
	~CALIEN();

	void Move(int, int);

	void draw();
	void remove();
};