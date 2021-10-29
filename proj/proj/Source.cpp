#include "Menu.h"

void TestMenu()
{
	int box_width = 20;
	int box_height = 3;
	Menu menu("MENU", MENU_SIZE, MENU, midWidth(SCREEN_WIDTH, box_width), midHeight(SCREEN_HEIGHT, box_height * MENU_SIZE), box_width, box_height, WHITE, BLACK);

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
			system("cls");
			printMessCenter(MENU[0] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		case 1:
			system("cls");
			printMessCenter(MENU[1] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		case 2:
			system("cls");
			printMessCenter(MENU[2] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		case 3:
			system("cls");
			printMessCenter(MENU[3] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		case 4:
			system("cls");
			printMessCenter(MENU[4] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		case 5:
			system("cls");
			printMessCenter(MENU[5] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		case 6:
			system("cls");
			printMessCenter(MENU[6] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		case 7:
			system("cls");
			printMessCenter(MENU[7] + " is selected");
			Sleep(1000);
			SavedState.ResetToCurrent();

			break;
		}
		if (buf == -1 || buf == 7)
			break;
	}
}
void TestScreen()
{
	int highscore_height = 30;
	Box lb(SCREEN_WIDTH - highscore_height, 0, highscore_height, SCREEN_HEIGHT, WHITE, BLACK, "HIGHSCORE");
	lb.printBox();

	Box land[4];
	int height = 8;

	Box side[2];
	int height_side = 3;
	int mid = midHeight(SCREEN_HEIGHT, height * 4 + height_side * 2);
	side[0].setBox(0, mid, SCREEN_WIDTH - highscore_height, height_side, GREEN, BLACK, "SIDEWALK");
	side[0].printBox();
	side[1].setBox(0, mid + 3 + 4 * height, SCREEN_WIDTH - highscore_height, height_side, GREEN, BLACK, "SIDEWALK");
	side[1].printBox();


	for (int i = 0; i < 4; i++)
	{
		land[i].setBox(0, mid + height_side + i * height, SCREEN_WIDTH - highscore_height, height, BLUE, BLACK, "CAR");
		land[i].printBox();
	}

	system("pause>0");
}

int main()
{
	//Set up window
	setRasterFonts();
	//FullScreenMode();
	SetWindowSize(1633, 900);
	FixConsoleWindow();
	HideCursor();
	GetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	//TestMenu();
	TestScreen();

	system("cls");
	return 0;
}