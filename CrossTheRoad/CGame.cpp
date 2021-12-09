#include "CGame.h"

CGame::CGame() : level(0), objNum(0), score(0), START_TIME(clock() / CLOCKS_PER_SEC), TIME(0), PAUSE_TIME(0), pause(true), running(false), UnDeadCMD(false)
{
	StartUp();

	Init();
}

CGame::~CGame()
{
	resetData();
}

void CGame::Init()
{
	for (int i = 0; i < 4; ++i)
		checkPoint[i] = false;

	player.setXY(midWidth(GAMEPLAY_W, 3), SIDEWALK[0]);
	player.setColor(LIGHTGRAY, BLACK);

	vansLight.setXY(GAMEPLAY_W, LANE[0]);
	carLight.setXY(GAMEPLAY_W, LANE[1]);

	if (Distance(Van().getWidth(), objNum + 1) < MAX_DISTANCE)
		return;


	objNum = level / 2 + 2;

	vans.resize(objNum);
	cars.resize(objNum);
	birds.resize(objNum);
	aliens.resize(objNum);

	for (int i = 0; i < objNum; ++i)
	{
		vans[i].setXY(i * (Distance(vans[i].getWidth(), objNum) + vans[i].getWidth()), midHeight(ROAD_H, vans[i].getHeight()) + LANE[0]);
		vans[i].setColor(BLUE, BLACK);

		cars[i].setXY(i * (Distance(cars[i].getWidth(), objNum) + cars[i].getWidth()), midHeight(ROAD_H, cars[i].getHeight()) + LANE[1]);
		cars[i].setColor(LIGHTCYAN, BLACK);

		birds[i].setXY(i * (Distance(birds[i].getWidth(), objNum) + birds[i].getWidth()), midHeight(ROAD_H, birds[i].getHeight()) + LANE[2]);
		birds[i].setColor(BROWN, BLACK);

		aliens[i].setXY(i * (Distance(aliens[i].getWidth(), objNum) + aliens[i].getWidth()), midHeight(ROAD_H, aliens[i].getHeight()) + LANE[3]);
		aliens[i].setColor(LIGHTGREEN, BLACK);
	}
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

void CGame::processAfterGame()
{
	drawArt(game_over, game_over_height, midWidth(SCREEN_WIDTH, game_over_width), midHeight(SCREEN_HEIGHT, game_over_height), LIGHTRED);
	Sleep(2000);

	system("cls");

	mciSendString(TEXT("play Finish_Game from 0"), NULL, 0, NULL);
	drawScoreBoard(Data(level, score, TIME, player.X(), player.Y()));

	if (Ask_PlayerName() == 0)
	{
		system("cls");

		Data playerData(level, score, TIME);
		string name;

		GotoXY(midWidth(SCREEN_WIDTH, "Enter Your Name: "), midHeight(SCREEN_HEIGHT, 1));
		cout << "Enter Your Name: ";

		getline(cin, name);
		playerData.setName(name);

		AddDataToLeaderBoard(playerData);


		system("cls");

		drawLeaderBoard();

		toupper(_getch());
	}


	system("cls");

	drawArt(angel, angel_height, midWidth(SCREEN_WIDTH, angel_width), midHeight(SCREEN_HEIGHT, angel_height) * 2 / 20);

	if (Ask_PlayAgain() == 0)
	{
		//Neu chon muon choi lai
		system("cls");
		mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

		resetGame();
		resumeThread();
	}
	else
	{
		pause = true;
		running = false;
	}

	SavePlayerSaves();
	SaveLeaderBoard();
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

Player CGame::getPeople()
{
	return player;
}

vector<CVEHICLE*> CGame::getVehicle()
{
	vector <CVEHICLE*> vehicle;

	for (int i = 0; i < vans.size(); i++)
		vehicle.push_back(&vans[i]);
	for (int i = 0; i < cars.size(); i++)
		vehicle.push_back(&cars[i]);

	return vehicle;
}

vector<CANIMAL*> CGame::getAnimal()
{
	vector <CANIMAL*> animal;

	for (int i = 0; i < birds.size(); i++)
		animal.push_back(&birds[i]);
	for (int i = 0; i < aliens.size(); i++)
		animal.push_back(&aliens[i]);

	return animal;
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

void CGame::nextLevel()
{
	mciSendString(TEXT("play Next_Level from 0"), NULL, 0, NULL);

	Remove();

	++level;
	
	Init();
}

void CGame::resetGame()
{
	resetData();

	Init();
}

void CGame::exitGame()
{
	resetData();
	Init();

	system("cls");

	if (running && Ask_SaveGame() == 0)
		saveGame();		

	SavePlayerSaves();
	SaveLeaderBoard();

	running = false;
}

void CGame::pauseThread()
{
	pause = true;
}

void CGame::pauseGame()
{
	PAUSE_TIME = clock() / CLOCKS_PER_SEC;
	pauseThread();
}

void CGame::resumeThread()
{
	drawGame();

	pause = false;
	running = true;
}

void CGame::resumeGame()
{
	START_TIME += clock() / CLOCKS_PER_SEC - PAUSE_TIME;
	TIME = clock() / CLOCKS_PER_SEC - START_TIME;

	resumeThread();
}

void CGame::loadGame() 
{
	system("cls");

	int buf = Load_Menu();

	if (buf < SavedPlayers.size())
	{
		resetData();

		level = SavedPlayers[buf].getLevel();
		score = SavedPlayers[buf].getScore();
		TIME = SavedPlayers[buf].getTime();
		START_TIME = clock() / CLOCKS_PER_SEC - TIME;

		Init();
		player.setXY(SavedPlayers[buf].getX(), SavedPlayers[buf].getY());

		int j = 2;
		while (checkImpact())
		{
			for (int i = 0; i < objNum; ++i)
			{
				vans[i].setXY(i * (Distance(vans[0].getWidth(), objNum) + vans[0].getWidth()) + player.getWidth()*j, midHeight(ROAD_H, vans[i].getHeight()) + LANE[0]);
				cars[i].setXY(i * (Distance(cars[0].getWidth(), objNum) + cars[0].getWidth()) + player.getWidth() * j, midHeight(ROAD_H, cars[i].getHeight()) + LANE[1]);
				birds[i].setXY(i * (Distance(birds[0].getWidth(), objNum) + birds[0].getWidth()) + player.getWidth() * j, midHeight(ROAD_H, birds[i].getHeight()) + LANE[2]);
				aliens[i].setXY(i * (Distance(aliens[0].getWidth(), objNum) + aliens[0].getWidth()) + player.getWidth() * j, midHeight(ROAD_H, aliens[i].getHeight()) + LANE[3]);
			}

			birds[0].Turn();
			aliens[0].Turn();
			
			j++;
		}

		running = true;
	}
	else if (buf == SavedPlayers.size())
	{
		system("cls");
		buf = Remove_Menu();

		while (buf >= 0 && buf < SavedPlayers.size())
		{
			RemovePlayer(buf);
			
			system("cls");
			printMessCenter("DELETED!");
			Sleep(1000);
			system("cls");

			buf = Remove_Menu();
		}
	}
}

void CGame::saveGame() 
{
	system("cls");

	int buf = Save_Menu();
	
	if (buf < SavedPlayers.size())
	{
		Data playerData(level, score, TIME, player.X(), player.Y(), SavedPlayers[buf].getName());
		SavePlayer(playerData, buf);
	}
	else if (buf == SavedPlayers.size())
	{
		system("cls");

		Data playerData(level, score, TIME, player.X(), player.Y());
		string name;

		GotoXY(midWidth(SCREEN_WIDTH, "Enter Your Name: "), midHeight(SCREEN_HEIGHT, 1));
		cout << "Enter Your Name: ";

		getline(cin, name);
		playerData.setName(name);

		AddPlayer(playerData);

		SavePlayerSaves();
	}
	else if (buf == SavedPlayers.size() + 1)
	{
		system("cls");
		buf = Remove_Menu();

		while (buf >= 0 && buf < SavedPlayers.size())
		{
			RemovePlayer(buf);

			system("cls");
			printMessCenter("DELETED!");
			Sleep(1000);
			system("cls");

			buf = Remove_Menu();
		}
	}
}


bool CGame::updatePosPeople(char MOVING)
{
	switch (MOVING)
	{
	case 'W':
		player.UP();
		checkDrawLines();
		return true;

	case 'A':
		player.LEFT();
		checkDrawLines();
		return true;

	case 'D':
		player.RIGHT();
		checkDrawLines();
		return true;

	case 'S':
		player.DOWN();
		checkDrawLines();
		return true;
	}

	return false;
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
	score -= score > 0 ? 1 : 0;

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
	cout << score;

	drawCommand();
}



bool CGame::checkImpact()
{
	if (UnDeadCMD)
		return false;

	if (player.Y() >= LANE[0])
		return player.isImpact<Van>(vans);
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
	if (player.Y() <= SIDEWALK[1])
		return true;
	
	return false;
}

void CGame::calcPoint()
{
	if (!checkPoint[0] && player.Y() == LANE[0])
	{
		mciSendString(TEXT("play Plus_Point from 0"), NULL, 0, NULL);
		score += 100;
		checkPoint[0] = true;
	}
	else if (!checkPoint[1] && player.Y() == LANE[1])
	{
		mciSendString(TEXT("play Plus_Point from 0"), NULL, 0, NULL);
		score += 200;
		checkPoint[1] = true;
	}	
	else if (!checkPoint[2] && player.Y() == LANE[2])
	{
		mciSendString(TEXT("play Plus_Point from 0"), NULL, 0, NULL);
		score += 300;
		checkPoint[2] = true;
	}	
	else if (!checkPoint[3] && player.Y() == LANE[3])
	{
		mciSendString(TEXT("play Plus_Point from 0"), NULL, 0, NULL);
		score += 400;
		checkPoint[3] = true;
	}
}

int CGame::getPoint()
{
	return score;
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

void CGame::resetData()
{
	Remove();

	objNum = 2;
	level = 0;
	score = 0;

	START_TIME = clock() / CLOCKS_PER_SEC;
	TIME = 0;
	PAUSE_TIME = 0;
	UnDeadCMD = false;

	vans.clear();
	cars.clear();
	birds.clear();
	aliens.clear();
}

bool CGame::isPause()
{
	return pause;
}

bool CGame::isPlaying()
{
	return running;
}

void CGame::checkDrawLines()
{
	if (player.Y() + player.getHeight() >= SIDEWALK[0] - 1 || (player.Y() >= SIDEWALK[1] && player.Y() <= SIDEWALK[1] + SIDEWALK_H - 1))
	{
		drawStartFinishLine();
		player.Draw();
	}
}
