#include "Menu.h"
#include "Bird.h"
#include "Alien.h"
#include "Vans.h"
#include "Player.h"
#include "CGame.h"

using namespace std;

CGame game;
int buf = 0;

void SubThread() {


    while (true) {

        if (buf == 'R')
            game.resetGame();

		game.drawCommand();

        game.updatePosPeople(buf);
        buf = 0;

        game.updatePosAnimal();
        game.updatePosVehicle();

		game.calcPoint();

		game.updateTime();
		game.updateGameStatus();

        //Đây là if kết thúc
        if (game.getPeople().Y() == SIDEWALK[1])
        {
            game.nextRound();
            continue;
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

		buf = MainMenu.inputMenu();
		//mciSendString(TEXT("play Menu_Theme repeat"), NULL, 0, NULL);




		switch (buf)
		{
		case 0:
		{
			//mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);

			//mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);

			game.resetGame();
			game.resumeThread(sub.native_handle());




			//mciSendString(TEXT("stop Gameplay_Theme"), NULL, 0, NULL);
			//mciSendString(TEXT("play Menu_Theme from 0 repeat"), NULL, 0, NULL);

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
				else if (buf == ESC)
				{
					game.pauseThread(sub.native_handle());
					break;
				}
				else
				{
					game.addBuf(buf);
				}
			}
			else if (game.checkImpact())
			{
				game.pauseThread(sub.native_handle());
				system("cls");
				game.drawDeadMenu();

				if (DeadMenu() == 0)
				{
					//Neu chon muon choi lai
					system("cls");

					game.resetGame();
					game.resumeThread(sub.native_handle());
				}
				else
				{
					//Neu chon khong muon choi lai

					break;
				}
			}

		} while (true);

	}

    sub.detach();
    return 0;
}