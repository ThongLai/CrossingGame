﻿#include "Window.h"
#include "Menu.h"
#include "Bird.h"
#include "Alien.h"
#include "Van.h"
#include "Player.h"
#include "CGame.h"


using namespace std;

CGame game;
int buf = 0;

void SubThread() {

	int time = 0;
    while (true) {

		if (game.checkImpact() || game.isFinish() || buf == 'P' || buf == 'R' || buf == 'M' || buf == 'L' || buf == ESC)
			game.pauseGame();
		

		while (game.isPause()) {}

		game.drawCommand();

		if (game.updatePosPeople(buf))
			buf = 0;

		game.updatePosAnimal();
		game.updatePosVehicle((++time)%=51);

		game.calcPoint();

		game.updateTime();
		game.updateGameStatus();

		game.soundEffects();

        Sleep(100);
    }
}


int main()
{
    thread sub(SubThread);
	LoadPlayerList();

	int box_width = 20;
	int box_height = 3;
	MENU MainMenu("Main Menu", MAINMENU_SIZE, MAINMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT*3/2, box_height * MAINMENU_SIZE), box_width, box_height, WHITE, BLACK);

	while (true)
	{
		system("cls");
		Title();
		MainMenu.printMenu();
		mciSendString(TEXT("play Menu_Theme repeat"), NULL, 0, NULL);

		buf = MainMenu.inputMenu();
		switch (buf)
		{
		case 0:
		{
			system("cls");
			printMessCenter("LOADING GAME...");
			Sleep(1000);

			game.resetGame();

			mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
			mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

			game.resumeThread();

			break;
		}
		case 1:
		{
			if (game.loadGame() <= -1)
				continue;

			mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
			mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

			game.resumeThread();

			break;
		}
		case 2:
		{
			system("cls");
			printMessCenter(MAINMENU[2] + " is selected");
			Sleep(1000);

			break;
		}
		case 3:
		{
			system("cls");
			printMessCenter(MAINMENU[3] + " is selected");
			Sleep(1000);

			break;
		}
		case 4:
		{
			system("cls");
			printMessCenter(MAINMENU[4] + " is selected");
			Sleep(1000);

			break;
		}
		case 5:
		{
			system("cls");
			printMessCenter(MAINMENU[5] + " is selected");
			Sleep(1000);

			break;
		}
		case 6:
		{
			system("cls");
			printMessCenter(MAINMENU[6] + " is selected");
			Sleep(1000);

			break;
		}
		case 7:
		{
			system("cls");
			printMessCenter(MAINMENU[7] + " is selected");
			Sleep(1000);

			break;
		}
		}
		if (buf == -1 || buf == 6)
		{
			system("cls");

			sub.detach();
			SavePlayerList();			
			break;
		}






		do
		{
			if (_kbhit())
			{
				buf = toupper(_getch());

				if (buf == 'P')
				{
					while (!game.isPause()) {}

					game.drawPauseScreen();

					do {
						buf = toupper(_getch());
					} while (buf != 'P');

					game.drawGame();
					
					buf = 0;
					game.resumeGame();
				}
				else if (buf == 'R')
				{
					while (!game.isPause()) {}

					game.resetGame();

					buf = 0;
					game.resumeThread();
				}
				else if (buf == 'M')
				{
					while (!game.isPause()) {}

					game.saveGame();

					buf = 0;
					game.resumeGame();
				}
				else if (buf == 'L')
				{
					while (!game.isPause()) {}

					if (game.loadGame() <= -1)
						game.drawGame();

					buf = 0;
					game.resumeThread();
				}
				else if (buf == ESC)
				{
					while (!game.isPause()) {}
					mciSendString(TEXT("pause Gameplay_Theme"), NULL, 0, NULL);

					break;
				}
				else
					game.addBuf(buf);
			}
			else if (game.checkImpact())
			{
				while (!game.isPause()) {}
				mciSendString(TEXT("stop Gameplay_Theme"), NULL, 0, NULL);
				system("cls");
				game.drawDeadMenu();

				if (Ask_PlayAgain() == 0)
				{
					//Neu chon muon choi lai
					system("cls");
					mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

					game.resetGame();
					game.resumeThread();
				}
				else
				{
					//Neu chon khong muon choi lai
					break;
				}
			}        
			else if (game.isFinish()) //Đây là if kết thúc
			{
				while (!game.isPause()) {}

				game.nextRound();
				game.resumeThread();
			}

		} while (true);

	}


    return 0;
}