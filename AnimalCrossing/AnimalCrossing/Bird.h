#pragma once

#include "Animal.h"

class Bird : public CANIMAL
{
private:
	string table[5] =
	{
		"      /'{>     ",
		"  ____) (____  ",
		" //'-;   ;-'\\\\ ",
		"//////\\_/\\\\\\\\\\\\",
		"      m m      ",
	};

	bool direct;
	int round;

public:
	Bird();
	Bird(int, int);
	~Bird();

	void Move(int, int);
	bool isImpact(int, int);
};