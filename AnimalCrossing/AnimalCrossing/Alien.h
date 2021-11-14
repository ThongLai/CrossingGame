#pragma once

#include "Animal.h"

class Alien : public CANIMAL
{
private:
	string table[5] =
	{
		"    .-\"\"`\"\"-.",
		" _/`oOoOoOoOo`\\_",
		"'.-=-=-=-=-=-=-.'",
		"  `-=.=-.-=.=-'",
		"     ^  ^  ^"
	};

public:
	Alien();
	Alien(int x, int y);
	~Alien();

	void Move(int, int);
};