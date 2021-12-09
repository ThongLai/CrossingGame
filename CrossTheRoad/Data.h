#pragma once

#include <time.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Data
{
private:
	string name;
	int level, score;
	clock_t TIME;
	int x, y;

	//vector <Van> vans;
	//vector <Car> cars;
	//vector <Alien> aliens;
	//vector <Bird> birds;
public:
	Data(int level = 0, int score = 0, clock_t TIME = 0, int x = 0, int y = 0, string name = "<Empty>");

	void setName(string);

	string getName() const;
	int getLevel() const;
	int getScore() const;
	clock_t getTime() const;
	int getX() const;
	int getY() const;

	void input(istream&);
	void output(ostream&) const;

	Data& operator=(const Data&);

	bool operator==(const string&);

	bool operator==(const Data&);
	bool operator>(const Data&);
	bool operator<(const Data&);

	friend istream& operator>>(istream&, Data&);
	friend ostream& operator<<(ostream&, const Data&);
};