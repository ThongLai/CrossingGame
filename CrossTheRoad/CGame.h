#pragma once

#include "Car.h"
#include "Vans.h"
#include "Alien.h"
#include "Bird.h"
#include "Player.h"
#include "Trafficlight.h"
#include "Menu.h"

class CGame
{
private:	
	vector <Van> vans;
	vector <Car> cars;
	vector <Alien> aliens;
	vector <Bird> birds;
	Player player;

	Trafficlight vansLight;
	Trafficlight carLight;

	int level;
	int objNum;

	int score;
	bool checkPoint[4]; //Check point de tranh viec cong diem nhieu lan

	//Check cheatcode de test game
	string buf;
	bool UnDeadCMD;

	//Time in game
	clock_t START_TIME;
	clock_t TIME;
	clock_t PAUSE_TIME;

	//Biến tạm dừng game
	bool pause;
	bool running;

public:
	CGame(); //Chuẩn bị dữ liệu cho tất cả các đối tượng 
	~CGame(); // Hủy tài nguyên đã cấp phát

	void Init();
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	void drawPauseScreen(); //Thực hiện vẽ màn hình tạm dừng
	void drawCommand();

	Player getPeople();//Lấy thông tin người
	vector <CVEHICLE*> getVehicle();//Lấy danh sách các xe
	vector <CANIMAL*> getAnimal(); //Lấy danh sách các thú

	void resetGame(); // Thực hiện chơi lại từ đầu
	void exitGame(); // Thực hiện thoát game
	void loadGame(); // Thực hiện tải lại trò chơi đã lưu
	void saveGame(); // Thực hiện lưu lại dữ liệu trò chơi
	void pauseThread(); // Tạm dừng Thread
	void pauseGame();
	void resumeThread(); //Quay lai Thread
	void resumeGame(); //Quay lai Thread

	void Remove();
	void nextLevel();

	bool updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(int); //Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void updateTime();//Thực hiện cập nhật thời gian
	void updateGameStatus();//Thực hiện cập nhật level, điểm
	void resetData(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void processAfterGame(); //Xử lý sau khi người chơi thua

	bool checkImpact();
	void checkDrawLines();
	bool isFinish();
	bool isPause();
	bool isPlaying();
	void calcPoint();
	int getPoint();

	void addBuf(char key);
	void CheckUnDeadCMD();
};
