#include "CGame.h"

CGame::CGame() : difficulty(0), point(0), totalPoint(0), UnDeadCMD(false)
{
	StartUp();
	Init();
}

void CGame::Init()
{
	objNum = difficulty / 2 + 2;
	if (objNum > 4)
		objNum = 4;

	vans.resize(objNum);
	cars.resize(objNum);
	birds.resize(objNum);
	aliens.resize(objNum);

	for (int i = 0; i < 4; ++i)
		checkPoint[i] = false;

	for (int i = 0; i < objNum; ++i)
	{
		vans[i].setXY(i * (Distance(vans[0].getWidth(), objNum) + vans[0].getWidth()), midHeight(ROAD_H, vans[i].getHeight()) + LANE[0]);
		vans[i].setColor(BLUE, BLACK);

		cars[i].setXY(i * (Distance(cars[0].getWidth(), objNum) + cars[0].getWidth()), midHeight(ROAD_H, cars[i].getHeight()) + LANE[1]);
		cars[i].setColor(LIGHTCYAN, BLACK);

		birds[i].setXY(i * (Distance(birds[0].getWidth(), objNum) + birds[0].getWidth()), midHeight(ROAD_H, birds[i].getHeight()) + LANE[2]);
		birds[i].setColor(BROWN, BLACK);

		aliens[i].setXY(i * (Distance(aliens[0].getWidth(), objNum) + aliens[0].getWidth()), midHeight(ROAD_H, aliens[i].getHeight()) + LANE[3]);
		aliens[i].setColor(LIGHTGREEN, BLACK);
	}

	vansLight.setXY(GAMEPLAY_W, LANE[0]);
	carLight.setXY(GAMEPLAY_W, LANE[1]);

	player.setXY(midWidth(GAMEPLAY_W, 3), SIDEWALK[0]);
	player.setColor(LIGHTGRAY, BLACK);
}

void CGame::drawGame()
{
	system("cls");

	BOX highScoreBox(GAMEPLAY_W, 0, STATUS_W, SCREEN_HEIGHT, WHITE, BLACK);
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
		birds[i].Draw();
		aliens[i].Draw();
	}

	player.Draw();
}

void CGame::drawDeadMenu()
{
	system("cls");

	string angel[21] =
	{
	"            ,-.-.       ",
	"           / ,-. \\      ",
	"      ,-. ( |a a| ) ,-.     ",
	"     :   `( : o ; )'   :       ",
	" ____|____(_.>-<._)____|____",
	"(_|        /     \\        |_)",
	" ||      :  `.|,' :       ||",
	"  |___..--|_\\_|_/_|-...___| ",
	"    ;     | /SSt\\ | :",
	"   /  ;  ;| ,'|`. |:  :  \\",
	"  /  /| /|;._____.:|\\ |\\  \\",
	" / ,' `' /  ;| |:  \\ `' `. \\",
	" `'     /  / | | \\  \\     `'",
	"       /  /  ; :  \\  \\",
	"      /  /  /| |\\  \\  \\",
	"     /  /  / | | \\  \\  \\",
	"    /  /  /  ; :  \\  \\  \\",
	"   /  /  /  /| |\\  \\  \\  \\",
	"  (  /  /  / | | \\  \\  \\  )",
	"   `(_ /  /  ; :  \\  \\ _)'",
	"      `'.(_./___\\._).`'",
	};


	int angel_height = sizeof(angel) / sizeof(string);

	for (int i = 0; i < angel_height; i++)
	{

		GotoXY(midWidth(SCREEN_WIDTH, angel[3].size()), midHeight(SCREEN_HEIGHT, angel_height) * 2 / 20 + i);
		cout << angel[i];
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
		birds[i].Remove();
		aliens[i].Remove();
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
	birds.clear();
	aliens.clear();

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
		if (birds[0].getCount() >= 10)
		{
			//Doi huong va set lai bien dem count = 0
			birds[0].setCount(0);
			birds[0].Turn();
		}
	}

	for (int i = 0; i < objNum; ++i)
		birds[i].Move();

	//Di chuyen Alien
	//Neu bien count bang khoang cach thi alien quay dau
	if (aliens[0].getCount() >= (objNum * Distance(aliens[0].getWidth(), objNum)))
	{
		aliens[0].setCount(0);
		aliens[0].Turn();
	}

	for (int i = 0; i < objNum; ++i)
		aliens[i].Move();
}

bool CGame::checkImpact()
{
	if (UnDeadCMD)
		return false;

	if (player.Y() >= LANE[0])
		return player.isImpact<Vans>(vans);
	else if (player.Y() >= LANE[1])
		return player.isImpact<Car>(cars);
	else if (player.Y() >= LANE[2])
		return player.isImpact<Bird>(birds);
	else if (player.Y() >= LANE[3])
		return player.isImpact<Alien>(aliens);
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

void CGame::addBuf(char key)
{
	if (CCODE.compare(0, buf.size() + 1, buf + key) == 0)
	{
		buf.push_back(key);
		CheckUnDeadCMD();
	}
	else
	{
		buf.clear();
		buf.push_back(key);
	}
}

void CGame::CheckUnDeadCMD()
{
	if (buf == CCODE)
	{
		UnDeadCMD = !UnDeadCMD;
		buf.clear();
	}
}
