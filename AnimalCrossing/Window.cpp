#include "Window.h"

int SCREEN_WIDTH_PXL = 1633;
int SCREEN_HEIGHT_PXL = 900;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int MID_SCREEN_HEIGHT;
int GAMEPLAY_W;
int HIGHSCORE_W = 30;
int ROAD_H = 9;
int SIDEWALK_H = 3;

int LAND[4];
int SIDEWALK[2];

bool PLAYGAME = false;
bool MAINMENU = true;

int Status::getX()
{
	return _X;
}

int Status::getY()
{
	return _Y;
}

int Status::getColor()
{
	return _COLOR;
}

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void GotoXY(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetTextColor(WORD wColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

WORD DefineColor(int t_color, int t_background)
{
	return ((t_background & 0x0F) << 4) + (t_color & 0x0F);
}

void GetWindowSize()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	SCREEN_WIDTH = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	SCREEN_HEIGHT = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void SetWindowSize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void SetUpScreenSize()
{
	GetWindowSize();
	GAMEPLAY_W = SCREEN_WIDTH - HIGHSCORE_W;
	MID_SCREEN_HEIGHT = midHeight(SCREEN_HEIGHT, ROAD_H * 4 + SIDEWALK_H * 2);

	for (int i = 0; i < 4; i++)
		LAND[i] = MID_SCREEN_HEIGHT + SIDEWALK_H + ROAD_H * i;

	SIDEWALK[0] = MID_SCREEN_HEIGHT;
	SIDEWALK[1] = MID_SCREEN_HEIGHT + 4 * ROAD_H + SIDEWALK_H;
}

void FullScreenMode()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void setRasterFonts()
{
	CONSOLE_FONT_INFOEX cf = { 0 };
	cf.cbSize = sizeof cf;
	cf.dwFontSize.X = 10;
	cf.dwFontSize.Y = 18;
	wcscpy_s(cf.FaceName, L"Terminal");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
}

bool GetXY(int &x, int &y) {
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleScreenBufferInfo(hStd, &screenBufferInfo)) {
		cout << "GetConsoleScreenBufferInfo (" << GetLastError() << ")\n";
		return false;
	}
	x = screenBufferInfo.dwCursorPosition.X;
	y = screenBufferInfo.dwCursorPosition.Y;
	return true;
}

bool GetColor(int &color) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info)) {
		cout << "GetConsoleScreenBufferInfo (" << GetLastError() << ")\n";
		return false;
	}
	color = info.wAttributes;
	return true;
}

void OpenSoundFiles()
{
	mciSendString(TEXT("open \"MenuTheme.mp3\" type mpegvideo alias Menu_Theme"), NULL, 0, NULL);
	mciSendString(TEXT("open \"GamePlayTheme.mp3\" type mpegvideo alias Gameplay_Theme"), NULL, 0, NULL);
}


int Distance(int objWidth, int objNum)
{
	return (GAMEPLAY_W - objWidth * objNum) / objNum;
}

void PrintChar(int x, int y, char ch)
{
	GotoXY(x, y);
	cout << ch;
}

void PrintString(int x, int y, string S)
{
	GotoXY(x, y);
	cout << S;
}

void printMessCenter(string message)
{
	GotoXY(midWidth(SCREEN_WIDTH, message), midHeight(SCREEN_HEIGHT, 1));
	cout << message;
}

int midWidth(int width, string message)
{
	return (width - message.size()) / 2;
}

int midWidth(int width, int content_width)
{
	return (width - content_width) / 2;
}

int midHeight(int height, int content_height)
{
	return (height - content_height) / 2;
}

void StartUp()
{
	//FullScreenMode();
	setRasterFonts();
	SetWindowSize(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL);
	FixConsoleWindow();
	HideCursor();
	SetUpScreenSize();
	OpenSoundFiles();
}
