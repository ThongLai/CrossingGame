#pragma once

#include "Animal.h"

class Alien : public CANIMAL
{
private:
	string table[5] =
	{
		"    .-\"\"`\"\"-.    ",
		" _/`oOoOoOoOo`\\_ ",
		"'.-=-=-=-=-=-=-.'",
		"  `-=.=-.-=.=-'  ",
		"     ^  ^  ^     "
	};
	
	static bool direct; //Bien quy dinh huong di chuyen cua object, true la qua phai, false la qua trai
	static int count; //Bien dem so buoc cua object ke tu lan cuoi object doi huong

public:
	Alien();
	Alien(int x, int y, int text_color = LIGHTGREEN, int bg_color = BLACK);
	Alien(const Alien&);
	~Alien();

	bool getDirect();
	int getCount();

	void setDirect(bool);
	void setCount(int);

	void Turn(); //Function doi huong cua object

	//Bi loi phan lu dau
	void Move();
	bool isImpact(int, int);

	void Tell();
	void SurroundingSound();
};