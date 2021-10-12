#pragma once Character

#ifndef _CHARACTER_H
#define _CHARACTER_H

class Character
{
	int x, y;

public:

	//Get value X and Y
	int getX();
	int getY();

	//Assign value X and Y
	void assignX(int);
	void assignY(int);

};
#endif // !_CHARACTER_H

