#include "Menu.h"
#include "Bird.h"
#include "Alien.h"
#include "Vans.h"
#include "Player.h"
#include "CGame.h"

using namespace std;

int moveTurn = 0;

string CAR[] =
{
	"  ÛßßßßßßßßßÛ",
	" Û     O     Û",
	"ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ",
	"  ßßÛÛÛÛÛÛÛßß"
};

string PLAYER[] =
{
	 "  ",
	 "ÄÛÄ",
	"/ \\"
};

string CAR2[] =
{
	"  ÛßßÛÛÛÛÛÛÛÛÛÛ",
	"ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ",
	"ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ",
	"ÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ",
	"O             O"
};

void printObj(int mX, int mY, int width, int height, int text_color, int bg_color, string Obj[])
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
	{
		GotoXY(mX, iy);
		cout << Obj[i];
	}
}

void removeObj(int mX, int mY, int width, int height)
{
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	for (int iy = mY; iy < mY + height; iy++)
		for (int ix = mX; ix < mX + width; ix++)
		{
			GotoXY(ix, iy);
			cout << " ";
		}
}

void moveObj(int &mX, int &mY,int width, int height, int text_color, int bg_color, int x, int y, string Obj[])
{
	while ((mX != x || mY != y) && PLAYGAME)
	{
		removeObj(mX, mY, width, height);

		if (mX < x) mX++;
		else if (mX > x) mX--;

		if (mY < y) mY++;
		else if (mY > y) mY--;

		printObj(mX, mY, width, height, text_color, bg_color, Obj);
	}
}

