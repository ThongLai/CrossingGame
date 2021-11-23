#include"Bird.h"

Bird::Bird() : CANIMAL(), direct(true), round(3), count(0)
{
	animal_table = table;
	height = sizeof(table) / sizeof(string);
	width = table[0].size();
}

Bird::Bird(int x, int y) : Bird()
{
	mX = x;
	mY = y;
}

Bird::Bird(const Bird& b) : Bird(b.mX, b.mY)
{
	
}

Bird::~Bird()
{
	
}

void Bird::Move()
{
	//Xoa object
	Remove();

	//Neu rand() chia het cho x => doi huong
	if (rand() % 20 == 0)
	{
	    //Neu bien dem >=4 thi moi doi huong de tranh viec object di chuyen lac qua lac lai
	    if (count >= 4)
	    {
	        //Doi huong va set lai bien dem count = 0
	        count = 0;
	        if (direct == true)
	            direct = false;
	        else direct = true;
	    }
	}    

	//Tang hoac giam toa do X tuy theo object di chuyen qua trai hay phai
	if (direct)
	{
		++mX;
		++count;
		if (mX == GAMEPLAY_W)
			mX = 0;
	}
	else
	{
		--mX;
		++count;
		if (mX < 0)
			mX = GAMEPLAY_W - 1;
	}

	//Ve object
	Draw();
}

bool Bird::isImpact(int x, int y)
{
	if (x <= X() - 3 || x >= X() + 15 || y <= Y() - 3 || y >= Y() + 5) return false;
	else
	{
		if (y == Y() - 2)
		{
			if (x <= X() + 3 || x >= X() + 10) return false;
			else return true;
		}

		if (y == Y() - 1)
		{
			if (x <= X() - 1 || x >= X() + 13) return false;
			else return true;
		}
		
		if (y == Y())
		{
			if (x <= X() - 2 || x >= X() + 14) return false;
			else return true;
		}

		if (y == Y() + 1) return true;

		if (y == Y() + 2) return true;

		if (y == Y() + 3) return true;

		if (y == Y() + 4)
		{
			if (x <= X() + 3 || x >= X() + 9) return false;
			else return true;
		}
	}
}