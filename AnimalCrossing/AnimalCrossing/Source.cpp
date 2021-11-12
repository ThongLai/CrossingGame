#include "Menu.h"
#include "Animal.h"
#include "People.h"

using namespace std;

int moveTurn = 0;

string CAR[] =
{
	"  лпппппппппл",
	" л     O     л",
	"ллллллллллллллл",
	"  пплллллллпп"
};

string PLAYER[] =
{
	 "  ",
	 "ФлФ",
	"/ \\"
};

string CAR2[] =
{
	"  лпплллллллллл",
	"ллллллллллллллл",
	"ллллллллллллллл",
	"ллллллллллллллл",
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

void TestScreen()
{
	Box lb(SCREEN_WIDTH - HIGHSCORE_H, 0, HIGHSCORE_H, SCREEN_HEIGHT, WHITE, BLACK, "HIGHSCORE");
	lb.printBox();

	Box land[4];

	Box side[2];
	int mid = midHeight(SCREEN_HEIGHT, ROAD_H * 4 + SIDEWALK_H * 2);
	side[0].setBox(0, mid, SCREEN_WIDTH - HIGHSCORE_H, SIDEWALK_H, LIGHTGREEN, BLACK, "SIDEWALK");
	side[0].printBox();
	side[1].setBox(0, mid + 3 + 4 * ROAD_H, SCREEN_WIDTH - HIGHSCORE_H, SIDEWALK_H, LIGHTGREEN, BLACK, "SIDEWALK");
	side[1].printBox();


	for (int i = 0; i < 4; i++)
	{
		land[i].setBox(0, mid + SIDEWALK_H + i * ROAD_H, SCREEN_WIDTH - HIGHSCORE_H, ROAD_H, LIGHTCYAN, BLACK, "ROAD");
		land[i].printBox();
	}

	//system("pause>0");
}
void ThreadMovingObjects()
{
	srand(time(NULL));

	int TURN = 0;
	int ROAD[4]{ 0 };

	CALIEN alien;
	int ix_alien = 0;
	bool flag = 1;
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
					if (flag == 1 && ix_alien >= GAMEPLAY_W - alien.getWidth())
					{
						flag = 0;
						alien.setColor(rand() % 15 + 1, BLACK);
					}
					else if (flag == 0 && ix_alien <= 0)
					{
						flag = 1;
						alien.setColor(rand() % 15 + 1, BLACK);
					}
					if (flag) ix_alien++;
					else ix_alien--;

					moveTurn = 0;
					alien.Move(ix_alien, ALIEN_LAND);

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

					moveTurn = 0;
					moveObj(x_car, CAR_LANE, car_width, car_height, car_color, BLACK, ix_car, CAR_LANE, CAR);

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

					moveTurn = 0;
					moveObj(x_player, PLAYER_LAND, player_width, player_height, player_color, BLACK, ix_player, PLAYER_LAND, PLAYER);

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

					moveTurn = 0;
					moveObj(x_car2, CAR2_LAND, car2_width, car2_height, car2_color, BLACK, ix_car2, CAR2_LAND, CAR2);

					count++;
					if (count == car2_speed) {
						count = 0;
						TURN = (TURN + 1) % 4;
					}
				}

				moveTurn = 1;
				Sleep(10);
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

void TestMenu()
{
	int box_width = 20;
	int box_height = 3;
	Menu menu("MENU", MENU_SIZE, MENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * MENU_SIZE), box_width, box_height, WHITE, BLACK);
	//mciSendString(TEXT("play Menu_Theme repeat"), NULL, 0, NULL);

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
			TestScreen();
			PLAYGAME = true;
			People Player;

			Player.setX(10);
			Player.setY(10);
			Player.draw();

			do {
				buf = toupper(_getch());
				while (moveTurn == 0)
				{

				}
				if (buf == KEY_UP || buf == 'W')
				{
					Player.remove();
					Player.UP();
				}
				else if (buf == KEY_DOWN || buf == 'S')
				{
					Player.remove();
					Player.DOWN();
				}
				else if (buf == KEY_LEFT || buf == 'A')
				{
					Player.remove();
					Player.LEFT();
				}
				else if (buf == KEY_RIGHT || buf == 'D')
				{
					Player.remove();
					Player.RIGHT();
				}
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

			People Player;
			Player.setX(10);
			Player.setY(10);

			while (true)
			{
				buf = toupper(_getch());

				if (buf == ESC) break;
				else if (buf == KEY_UP || buf == 'W')
				{
					Player.draw();
					Player.UP();
				}
				else if (buf == KEY_DOWN || buf == 'S')
				{
					Player.draw();
					Player.DOWN();
				}
				else if (buf == KEY_LEFT || buf == 'A')
				{
					Player.draw();
					Player.LEFT();
				}
				else if (buf == KEY_RIGHT || buf == 'D')
				{
					Player.draw();
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

			break;
		}
		}
		if (buf == -1 || buf == 7)
			break;
	}
}


int main()
{	
	//SET UP WINDOW
	//FullScreenMode();
	setRasterFonts();
	SetWindowSize(1633, 900);
	FixConsoleWindow();
	HideCursor();
	SetUpScreenSize();
	OpenSoundFiles(); 
	thread t1(TestMenu);
	//thread t2(ThreadCar);
	//t1.detach();
	//t2.detach();
	

	ThreadMovingObjects();
	//TestScreen();


	mciSendString(TEXT("close Menu_Theme"), NULL, 0, NULL);
	t1.join();
	//t2.detach();
	system("cls");

	
	return 0;
}