void ThreadMovingObjects()
{
	srand(time(NULL));

	int TURN = 0;
	int ROAD[4]{ 0 };

	Alien alien;
	int ix_alien = 0;
	bool direct = true;
	alien.setColor(rand() % 15 + 1, BLACK);


	int car_width = 15, car_height = sizeof(CAR) / sizeof(string);
	int x_car = 0;
	int ix_car = x_car;
	int car_color = rand() % 15 + 1;


	int player_width = 3, player_height = sizeof(PLAYER) / sizeof(string);
	int x_player = 0;
	int ix_player = x_player;
	int player_color = rand() % 15 + 1;

	int car2_width = 15, car2_height = sizeof(CAR2) / sizeof(string);
	int x_car2 = GAMEPLAY_W - car2_width;
	int ix_car2 = x_car2;
	int car2_color = rand() % 15 + 1;

	int alien_speed = 3;
	int car_speed = 2;
	int player_speed = 1;
	int car2_speed = 1;

	while (true) {
		if (PLAYGAME)
		{
			int count = 0;
			for (int i = 0; i < 4; i++)
			{
				ROAD[i] = rand() % 4;
				for (int j = 0; j < i; j++)
					if (ROAD[i] == ROAD[j])
					{
						i--;
						break;
					}
			}

			int ALIEN_LAND = midHeight(SCREEN_HEIGHT, SIDEWALK_H * 2 + ROAD_H * 4) + SIDEWALK_H + midHeight(ROAD_H, alien.getHeight()) + ROAD_H * ROAD[0];
			int CAR_LANE = midHeight(SCREEN_HEIGHT, SIDEWALK_H * 2 + ROAD_H * 4) + SIDEWALK_H + midHeight(ROAD_H, car_height) + ROAD_H * ROAD[1];
			int PLAYER_LAND = midHeight(SCREEN_HEIGHT, SIDEWALK_H * 2 + ROAD_H * 4) + SIDEWALK_H + midHeight(ROAD_H, player_height) + ROAD_H * ROAD[2];
			int CAR2_LAND = midHeight(SCREEN_HEIGHT, SIDEWALK_H * 2 + ROAD_H * 4) + SIDEWALK_H + midHeight(ROAD_H, car2_height) + ROAD_H * ROAD[3];

			alien.setXY(0, ALIEN_LAND);


			while (PLAYGAME)
			{
				
				if (TURN == 0)
				{
					if (direct == true && ix_alien >= GAMEPLAY_W - alien.getWidth())
					{
						direct = false;
						alien.setColor(rand() % 15 + 1, BLACK);
					}
					else if (direct == false && ix_alien <= 0)
					{
						direct = true;
						alien.setColor(rand() % 15 + 1, BLACK);
					}
					if (direct) ix_alien++;
					else ix_alien--;

					while (moveTurn != 0) {}
					moveTurn = 0;

					alien.Move();

					moveTurn = 1;
					
					count++;
					if (count == alien_speed) {
						count = 0;
						TURN = (TURN + 1) % 4;
					}
				}
				else if (TURN == 1)
				{
					if (ix_car >= GAMEPLAY_W - car_width)
					{
						removeObj(x_car, CAR_LANE, car_width, car_height);
						x_car = 0;
						ix_car = x_car;
						car_color = rand() % 15 + 1;
					}

					ix_car++;

					while (moveTurn != 0) {}
					moveTurn = 0;

					moveObj(x_car, CAR_LANE, car_width, car_height, car_color, BLACK, ix_car, CAR_LANE, CAR);
					moveTurn = 1;
					count++;
					if (count == car_speed) {
						count = 0;
						TURN = (TURN + 1) % 4;
					}
				}
				else if (TURN == 2)
				{
					if (ix_player >= GAMEPLAY_W - player_width)
					{
						removeObj(x_player, PLAYER_LAND, player_width, player_height);
						x_player = 0;
						ix_player = x_player;
						player_color = rand() % 15 + 1;
					}

					ix_player++;

					while (moveTurn != 0) {}
					moveTurn = 0;

					moveObj(x_player, PLAYER_LAND, player_width, player_height, player_color, BLACK, ix_player, PLAYER_LAND, PLAYER);
					moveTurn = 1;
					count++;
					if (count == player_speed) {
						count = 0;
						TURN = (TURN + 1) % 4;
					}
				}
				else if (TURN == 3)
				{
					if (ix_car2 <= 0)
					{
						removeObj(x_car2, CAR2_LAND, car2_width, car2_height);
						x_car2 = GAMEPLAY_W - car2_width;
						ix_car2 = x_car2;
						car2_color = rand() % 15 + 1;
					}

					ix_car2--;

					while (moveTurn != 0) {}
					moveTurn = 0;

					moveObj(x_car2, CAR2_LAND, car2_width, car2_height, car2_color, BLACK, ix_car2, CAR2_LAND, CAR2);
					moveTurn = 1;
					count++;
					if (count == car2_speed) {
						count = 0;
						TURN = (TURN + 1) % 4;
					}
				}
				Sleep(10);
				
				moveTurn = 0;
			}
			MAINMENU = true;
		}
	}
}
//void ThreadCar()
//{
//	srand(time(NULL));
//
//	int car_width = 15, car_height = 4;
//	int x_car = 0;
//	int y_car = midHeight(SCREEN_HEIGHT, SIDEWALK_H * 2 + ROAD_H * 4) + SIDEWALK_H + midHeight(ROAD_H, car_height) + ROAD_H;
//
//	int ix_car = x_car;
//	int text_color = rand() % 15 + 1;
//
//	while (true) {
//		if (PLAYGAME) {
//			int count = 0;
//			while (PLAYGAME)
//			{
//				if (THREAD_CHANNEL == 1) 
//				{
//					removeCar(ix_car, y_car, car_width, car_height);
//					
//					if (ix_car >= GAMEPLAY_W - car_width)
//					{
//						ix_car = x_car;
//						text_color = rand() % 15 + 1;
//					}
//
//					ix_car++;
//
//					printCar(ix_car, y_car, car_width, car_height, text_color, BLACK);
//					count++;
//					if (count == 1) {
//						THREAD_CHANNEL = (THREAD_CHANNEL + 1) % THREADS;
//						count = 0;
//					}
//					Sleep(1);
//				}
//			}
//
//			MAINMENU = true;
//		}
//	}
//}

