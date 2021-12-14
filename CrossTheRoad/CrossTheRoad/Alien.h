#pragma once

#include "Animal.h"

class Alien : public CANIMAL
{
private:
	//An one dimensional array that keeps the shape of Alien
	string table[5] =
	{
		"    .-\"\"`\"\"-.    ",
		" _/`oOoOoOoOo`\\_ ",
		"'.-=-=-=-=-=-=-.'",
		"  `-=.=-.-=.=-'  ",
		"     ^  ^  ^     "
	};
	
	//All Alien objects can only move in one direction so the static variable "direct" is every object direction
	// true -> move right, false -> move left
	static bool direct;

	//The static variable "count" will count the number of bird's steps since the last change direction 
	static int count;

public:
	//Constructor and destructor
	Alien();
	Alien(int x, int y, int text_color = LIGHTGREEN, int bg_color = BLACK);
	Alien(const Alien&);
	~Alien();

	//Getter of some properties
	bool getDirect();
	int getCount();

	//Setter of some properties
	void setDirect(bool);
	void setCount(int);

	//Turn function will negate "direct" variable to change direction
	void Turn(); 

	//Alien's Move method 
	void Move();

	// Alien's check impact occur method (this method will work with Player class)
	bool isImpact(int, int);

	//Alien's Tell method (sound when impact occurs)
	void Tell();
};