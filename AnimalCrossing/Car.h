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
	Car(int, int);

	void Move();

	bool isImpact(int, int);
};
