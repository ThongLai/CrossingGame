#pragma once

#include"Window.h"
#include "Car.h"
#include "Vans.h"
#include "Alien.h"
#include "Bird.h"

class Player
{
	int mX, mY;
	int height, width;
	int text_color, bg_color;

	bool mState;	//1 is alive - 0 is dead
	string table[3]= {
	 " ",
	 "���",
	"/ \\"
	};


public:

	Player();
	~Player();

	int X();
	int Y();

	void setX(int);
	void setY(int);
	void setXY(int x, int y);

	void Draw();
	void remove();
	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	bool isDead();

	bool isImpact(int objNum, vector<Vans>, vector<Car>, vector<Bird>, vector<Alien>);

	bool isImpactVehicle(CVEHICLE*);
	bool isImpactAnimal(CANIMAL*);
};