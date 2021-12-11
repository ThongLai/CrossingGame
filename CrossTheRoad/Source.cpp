#include "Window.h"
#include "Menu.h"
#include "Bird.h"
#include "Alien.h"
#include "Van.h"
#include "Player.h"
#include "CGame.h"

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


		game.updateTime();
		game.updateGameStatus();

        Sleep(100);
    }
}


int main()
{


	printMessCenter("LOADING ...");

    thread sub(SubThread);
	LoadPlayerSaves();
	LoadLeaderBoard();
	OpenSoundFiles();

	int box_width = 20;
	int box_height = 3;
	MENU MainMenu("MAIN MENU", MAINMENU, MAINMENU_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 3 / 2, box_height * MAINMENU_SIZE), box_width, box_height, WHITE, BLACK);

	while (true)
	{
		system("cls");
		drawArt(title, title_height, midWidth(SCREEN_WIDTH, title_width), midHeight(SCREEN_HEIGHT / 2, title_height), rand() % (15) + 1);
		MainMenu.printMenu();
		mciSendString(TEXT("play Menu_Theme repeat"), NULL, 0, NULL);

		buf = MainMenu.inputMenu();
		switch (buf)
		{
		case 0:
		{
			system("cls");
			printMessCenter("LOADING ...");

			game.resetGame();
			system("cls");

			mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
			mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

			game.resumeThread();

			break;
		}
		case 1:
		{
			system("cls");

			game.loadGame();
			system("cls");

			if (!game.isPlaying())
				continue;

			mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
			mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

			game.resumeThread();

			break;
		}
		case 2:
		{
			system("cls");

			drawLeaderBoard();

			toupper(_getch());

			break;
		}
		case 3:
		{
			system("cls");

			drawInstruction();

			do {
				buf = toupper(_getch());
			} while (buf != ESC && buf != ENTER);

			break;
		}
		case 4:
		{
			system("cls");

			Settings_Menu();
			
			MainMenu.setMenu("MAIN MENU", MAINMENU, MAINMENU_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 3 / 2, box_height * MAINMENU_SIZE), box_width, box_height, WHITE, BLACK);
			break;
		}
		case 5:
		{
			system("cls");

			drawCredits();

			do {
				buf = toupper(_getch());
			} while (buf != ESC && buf != ENTER);

			break;

			break;
		}
		}
		if (buf == -1 || buf == 6)
		{
			system("cls");
			printMessCenter("GOOD BYE! :-)", rand() % 15 + 1, BLACK);
			Sleep(1000);

			sub.detach();
			break;
		}






		while (game.isPlaying())
		{
			game.calcPoint();

			if (_kbhit())
			{
				buf = toupper(_getch());

				if (buf == 'P')
				{
					while (!game.isPause()) {}

					mciSendString(TEXT("pause Gameplay_Theme"), NULL, 0, NULL);

					game.drawPauseScreen();

					do {
						buf = toupper(_getch());
					} while (buf != 'P');

					mciSendString(TEXT("resume Gameplay_Theme"), NULL, 0, NULL);

					buf = 0;
					game.resumeGame();
				}
				else if (buf == 'R')
				{
					while (!game.isPause()) {}

					game.resetGame();

					mciSendString(TEXT("play Gameplay_Theme from 0"), NULL, 0, NULL);

					buf = 0;
					game.resumeThread();
				}
				else if (buf == 'M')
				{
					while (!game.isPause()) {}

					mciSendString(TEXT("pause Gameplay_Theme"), NULL, 0, NULL);

					game.saveGame();

					mciSendString(TEXT("resume Gameplay_Theme"), NULL, 0, NULL);

					buf = 0;
					game.resumeGame();
				}
				else if (buf == 'L')
				{
					while (!game.isPause()) {}

					mciSendString(TEXT("pause Gameplay_Theme"), NULL, 0, NULL);

					game.loadGame();

					mciSendString(TEXT("resume Gameplay_Theme"), NULL, 0, NULL);

					buf = 0;
					game.resumeThread();
				}
				else if (buf == ESC)
				{
					while (!game.isPause()) {}

					mciSendString(TEXT("stop Gameplay_Theme"), NULL, 0, NULL);

					game.exitGame();

					mciSendString(TEXT("play Menu_Theme from 0 repeat"), NULL, 0, NULL);

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

				game.processAfterGame();

				if (!game.isPlaying()) //Neu chon khong muon choi lai
				{
					mciSendString(TEXT("play Menu_Theme from 0 repeat"), NULL, 0, NULL);
					break;
				}
			}
			else if (game.isFinish()) //Đây là if kết thúc
			{
				while (!game.isPause()) {}

				game.nextLevel();
				game.resumeThread();
			}
		}
	}

    return 0;
}