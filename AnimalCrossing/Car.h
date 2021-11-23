#pragma once
#include<string>
#include"Vehicle.h"

using namespace std;

class Car : public CVEHICLE
{
	string table[3] =
	{
		"  млппплпплм   ",
		"ллллллллллллллл",
		" O          O  ",
	};

public:

	Car();
	Car(int, int);
	Car(const Car&);
	~Car();

	bool isImpact(int, int);

	void Move();
};
