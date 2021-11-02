#include<iostream>
#include "Vans.h"
#include"ConsoleTask.h"
#include"Trafficlight.h"
#include<Windows.h>

using namespace std;
int main()
{
	Trafficlight a(10,20,true);

	a.initDraw();

	Sleep(20);
	while (1)
	{
		
		a.changeLight();
		Sleep(10000);
	}
}