#include "CGame.h"

CGame::CGame() : level(0), scores(0), curSound(0), UnDeadCMD(false), START_TIME(clock() / CLOCKS_PER_SEC), TIME(0), PAUSE_TIME(0)
{
	StartUp();
	Init();
}

void CGame::Init()
{
	objNum = level / 2 + 2;
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

	drawStartFinishLine();

	drawStatusBox();
	updateGameStatus();

	vansLight.Draw();
	carLight.Draw();

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

	string angel[] =
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

void CGame::drawPauseScreen()
{
	system("cls");
	GotoXY((SCREEN_WIDTH - 5) / 2, (SCREEN_HEIGHT) / 4 - 3);
	cout << "PAUSE";

	printMessCenter("P - Back to the game");
}

void CGame::drawCommand()
{
	Status SavedStatus;
	SetTextColor(DefineColor(RED, BLACK));

	GotoXY(GAMEPLAY_W + midWidth(STATUS_W, 19), SCREEN_HEIGHT - 3);
	cout << (UnDeadCMD ? "UNDEAD COMMAND - ON" : string(19, ' '));
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
	Remove();

	++level;
	
	Init();
	drawGame();
}

void CGame::resetGame()
{
	Remove();

	level = 0;
	scores = 0;
	curSound = 0;

	START_TIME = clock() / CLOCKS_PER_SEC;
	TIME = 0;
	PAUSE_TIME = 0;

	vans.clear();
	cars.clear();
	birds.clear();
	aliens.clear();

	Init();
	drawGame();
}

void CGame::exitGame(HANDLE t)
{
	TerminateThread(t, 0);
	system("cls");
}

void CGame::pauseThread(HANDLE t)
{
	SuspendThread(t);
}

void CGame::pauseGame(HANDLE t)
{
	PAUSE_TIME = clock() / CLOCKS_PER_SEC;
	pauseThread(t);
}

void CGame::resumeThread(HANDLE t)
{
	ResumeThread(t);
}

void CGame::resumeGame(HANDLE t)
{
	START_TIME += clock() / CLOCKS_PER_SEC - PAUSE_TIME;
	TIME = clock() / CLOCKS_PER_SEC - START_TIME;

	resumeThread(t);
}

void CGame::loadGame() 
{
	string fileName = "GameData\\";
	string playerName;
	system("cls");
	cout << "Nhap ten nguoi choi de load: ";
	getline(cin, playerName);
	fileName += playerName;
	fileName += ".txt";
	Remove();
	scores = 0;
	fstream inp(fileName, ios::in);

	inp >> level >> scores >> TIME >> START_TIME;

	vans.clear();
	cars.clear();
	birds.clear();
	aliens.clear();

	system("cls");
	Init();
	drawGame();
	inp.close();
}

void CGame::saveGame() 
{
	string fileName = "GameData\\";
	string playerName;
	system("cls");

	cout << "Nhap ten nguoi choi de save: ";
	getline(cin, playerName);
	fileName += playerName;
	fileName += ".txt";
	fstream out(fileName, ios::out);

	out << level << " " << scores << " " << TIME << " " << START_TIME;

	out.close();
	system("cls");
	drawGame();
}


void CGame::updatePosPeople(char MOVING)
{

	switch (MOVING)
	{
	case 'W':
	case KEY_UP:
		player.UP();
		checkDrawLines();
		break;

	case 'A':
	case KEY_LEFT:
		player.LEFT();
		checkDrawLines();
		break;

	case 'D':
	case KEY_RIGHT:
		player.RIGHT();
		checkDrawLines();
		break;

	case 'S':
	case KEY_DOWN:
		player.DOWN();
		checkDrawLines();
		break;
	}
}

void CGame::updatePosVehicle(int time)
{
	//Thay doi den giao thong
	if (time % 30 == 0) vansLight.changeLight();
	if (time % 50 == 0) carLight.changeLight();

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

void CGame::updateTime()
{
	if (clock() / CLOCKS_PER_SEC - START_TIME - TIME < 1)
		return;

	TIME = clock() / CLOCKS_PER_SEC - START_TIME;
	scores -= scores > 0 ? 1 : 0;

	GotoXY(GAMEPLAY_W + midWidth(STATUS_W, STATUSVAR[0].size() + 10) + 3 +STATUSVAR[0].size(), midHeight(SCREEN_HEIGHT, STATUSVAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5);
	cout << setfill('0') << setw(2) << TIME / 3600 << ":" << setfill('0') << setw(2) << (TIME / 60) % 60 << ":" << setfill('0') << setw(2) << TIME % 60 << endl;
}

void CGame::updateGameStatus()
{
	GotoXY(GAMEPLAY_W + midWidth(STATUS_W, STATUSVAR[0].size() + 10) + 3 + STATUSVAR[0].size(), midHeight(SCREEN_HEIGHT, STATUSVAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + 2);
	cout << level;

	GotoXY(GAMEPLAY_W + midWidth(STATUS_W, STATUSVAR[0].size() + 10) + 3 + STATUSVAR[0].size(), midHeight(SCREEN_HEIGHT, STATUSVAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + 4);
	cout << string(STATUS_W - (midWidth(STATUS_W, STATUSVAR[0].size() + 10) + 3 + STATUSVAR[0].size() + 1), ' ');

	GotoXY(GAMEPLAY_W + midWidth(STATUS_W, STATUSVAR[0].size() + 10) + 3 + STATUSVAR[0].size(), midHeight(SCREEN_HEIGHT, STATUSVAR_SIZE + GUIDEBUTTONS_SIZE + 1) * 3 / 5 + 4);
	cout << scores;

	drawCommand();
}



bool CGame::checkImpact()
{
	if (UnDeadCMD)
		return false;

	if (player.Y() >= LANE[0])
		return player.isImpact<Vans>(vans);
	if (player.Y() >= LANE[1])
		return player.isImpact<Car>(cars);
	if (player.Y() >= LANE[2])
		return player.isImpact<Bird>(birds);
	if (player.Y() >= LANE[3])
		return player.isImpact<Alien>(aliens);

	return false;
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
		scores += 100;
		checkPoint[0] = true;
	}
	else if (!checkPoint[1] && player.Y() == LANE[1])
	{
		scores += 200;
		checkPoint[1] = true;
	}	
	else if (!checkPoint[2] && player.Y() == LANE[2])
	{
		scores += 300;
		checkPoint[2] = true;
	}	
	else if (!checkPoint[3] && player.Y() == LANE[3])
	{
		scores += 400;
		checkPoint[3] = true;
	}
}

int CGame::getPoint()
{
	return scores;
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

void CGame::soundEffects()
{
	if (player.Y() >= LANE[0] && curSound == 0)
	{
		vans[0].SurroundingSound();
		curSound = 1;
	}
	else if (player.Y() >= LANE[1])
	{ 
		cars[0].SurroundingSound();
		//xiu lam tiep
	}
	else if (player.Y() >= LANE[2])
	{
		birds[0].SurroundingSound();
	}
	else if (player.Y() >= LANE[3])
	{
		aliens[0].SurroundingSound();
	}
}

void CGame::checkDrawLines()
{
	if (player.Y() + player.getHeight() >= SIDEWALK[0] - 1 || (player.Y() >= SIDEWALK[1] && player.Y() <= SIDEWALK[1] + SIDEWALK_H - 1))
	{
		drawStartFinishLine();
		player.Draw();
	}
}
