#pragma once

#include "Vehicle.h"

class Van : public CVEHICLE
{
	string table[5] =
	{
		"  �������������",
		"���������������",
		"���������������",
		"���������������",
		"O             O"
	};
public:
	Van();
	Van(int,int, int text_color = BLUE, int bg_color = BLACK);
	Van(const Van&);
	~Van();

	void Move();
	
	bool isImpact(int,int);

	void Tell();
	void SurroundingSound();
};