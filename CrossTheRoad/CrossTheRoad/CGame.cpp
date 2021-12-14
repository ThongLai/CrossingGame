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
	//Reset checkPoint
	for (int i = 0; i < 4; i++)
		checkPoint[i] = false;

	//Set the init position of the player
	player.setXY(midWidth(GAMEPLAY_W, 3), SIDEWALK[0]);

	//Set the init position of 2 traffic lights
	vanLight.setXY(GAMEPLAY_W, LANE[0]);
	carLight.setXY(GAMEPLAY_W, LANE[1]);

	//Check if the Distance reaches the limit or not to prevent the overwhelming of the number of obstacles
	if (Distance(Van().getWidth(), objNum + 1) < MIN_DISTANCE)
		return;

	//Increase the number of objects in each road
	objNum = level / 2 + 2;

	vans.resize(objNum);
	cars.resize(objNum);
	birds.resize(objNum);
	aliens.resize(objNum);

	//Set the init positions of the obstacle objects
	for (int i = 0; i < objNum; ++i)
	{
		vans[i].setXY(i * (Distance(vans[i].getWidth(), objNum) + vans[i].getWidth()), midHeight(ROAD_H, vans[i].getHeight()) + LANE[0]);
		cars[i].setXY(i * (Distance(cars[i].getWidth(), objNum) + cars[i].getWidth()), midHeight(ROAD_H, cars[i].getHeight()) + LANE[1]);
		birds[i].setXY(i * (Distance(birds[i].getWidth(), objNum) + birds[i].getWidth()), midHeight(ROAD_H, birds[i].getHeight()) + LANE[2]);
		aliens[i].setXY(i * (Distance(aliens[i].getWidth(), objNum) + aliens[i].getWidth()), midHeight(ROAD_H, aliens[i].getHeight()) + LANE[3]);
	}
}

