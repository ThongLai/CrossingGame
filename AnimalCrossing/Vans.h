#pragma once

#include "Vehicle.h"

class Vans : public CVEHICLE
{
	string table[5] =
	{
		"  лпплллллллллл",
		"ллллллллллллллл",
		"ллллллллллллллл",
		"ллллллллллллллл",
		"O             O"
	};
public:
	Vans();
	Vans(int,int);
	Vans(const Vans&);
	~Vans();

	void Move();
	
	bool isImpact(int,int);
};