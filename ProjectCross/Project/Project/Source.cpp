#include<iostream>
#include "Vans.h"
#include"ConsoleTask.h"
#include"Trafficlight.h"
#include<Windows.h>
#include"People.h"

using namespace std;
int main()
{
	People a;
	a.initDraw();
	ConsoleTask::hideCursor();

	while (1)
	{
		char temp = _getwch();
		
		if (temp == 27) break;
		else if (temp == 119)
		{
			a.initDraw();
			a.UP();
		}
		else if (temp == 115)
		{
			a.initDraw();
			a.DOWN();
		}
		else if (temp == 97)
		{
			a.initDraw();
			a.LEFT();
		}
		else if (temp == 100)
		{
			a.initDraw();
			a.RIGHT();
		}
		
	}
}