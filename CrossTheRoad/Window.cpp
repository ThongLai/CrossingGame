#include "Window.h"

int SCREEN_WIDTH_PXL = 1633;
int SCREEN_HEIGHT_PXL = 900;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int GAMEPLAY_W;
int STATUS_W;
int ROAD_H = 9;
int SIDEWALK_H = 3;

int LANE[4];
int SIDEWALK[2];

int MIN_DISTANCE = 10;

int LEADERBOARD_SIZE;

string CCODE = "THONG";
string SoundPath = "SoundEffects/";
string SavePath = "GameData/";

vector <Data> SavedPlayers;
vector <Data> LeaderBoard;

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
void SetUpParameters()
{
	GetWindowSize();
	GAMEPLAY_W = 0.75 * SCREEN_WIDTH;
	STATUS_W = SCREEN_WIDTH - GAMEPLAY_W;
	LEADERBOARD_SIZE = SCREEN_HEIGHT * 0.8 / 3 - 1;

	int GAP = (SCREEN_HEIGHT - (ROAD_H * 4 + SIDEWALK_H * 2)) / 5;
	int MID_SCREEN_HEIGHT = midHeight(SCREEN_HEIGHT, ROAD_H * 4 + SIDEWALK_H * 2 + GAP * 5);

	SIDEWALK[1] = MID_SCREEN_HEIGHT;
	LANE[3] = SIDEWALK[1] + SIDEWALK_H + GAP;

	for (int i = 2; i >= 0; i--)
		LANE[i] = LANE[i + 1] + ROAD_H + GAP;

	SIDEWALK[0] = LANE[0] + ROAD_H + GAP;
}
void FullScreenMode()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void WindowedMode()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, 0);
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
bool GetXY(int& x, int& y) {
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
bool GetColor(int& color) {
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
	mciSendStringA(string("open \"" + SoundPath + "MenuTheme.mp3\" type mpegvideo alias Menu_Theme").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "GamePlayTheme.mp3\" type mpegvideo alias Gameplay_Theme").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "Van_Crash.mp3\" type mpegvideo alias Van_Crash").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "Car_Crash.mp3\" type mpegvideo alias Car_Crash").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "Alien_Crash.mp3\" type mpegvideo alias Alien_Crash").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "Bird_Crash.mp3\" type mpegvideo alias Bird_Crash").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "Menu_Select.mp3\" type mpegvideo alias Menu_Select").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "Plus_Point.mp3\" type mpegvideo alias Plus_Point").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "Next_Level.mp3\" type mpegvideo alias Next_Level").c_str(), NULL, 0, NULL);
	mciSendStringA(string("open \"" + SoundPath + "Finish_Game.mp3\" type mpegvideo alias Finish_Game").c_str(), NULL, 0, NULL);
}
void SetAllVolumes(int volume)
{
	mciSendStringA(string("setaudio Menu_Theme volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Gameplay_Theme volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Van_Crash volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Car_Crash volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Alien_Crash volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Bird_Crash volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Menu_Select volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Plus_Point volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Next_Level volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
	mciSendStringA(string("setaudio Finish_Game volume to " + to_string(volume)).c_str(), NULL, 0, NULL);
}
void SavePlayer(const Data& playerData, int index)
{
	SavedPlayers[index] = playerData;
}
void AddPlayer(const Data& playerData)
{
	SavedPlayers.push_back(playerData);
}
void RemovePlayer(int index)
{
	SavedPlayers.erase(SavedPlayers.begin() + index);
}
void AddDataToLeaderBoard(const Data& playerData)
{
	LeaderBoard.push_back(playerData);
	sort(LeaderBoard.begin(), LeaderBoard.end(), greater<Data&>());
	if (LeaderBoard.size() > LEADERBOARD_SIZE)
		LeaderBoard.resize(LEADERBOARD_SIZE);
}
void RemoveDataToLeaderBoard(int index)
{
	LeaderBoard.erase(LeaderBoard.begin() + index);
	sort(LeaderBoard.begin(), LeaderBoard.end(), greater<Data&>());
}
string* ExtractPlayerName()
{
	string* NameList = new string[SavedPlayers.size()];

	for (int i = 0; i < SavedPlayers.size(); i++)
		NameList[i] = SavedPlayers[i].getName();

	return NameList;
}
void LoadPlayerSaves()
{
	ifstream inList(SavePath + "Saved_Players_Data.txt", ios::in);

	Data playerData;

	while (inList >> playerData)
		SavedPlayers.push_back(playerData);

	inList.close();
}
void SavePlayerSaves()
{
	ofstream outList(SavePath + "Saved_Players_Data.txt", ios::out);

	for (int i = 0; i < SavedPlayers.size(); i++)
		outList << SavedPlayers[i] << endl;

	outList.close();
}
void LoadLeaderBoard()
{
	ifstream inList(SavePath + "Leader_Board.txt", ios::in);

	Data playerData;

	int count = 0;
	while (count < LEADERBOARD_SIZE && inList >> playerData)
	{
		LeaderBoard.push_back(playerData);
		count++;
	}

	sort(LeaderBoard.begin(), LeaderBoard.end(), greater<Data&>());

	inList.close();
}
void SaveLeaderBoard()
{
	ofstream outList(SavePath + "Leader_Board.txt", ios::out);

	for (int i = 0; i < LeaderBoard.size(); i++)
		outList << LeaderBoard[i] << endl;

	outList.close();
}


int artWidth(string *art, int height)
{
	int width = art[0].size();
	for (int i = 0; i < height; i++)
		if (width < art[i].size())
			width = art[i].size();

	return width;
}
void printMessCenter(string message)
{
	Status SavedStatus;

	GotoXY(midWidth(SCREEN_WIDTH, message), midHeight(SCREEN_HEIGHT, 1));
	cout << message;
}
void printMessCenter(string message, int text_color, int bg_color)
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

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
int Distance(int objWidth, int objNum)
{
	return (GAMEPLAY_W - objWidth * objNum) / objNum;
}

//Set up when start up
void StartUp()
{
	srand(time(NULL));
	setRasterFonts();
	//FullScreenMode();
	SetWindowSize(SCREEN_WIDTH_PXL, SCREEN_HEIGHT_PXL);
	FixConsoleWindow();
	HideCursor();
	SetUpParameters();
}