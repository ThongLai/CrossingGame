#pragma once

#include "Animal.h"

class Bird : public CANIMAL
{
private:
	string table[5] =
	{
		"      /'{>     ",
		"  ____) (____  ",
		" //'-;   ;-'\\\\ ",
		"//////\\_/\\\\\\\\\\\\",
		"      m m      ",
	};

	static bool direct; //Bien quy dinh huong di chuyen cua object, true la qua phai, false la qua trai
	static int count; //Bien dem so buoc cua object ke tu lan cuoi object doi huong

public:
	Bird();
	Bird(int, int, int text_color = BROWN, int bg_color = BLACK);
	Bird(const Bird&);
	~Bird();

	bool getDirect();
	int getCount();

	void setDirect(bool);
	void setCount(int);

	void Turn(); //Function doi huong cua object

	void Move(); //Function di chuyen cua object
	bool isImpact(int, int); //Function tra ve gia tri bool true neu nguoi va cham voi object

	void Tell();
	void SurroundingSound();
};