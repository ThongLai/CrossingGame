#pragma once

#include "Vehicle.h"

class Van : public CVEHICLE
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
	Van();
	Van(int,int);
	Van(const Van&);
	~Van();

	void Move();
	
	bool isImpact(int,int);

	void Tell();
	void SurroundingSound();
};