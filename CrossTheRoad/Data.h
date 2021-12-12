#pragma once

#include <time.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Data
{
private:
	//player's name
	string name;

	//current level, score
	int level, score;

	//time passed in this level
	clock_t TIME;

	//current position of player
	int x, y;
public:
	//Constructor
	Data(int level = 0, int score = 0, clock_t TIME = 0, int x = 0, int y = 0, string name = "<Empty>");

	//Setter and getter
	void setName(string);
	string getName() const;
	int getLevel() const;
	int getScore() const;
	clock_t getTime() const;
	int getX() const;
	int getY() const;

	//Overload some operator
	Data& operator=(const Data&);
	bool operator==(const string&);
	bool operator==(const Data&);
	bool operator>(const Data&);
	bool operator<(const Data&);

	//Input and output
	void input(istream&);
	void output(ostream&) const;
	friend istream& operator>>(istream&, Data&);
	friend ostream& operator<<(ostream&, const Data&);
};