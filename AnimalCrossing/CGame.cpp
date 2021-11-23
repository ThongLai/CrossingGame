#include "CGame.h"

CGame::CGame() : difficulty(0), objNum(2)
{
	vans.resize(objNum);
	cars.resize(objNum);
	bird.resize(objNum);
	alien.resize(objNum);

	for (int i = 0; i < objNum; i++)
	{
		vans[i].setXY(i * (Distance(vans[0].getWidth(), objNum) + vans[0].getWidth()), midHeight(ROAD_H, vans[i].getHeight()) + LAND[0]);
		cars[i].setXY(i * (Distance(cars[0].getWidth(), objNum) + cars[0].getWidth()), midHeight(ROAD_H, cars[i].getHeight()) + LAND[1]);
		bird[i].setXY(i * (Distance(bird[0].getWidth(), objNum) + bird[0].getWidth()), midHeight(ROAD_H, bird[i].getHeight()) + LAND[2]);
		alien[i].setXY(i * (Distance(alien[0].getWidth(), objNum) + alien[0].getWidth()), midHeight(ROAD_H, alien[i].getHeight()) + LAND[3]);
	}

	vansLight.setXY(GAMEPLAY_W, LAND[0]);
	carLight.setXY(GAMEPLAY_W, LAND[1]);

	player.setXY(midWidth(GAMEPLAY_W, 3), SIDEWALK[0]);
}

void CGame::drawGame()
{
	Box highScoreBox(GAMEPLAY_W, 0, HIGHSCORE_W, SCREEN_HEIGHT, WHITE, BLACK);
	highScoreBox.printBox();

	Box side[2];
	side[0].setBox(0, SIDEWALK[0], GAMEPLAY_W, SIDEWALK_H, LIGHTGREEN, BLACK, "START");
	side[0].printBox();
	side[1].setBox(0, SIDEWALK[1], GAMEPLAY_W, SIDEWALK_H, LIGHTGREEN, BLACK, "FINISH");
	side[1].printBox();

	vansLight.initDraw();
	carLight.initDraw();

	for (int i = 0; i < objNum; i++)
	{
		vans[i].Draw();
		cars[i].Draw();
		bird[i].Draw();
		alien[i].Draw();
	}

	player.Draw();
}

CGame::~CGame()
{

}

Player CGame::getPeople()
{
	return player;
}

vector<CVEHICLE> CGame::getVehicle()
{
	return vector<CVEHICLE>();
}

vector<CANIMAL> CGame::getAnimal()
{
	return vector<CANIMAL>();
}
void CGame::resumeGame(HANDLE t)
{
	ResumeThread(t);
}

void CGame::pauseGame(HANDLE t)
{
	SuspendThread(t);
}
void CGame::exitGame(HANDLE t)
{
	TerminateThread(t, 0);
	system("cls");
}

void CGame::updatePosPeople(char MOVING)
{
	
	if (MOVING == ' ') return;

	if (MOVING == 'W') player.UP();
	else
		if (MOVING == 'A') player.LEFT();
		else
			if (MOVING == 'D') player.RIGHT();
			else
				if (MOVING == 'S') player.DOWN();
}

void CGame::updatePosVehicle()
{

}

void CGame::updatePosAnimal()
{

}