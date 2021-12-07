#include "Data.h"

Data::Data(string n, int l, int s, clock_t T, int _x, int _y) : name(n), level(l), score(s), TIME(T), x(_x), y(_y)
{

}

void Data::setName(string name)
{
	this->name = name;
}

string Data::getName() const
{
	return name;
}

int Data::getLevel() const
{
	return level;
}

int Data::getScore() const
{
	return score;
}

clock_t Data::getTime() const
{
	return TIME;
}

int Data::getX() const
{
	return x;
}

int Data::getY() const
{
	return y;
}

void Data::input(istream& inDev)
{
	inDev >> name;
	inDev >> level;
	inDev >> score;
	inDev >> TIME;
	inDev >> x;
	inDev >> y;
}

void Data::output(ostream& outDev) const
{
	outDev << name << endl;
	outDev << level << endl;
	outDev << score << endl;
	outDev << TIME << endl;
	outDev << x << endl;
	outDev << y;
}

Data& Data::operator=(const Data& data)
{
	if (this == &data)
		return *this;

	name = data.name;
	level = data.level;
	score = data.score;
	TIME = data.TIME;
	x = data.x;
	y = data.y;

	return *this;
}

bool Data::operator==(const Data& data)
{
	return (name == data.name && level == data.level && score == data.score && TIME == data.TIME);
}

bool Data::operator==(const string& name)
{
	return (this->name == name);
}

bool Data::operator>(const Data& data)
{
	if (score == data.score)
	{
		if (level == data.level)
		{
			if (TIME == data.TIME)
			{
				if (name > data.name)
					return true;
				else
					return false;
			}
			else if (TIME > data.TIME)
				return true;
			else
				return false;
		}
		else if (level > data.level)
			return true;
		else
			return false;
	}
	else if (score > data.score)
		return true;
	else
		return false;
}

bool Data::operator<(const Data& data)
{
	if (score == data.score)
	{
		if (level == data.level)
		{
			if (TIME == data.TIME)
			{
				if (name < data.name)
					return true;
				else
					return false;
			}
			else if (TIME < data.TIME)
				return true;
			else
				return false;
		}
		else if (level < data.level)
			return true;
		else
			return false;
	}
	else if (score < data.score)
		return true;
	else
		return false;
}

istream& operator>>(istream& inDev, Data& data)
{
	data.input(inDev);

	return inDev;
}

ostream& operator<<(ostream& outDev, const Data& data)
{
	data.output(outDev);

	return outDev;
}