void MainMenu()
{
	thread t1(ThreadMovingObjects);

	int box_width = 20;
	int box_height = 3;
	Menu menu("MENU", MENU_SIZE, MENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * MENU_SIZE), box_width, box_height, WHITE, BLACK);
	//mciSendString(TEXT("play Menu_Theme repeat"), NULL, 0, NULL);
	
	CGame Game;

	int buf = 0;
	Status SavedState;
	while (true)
	{
		system("cls");
		menu.printMenu();
		buf = menu.inputMenu();

		switch (buf)
		{
		case 0:
		{
			system("cls");
			printMessCenter(MENU[0] + " is selected");
			//mciSendString(TEXT("stop Menu_Theme"), NULL, 0, NULL);
			Sleep(1000);
			
			//mciSendString(TEXT("play Gameplay_Theme from 0 repeat"), NULL, 0, NULL);
			MAINMENU = false;
			system("cls");

			Game.drawGame();

			PLAYGAME = true;
			
			Game.resumeGame(t1.native_handle());


			do {
				
				buf = toupper(_getch());
				while (moveTurn != 1) {

				}
				if (buf == 'P')
				{
					Game.pauseGame(t1.native_handle());
				}
				else if (buf == 'R')
				{
					Game.resumeGame(t1.native_handle());
				}

				Game.updatePosPeople(buf);
				moveTurn = 0;
			} while (buf != ESC);



			//mciSendString(TEXT("stop Gameplay_Theme"), NULL, 0, NULL);
			//mciSendString(TEXT("play Menu_Theme from 0 repeat"), NULL, 0, NULL);
			PLAYGAME = false;
			while (!MAINMENU) {}

			break;
		}
		case 1:
		{
			system("cls");
			printMessCenter(MENU[1] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			
			Player Player;
			Player.setX(10);
			Player.setY(10);

			while (true)
			{
				buf = toupper(_getch());

				if (buf == ESC) break;
				else if (buf == KEY_UP || buf == 'W')
				{
					
					Player.UP();
				}
				else if (buf == KEY_DOWN || buf == 'S')
				{
					
					Player.DOWN();
				}
				else if (buf == KEY_LEFT || buf == 'A')
				{
					
					Player.LEFT();
				}
				else if (buf == KEY_RIGHT || buf == 'D')
				{
					
					Player.RIGHT();
				}
				
			}
			

			break;
		}
		case 2:
		{
			system("cls");
			printMessCenter(MENU[2] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		}
		case 3:
		{
			system("cls");
			printMessCenter(MENU[3] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		}
		case 4:
		{
			system("cls");
			printMessCenter(MENU[4] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		}
		case 5:
		{
			system("cls");
			printMessCenter(MENU[5] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		}
		case 6:
		{
			system("cls");
			printMessCenter(MENU[6] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		}
		case 7:
		{
			system("cls");
			printMessCenter(MENU[7] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			Game.exitGame(t1.native_handle());

			break;
		}
		}
		if (buf == -1 || buf == 7)
			break;
	}
}


//int main()
//{	
//	/*
//	//BIRD/VANS TESTING.....
//	
//	StartUp();
//
//	drawGamePlayScreen();
//
//	Bird bird;
//	Vans vans(0, 10);
//
//	PLAYGAME = true;
//
//	bird.setXY(0, midHeight(ROAD_H, bird.getHeight()) + LAND[0]);
//
//	bird.Move(69, midHeight(ROAD_H, bird.getHeight()) + LAND[0]);
//
//	system("pause>0");
//	*/
//
//	//SET UP WINDOW
//	StartUp();
//
//	moveTurn = 0;
//	thread t1(ThreadMovingObjects);
//
//	//mún dùng mấy hàm pause, resume,exit đồ thì dùng lệnh ví dụ: g.resumeGame((HANDLE)t1.native_handle())
//	TestMenu();
//
//	//mciSendString(TEXT("close Menu_Theme"), NULL, 0, NULL);
//
//	system("cls");
//
//	t1.detach();
//	
//	return 0;
//}


int main()
{
	srand(time(0));
	StartUp();

	MainMenu();

	return 0;
}