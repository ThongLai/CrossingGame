#pragma once

#include "Vehicle.h"

class Van : public CVEHICLE
{
	//An one dimensional array that keeps the shape of Van
	string table[5] =
	{
		"  лпплллллллллл",
		"ллллллллллллллл",
		"ллллллллллллллл",
		"ллллллллллллллл",
		"O             O"
	};
public:
	//Constructor and destructor
	Van();
	Van(int,int, int text_color = BLUE, int bg_color = BLACK);
	Van(const Van&);
	~Van();

	//Van's Move method 
	void Move();
	
	//Van's check impact occur method (this method will work with Player class)
	bool isImpact(int,int);

	//Van's Tell method (sound when impact occurs)
	void Tell();

};