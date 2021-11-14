#include "CGame.h"

CGame::CGame() : difficulty(0)
{
	vans.resize(5);
	bird.resize(5);
	alien.resize(5);

	for (int i = 0; i < 5; i++)
	{
		vans[i].setXY(i * 25, midHeight(ROAD_H, vans[i].getHeight()) + LAND[0]);
		bird[i].setXY(i * 25, midHeight(ROAD_H, bird[i].getHeight()) + LAND[1]);
		alien[i].setXY(i * 25, midHeight(ROAD_H, alien[i].getHeight()) + LAND[2]);
	}
}

void CGame::drawGame()
{
	Box highScoreBox(GAMEPLAY_W, 0, HIGHSCORE_W, SCREEN_HEIGHT, WHITE, BLACK);
	highScoreBox.printBox();

	Box side[2];
	side[0].setBox(0, SIDEWALK[0], GAMEPLAY_W, SIDEWALK_H, LIGHTGREEN, BLACK, "");
	side[0].printBox();
	side[1].setBox(0, SIDEWALK[1], GAMEPLAY_W, SIDEWALK_H, LIGHTGREEN, BLACK, "");
	side[1].printBox();


	Box land[4];
	for (int i = 0; i < 4; i++)
	{
		land[i].setBox(0, LAND[i], GAMEPLAY_W, ROAD_H, LIGHTCYAN, BLACK, "");
		land[i].printBox();
	}
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
