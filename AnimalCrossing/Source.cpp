#include "Menu.h"
#include "Bird.h"
#include "Alien.h"
#include "Vans.h"
#include "Player.h"
#include "CGame.h"

using namespace std;

CGame game;
int buf = 0;
bool isPause = false;

void SubThread() {

	int time = 0;
    while (true) {
		

		game.drawCommand();

		game.updatePosPeople(buf);
		buf = 0;
		time++;

		game.updatePosAnimal();
		game.updatePosVehicle(time);

		game.calcPoint();

		game.updateTime();
		game.updateGameStatus();

		game.soundEffects();

        //Đây là if kết thúc
        if (game.getPeople().Y() == SIDEWALK[1])
        {
            game.nextRound();
            continue;
        }
		else if (game.checkImpact())
		{
			isPause = true;
			while (isPause) {}
		}

        Sleep(100);
    }
}

int main()
{
    thread sub(SubThread);
	game.pauseThread(sub.native_handle());


	int box_width = 20;
	int box_height = 3;
	MENU MainMenu("Main Menu", MAINMENU_SIZE, MAINMENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * MAINMENU_SIZE), box_width, box_height, WHITE, BLACK);

	while (true)
	{
		system("cls");
		MainMenu.printMenu();
		mciSendString(TEXT("play Menu_Theme from 0 repeat"), NULL, 0, NULL);

		buf = MainMenu.inputMenu();




		switch (buf)
		{
		case 0:
		{
			system("cls");
			printMessCenter("LOADING GAME...");
			Sleep(1000);

			mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
			mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

			game.resetGame();
			game.resumeThread(sub.native_handle());





			break;
		}
		case 1:
		{
			system("cls");

			game.resumeThread(sub.native_handle());

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
		if (buf == -1 || buf == 7)
		{
			//game.exitGame(sub.native_handle());
			break;
		}






		do
		{
			if (_kbhit())
			{
				buf = toupper(_getch());

				if (buf == 'P')
				{
					game.pauseGame(sub.native_handle());
					game.drawPauseScreen();

					do {
						buf = toupper(_getch());
					} while (buf != 'P');

					game.drawGame();
					game.resumeGame(sub.native_handle());
				}
				else if (buf == 'M')
				{
					game.pauseGame(sub.native_handle());
					game.saveGame();
					game.resumeGame(sub.native_handle());
				}
				else if (buf == 'L')
				{
					game.pauseGame(sub.native_handle());
					game.loadGame();
					game.resumeGame(sub.native_handle());
				}
				else if (buf == 'R')
					game.resetGame();
				else if (buf == ESC)
				{
					mciSendString(TEXT("stop Gameplay_Theme"), NULL, 0, NULL);
					game.pauseThread(sub.native_handle());

					break;
				}
				else
					game.addBuf(buf);
			}
			else if (game.checkImpact())
			{
				mciSendString(TEXT("stop Gameplay_Theme"), NULL, 0, NULL);
				while (!isPause) {}

				system("cls");
				game.drawDeadMenu();

				if (DeadMenu() == 0)
				{
					//Neu chon muon choi lai
					system("cls");
					mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

					game.resetGame();
					isPause = false;
				}
				else
				{
					//Neu chon khong muon choi lai
					isPause = false;
					game.pauseGame(sub.native_handle());
					break;
				}
			}

		} while (true);

	}

    sub.detach();
    return 0;
}