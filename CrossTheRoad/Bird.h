#pragma once

#include "Animal.h"

class Bird : public CANIMAL
{
private:
	//An one dimensional array that keeps the shape of Bird
	string table[5] =
	{
		"      /'{>     ",
		"  ____) (____  ",
		" //'-;   ;-'\\\\ ",
		"//////\\_/\\\\\\\\\\\\",
		"      m m      ",
	};

	//All Bird objects can only move in one direction so the static variable "direct" is every object direction
	// true -> move right, false -> move left
	static bool direct; 

	//The static variable "count" will count the number of bird's steps since the last change direction 
	static int count;

public:
	//Constructor and destructor
	Bird();
	Bird(int, int, int text_color = BROWN, int bg_color = BLACK);
	Bird(const Bird&);
	~Bird();

	//Getter of some properties
	bool getDirect();
	int getCount();

	//Setter of some properties
	void setDirect(bool);
	void setCount(int);

	//Turn function will negate "direct" variable to change direction
	void Turn();

	//Bird's Move method 
	void Move(); 

	// Bird's check impact occur method (this method will work with Player class)
	bool isImpact(int, int); 

	//Bird's Tell method (sound when impact occurs)
	void Tell();
};