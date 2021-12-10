#pragma once

#include "Vehicle.h"

class Car : public CVEHICLE
{
	string table[3] =
	{
		"  млппплпплм   ",
		"ллллллллллллллл",
		" O          O  ",
	};

public:

	Car();
	Car(int, int, int text_color = LIGHTCYAN,int bg_color = BLACK);
	Car(const Car&);
	~Car();

	bool isImpact(int, int);

	void Move();

	void Tell();
	void SurroundingSound();
};
