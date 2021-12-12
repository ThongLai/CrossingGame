#include "Window.h"
#include "Menu.h"
#include "Bird.h"
#include "Alien.h"
#include "Van.h"
#include "Player.h"
#include "CGame.h"

CGame game;

//Catch input from keyboard
int buf = 0;

void SubThread() {

	int time = 0;
    while (true) {

		if (game.checkImpact() || game.isFinish() || buf == 'P' || buf == 'R' || buf == 'M' || buf == 'L' || buf == ESC)
			game.pauseGame();

		//Pause thread loop
		while (game.isPause()) {}

		game.displayCommand();

		if (game.updatePosPlayer(buf))
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

	//Run another thread
    thread sub(SubThread);

	//Load and open files
	LoadPlayerSaves();
	LoadLeaderBoard();
	OpenSoundFiles();

	int box_width = 20;
	int box_height = 3;
	MENU MainMenu("MAIN MENU", MAINMENU, MAINMENU_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 3 / 2, box_height * MAINMENU_SIZE), box_width, box_height, WHITE, BLACK);

	while (true)
	{
		system("cls");

		//Draw tiltle
		drawArt(title, title_height, midWidth(SCREEN_WIDTH, title_width), midHeight(SCREEN_HEIGHT / 2, title_height), rand() % (15) + 1);
		
		MainMenu.printMenu();
		
		//Play menu theme
		mciSendString(TEXT("play Menu_Theme repeat"), NULL, 0, NULL);

		//Take input from player
		buf = MainMenu.inputMenu();

		switch (buf)
		{
		case 0: //Play
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
		case 1: //Load Game
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
		case 2: //Leader Board
		{
			system("cls");

			displayLeaderBoard();

			toupper(_getch());

			break;
		}
		case 3: //Instruction
		{
			system("cls");

			drawInstruction();

			do {
				buf = toupper(_getch());
			} while (buf != ESC && buf != ENTER);

			break;
		}
		case 4://Settings
		{
			system("cls");

			Settings_Menu();
			
			MainMenu.setMenu("MAIN MENU", MAINMENU, MAINMENU_SIZE, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT * 3 / 2, box_height * MAINMENU_SIZE), box_width, box_height, WHITE, BLACK);
			break;
		}
		case 5: //Credits
		{
			system("cls");

			drawCredits();

			do {
				buf = toupper(_getch());
			} while (buf != ESC && buf != ENTER);

			break;

			break;
		}
		case 6: //Quit
		case -1:
		{
			system("cls");
			printMessCenter("GOOD BYE! :-)", rand() % 15 + 1, BLACK);
			Sleep(1000);

			sub.detach();
			return 0;
		}
		}




		//Ingame process
		while (game.isPlaying())
		{
			//Calculate score
			game.calcScore();

			if (_kbhit())
			{
				buf = toupper(_getch());

				if (buf == ESC) //Exit
				{
					while (!game.isPause()) {}

					mciSendString(TEXT("stop Gameplay_Theme"), NULL, 0, NULL);

					game.exitGame();

					mciSendString(TEXT("play Menu_Theme from 0 repeat"), NULL, 0, NULL);

					break;
				}

				switch (buf)
				{
				case 'P': //Pause/Continue
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

					break;
				}
				case 'R': //Reset Game
				{
					while (!game.isPause()) {}

					game.resetGame();

					mciSendString(TEXT("play Gameplay_Theme from 0"), NULL, 0, NULL);

					buf = 0;
					game.resumeThread();

					break;
				}
				case 'M': //Save Game
				{
					while (!game.isPause()) {}

					mciSendString(TEXT("pause Gameplay_Theme"), NULL, 0, NULL);

					game.saveGame();

					mciSendString(TEXT("resume Gameplay_Theme"), NULL, 0, NULL);

					buf = 0;
					game.resumeGame();

					break;
				}
				case 'L': //Load Game
				{
					while (!game.isPause()) {}

					mciSendString(TEXT("pause Gameplay_Theme"), NULL, 0, NULL);

					game.loadGame();

					mciSendString(TEXT("resume Gameplay_Theme"), NULL, 0, NULL);

					buf = 0;
					game.resumeThread();

					break;
				}
				default: //Add uncommon key into buffer
					game.addBuf(buf);
				}
			}
			else if (game.checkImpact()) //Checking impact
			{
				while (!game.isPause()) {}

				mciSendString(TEXT("stop Gameplay_Theme"), NULL, 0, NULL);
				system("cls");

				game.processAfterGame();

				if (!game.isPlaying()) //Stop game and Exit
				{
					mciSendString(TEXT("play Menu_Theme from 0 repeat"), NULL, 0, NULL);
					break;
				}
			}
			else if (game.isFinish()) //Check FINISH line
			{
				while (!game.isPause()) {}

				game.nextLevel();
				game.resumeThread();
			}
		}
	}
}