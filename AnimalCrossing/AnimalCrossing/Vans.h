#pragma once

#include "Vehicle.h"

class Vans : public CVEHICLE
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

	Vans();
	Vans(int,int);

	void Move(int, int);

	void Draw();
	
	bool isImpact(int,int);

	void moveLeft();
};