void CGame::drawGame()
{
	system("cls");
	
	//Draw the screen
	drawStartFinishLine();

	drawStatusBox();
	updateGameStatus();

	//Draw all the objects
	vanLight.Draw();
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

void CGame::drawPauseScreen()
{
	system("cls");
	GotoXY((SCREEN_WIDTH - 5) / 2, (SCREEN_HEIGHT) / 4 - 3);
	cout << "PAUSE";

	printMessCenter("P - Back to the game");
}

void CGame::displayCommand()
{
	Status SavedStatus;
	SetTextColor(DefineColor(RED, BLACK));

	GotoXY(GAMEPLAY_W + midWidth(STATUS_W, 19), SCREEN_HEIGHT - 3);
	cout << (UnDeadCMD ? "UNDEAD COMMAND - ON" : string(19, ' '));
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



Player CGame::getPlayer()
{
	return player;
}

vector<CVEHICLE*>& CGame::getVehicle()
{
	vector <CVEHICLE*> vehicle;

	for (int i = 0; i < vans.size(); i++)
		vehicle.push_back(&vans[i]);
	for (int i = 0; i < cars.size(); i++)
		vehicle.push_back(&cars[i]);

	return vehicle;
}

vector<CANIMAL*>& CGame::getAnimal()
{
	vector <CANIMAL*> animal;

	for (int i = 0; i < birds.size(); i++)
		animal.push_back(&birds[i]);
	for (int i = 0; i < aliens.size(); i++)
		animal.push_back(&aliens[i]);

	return animal;
}

int CGame::getPoint()
{
	return score;
}



void CGame::resetGame()
{
	resetData();

	Init();
}

void CGame::exitGame()
{
	system("cls");

	//Ask player to save game before exiting
	if (running && Ask_SaveGame() == 0)
		saveGame();

	resetData();
	Init();

	SavePlayerSaves();
	SaveLeaderBoard();

	running = false;
}

void CGame::loadGame()
{
	system("cls");

	//Display Load Game menu and take the input from the player
	int buf = Load_Menu();

	if (buf < SavedPlayers.size()) //Load from an existing save file
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
				vans[i].setXY(i * (Distance(vans[0].getWidth(), objNum) + vans[0].getWidth()) + player.getWidth() * j, midHeight(ROAD_H, vans[i].getHeight()) + LANE[0]);
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
	else if (buf == SavedPlayers.size())  //Delete a file option
	{
		system("cls");

		//Display Remove File menu and take the input from the player
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

	//Display Load Game menu and take the input from the player
	int buf = Save_Menu();

	if (buf < SavedPlayers.size()) //Save to an existing save file
	{
		Data playerData(level, score, TIME, player.X(), player.Y(), SavedPlayers[buf].getName());
		SavePlayer(playerData, buf);
	}
	else if (buf == SavedPlayers.size())
	{
		Status SavedStatus;
		system("cls");

		Data playerData(level, score, TIME, player.X(), player.Y());
		string name;

		GotoXY(midWidth(SCREEN_WIDTH, "Enter Your Name: "), midHeight(SCREEN_HEIGHT, 1));
		cout << "Enter Your Name: ";
		SetTextColor(DefineColor(LIGHTCYAN, BLACK));

		getline(cin, name);
		playerData.setName(name);

		AddPlayer(playerData);

		SavePlayerSaves();
	}
	else if (buf == SavedPlayers.size() + 1) //Delete a file option
	{
		system("cls");

		//Display Remove File menu and take the input from the player
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



bool CGame::updatePosPlayer(char MOVING)
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
	//Change the light
	if (time % 30 == 0) vanLight.changeLight();
	if (time % 50 == 0) carLight.changeLight();

	//Move Van and Car base on the state of Traffic Light
	if (vanLight.getState())
		for (int i = 0; i < objNum; ++i)
			vans[i].Move();

	if (carLight.getState())
		for (int i = 0; i < objNum; ++i)
			cars[i].Move();
}

void CGame::updatePosAnimal()
{
	//Move Bird
	//Randomly change Bird's direction
	if (rand() % 20 == 0)
	{
		//Only change direction when [count] >= 10 to prevent the abnormal movement
		if (birds[0].getCount() >= 10)
		{
			birds[0].setCount(0);
			birds[0].Turn();
		}
	}

	for (int i = 0; i < objNum; ++i)
		birds[i].Move();

	//Move Alien
	//Only change direction when [count] >= distance
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
	//Only update when the [TIME] fluctuates more than 1 second
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

	displayCommand();
}

void CGame::calcScore()
{
	//Add a score corresponding to a particular road
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



void CGame::nextLevel()
{
	//Play next level sound effect
	mciSendString(TEXT("play Next_Level from 0"), NULL, 0, NULL);

	Remove();

	++level;

	Init();
}

void CGame::processAfterGame()
{
	//Draw the GAMEOVER art
	drawArt(game_over, game_over_height, midWidth(SCREEN_WIDTH, game_over_width), midHeight(SCREEN_HEIGHT, game_over_height), LIGHTRED);
	Sleep(2000);

	system("cls");

	//Play the finish game theme
	mciSendString(TEXT("play Finish_Game from 0"), NULL, 0, NULL);

	//Display score board contains [level], [score], [TIME] values
	displayScoreBoard(Data(level, score, TIME, player.X(), player.Y()));

	//Ask player to save the progress
	if (Ask_PlayerName() == 0)
	{
		Status SavedStatus;
		system("cls");

		Data playerData(level, score, TIME);
		string name;

		GotoXY(midWidth(SCREEN_WIDTH, "Enter Your Name: "), midHeight(SCREEN_HEIGHT, 1));
		cout << "Enter Your Name: ";
		SetTextColor(DefineColor(LIGHTCYAN, BLACK));

		getline(cin, name);
		playerData.setName(name);

		AddDataToLeaderBoard(playerData);


		system("cls");

		displayLeaderBoard();

		toupper(_getch());
	}


	system("cls");

	//Draw the ANGEL art
	drawArt(angel, angel_height, midWidth(SCREEN_WIDTH, angel_width), midHeight(SCREEN_HEIGHT, angel_height) * 2 / 20);

	//Ask player to play again
	if (Ask_PlayAgain() == 0)
	{
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

	//Save progress
	SavePlayerSaves();
	SaveLeaderBoard();
}



bool CGame::checkImpact()
{
	//If the UNDEAD mode is actived, the player will become invisible
	if (UnDeadCMD)
		return false;

	//Check the impact corresponding to each road
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

void CGame::checkDrawLines()
{
	if (player.Y() + player.getHeight() >= SIDEWALK[0] - 1 || (player.Y() >= SIDEWALK[1] && player.Y() <= SIDEWALK[1] + SIDEWALK_H - 1))
	{
		drawStartFinishLine();
		player.Draw();
	}
}

bool CGame::isFinish()
{
	if (player.Y() <= SIDEWALK[1])
		return true;
	
	return false;
}

bool CGame::isPause()
{
	return pause;
}

bool CGame::isPlaying()
{
	return running;
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