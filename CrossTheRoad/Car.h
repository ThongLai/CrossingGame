#pragma once

#include "Vehicle.h"

class Car : public CVEHICLE
{
	//An one dimensional array that keeps the shape of Car
	string table[3] =
	{
		"  млппплпплм   ",
		"ллллллллллллллл",
		" O          O  ",
	};

public:
	//Constructor and destructor
	Car();
	Car(int, int, int text_color = LIGHTCYAN,int bg_color = BLACK);
	Car(const Car&);
	~Car();

	//Car's check impact occur method (this method will work with Player class)
	bool isImpact(int, int);

	//Car's Move method 
	void Move();

	//Car's Tell method (sound when impact occurs)
	void Tell();
};
