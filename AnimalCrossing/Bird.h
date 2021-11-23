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
	int count;

public:
	Bird();
	Bird(int, int);
	Bird(const Bird&);
	~Bird();

	void Move();
	bool isImpact(int, int);
};