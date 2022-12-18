#include "CGame.h"

CGame::CGame() : difficulty(0), point(0), totalPoint(0)
{
	Init();
}

void CGame::Init()
{
	objNum = difficulty / 2 + 2;
	if (objNum > 4)
		objNum = 4;

	vans.resize(objNum);
	cars.resize(objNum);
	bird.resize(objNum);
	alien.resize(objNum);

	for (int i = 0; i < 4; ++i)
		checkPoint[i] = false;

	for (int i = 0; i < objNum; ++i)
	{
		vans[i].setXY(i * (Distance(vans[0].getWidth(), objNum) + vans[0].getWidth()), midHeight(ROAD_H, vans[i].getHeight()) + LANE[0]);
		cars[i].setXY(i * (Distance(cars[0].getWidth(), objNum) + cars[0].getWidth()), midHeight(ROAD_H, cars[i].getHeight()) + LANE[1]);
		bird[i].setXY(i * (Distance(bird[0].getWidth(), objNum) + bird[0].getWidth()), midHeight(ROAD_H, bird[i].getHeight()) + LANE[2]);
		alien[i].setXY(i * (Distance(alien[0].getWidth(), objNum) + alien[0].getWidth()), midHeight(ROAD_H, alien[i].getHeight()) + LANE[3]);
	}

	vansLight.setXY(GAMEPLAY_W, LANE[0]);
	carLight.setXY(GAMEPLAY_W, LANE[1]);

	player.setXY(midWidth(GAMEPLAY_W, 3), SIDEWALK[0]);
}

void CGame::drawGame()
{
	BOX highScoreBox(GAMEPLAY_W, 0, HIGHSCORE_W, SCREEN_HEIGHT, WHITE, BLACK);
	highScoreBox.printBox();

	BOX side[2];
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

void CGame::Remove()
{
	for (int i = 0; i < objNum; i++)
	{
		vans[i].Remove();
		cars[i].Remove();
		bird[i].Remove();
		alien[i].Remove();
	}

	player.Remove();
}

void CGame::nextRound()
{
	totalPoint += point;
	point = 0;
	Remove();

	++difficulty;
	
	Init();
	drawGame();
}

void CGame::resetGame()
{
	Remove();

	difficulty = 0;
	point = 0;
	totalPoint = 0;

	vans.clear();
	cars.clear();
	bird.clear();
	alien.clear();

	Init();
	drawGame();
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

void CGame::updatePosVehicle(int time)
{
	//Thay doi den giao thong
	if (time % 30 == 0) vansLight.changeLight();
	if (time % 50 == 0)carLight.changeLight();

	//Di chuyen xe
	if (vansLight.getState())
		for (int i = 0; i < objNum; ++i)
			vans[i].Move();

	if (carLight.getState())
		for (int i = 0; i < objNum; ++i)
			cars[i].Move();
}

void CGame::updatePosAnimal()
{
	//Di chuyen Bird
	//Neu rand() chia het cho x => doi huong
	if (rand() % 20 == 0)
	{
		//Neu bien dem >=4 thi moi doi huong de tranh viec object di chuyen lac qua lac lai
		if (bird[0].getCount() >= 10)
		{
			//Doi huong va set lai bien dem count = 0
			bird[0].setCount(0);
			bird[0].Turn();
		}
	}

	for (int i = 0; i < objNum; ++i)
		bird[i].Move();

	//Di chuyen Alien
	//Neu bien count bang khoang cach thi alien quay dau
	if (alien[0].getCount() >= (objNum * Distance(alien[0].getWidth(), objNum)))
	{
		alien[0].setCount(0);
		alien[0].Turn();
	}

	for (int i = 0; i < objNum; ++i)
		alien[i].Move();
}

bool CGame::checkImpact()
{
	if (player.Y() >= LANE[0])
		return player.isImpact<Vans>(vans, objNum);
	else if (player.Y() >= LANE[1])
		return player.isImpact<Car>(cars, objNum);
	else if (player.Y() >= LANE[2])
		return player.isImpact<Bird>(bird, objNum);
	else if (player.Y() >= LANE[3])
		return player.isImpact<Alien>(alien, objNum);
	else return false;
}

bool CGame::isFinish()
{
	if (player.Y() == SIDEWALK[1])
		return true;
	else return false;
}

void CGame::calcPoint()
{
	if (!checkPoint[0] && player.Y() == LANE[0])
	{
		point += 100;
		checkPoint[0] = true;
	}
	else if (!checkPoint[1] && player.Y() == LANE[1])
	{
		point += 200;
		checkPoint[1] = true;
	}	
	else if (!checkPoint[2] && player.Y() == LANE[2])
	{
		point += 300;
		checkPoint[2] = true;
	}	
	else if (!checkPoint[3] && player.Y() == LANE[3])
	{
		point += 400;
		checkPoint[3] = true;
	}
	else --point;
}

int CGame::getPoint()
{
	return totalPoint + point;
}
