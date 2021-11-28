#pragma once

#include "Car.h"
#include "Vans.h"
#include "Alien.h"
#include "Bird.h"
#include"Player.h" //Check lai
#include "Trafficlight.h"
#include "Menu.h"

class CGame
{
private:
	vector <Vans> vans;
	vector <Car> cars;
	vector <Alien> alien;
	vector <Bird> bird;
	Player player;
	int difficulty;
	int objNum;
	//int speed;
	Trafficlight vansLight;
	Trafficlight carLight;
	int point;
	bool checkPoint[4]; //Check point de tranh viec cong diem nhieu lan

public:
	CGame(); //Chuẩn bị dữ liệu cho tất cả các đối tượng 
	void Init();
	void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
	~CGame(); // Hủy tài nguyên đã cấp phát

	Player getPeople();//Lấy thông tin người
	vector <CVEHICLE> getVehicle();//Lấy danh sách các xe
	vector <CANIMAL> getAnimal(); //Lấy danh sách các thú

	void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE); // Thực hiện thoát Thread 
	void startGame(); // Thực hiện bắt đầu vào trò chơi
	void loadGame(istream); // Thực hiện tải lại trò chơi đã lưu
	void saveGame(istream); // Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(HANDLE); // Tạm dừng Thread
	void resumeGame(HANDLE); //Quay lai Thread

	void Remove();
	void nextRound();

	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosVehicle(int); //Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosAnimal();//Thực hiện cho CDINAUSOR & CBIRD di chuyển

	bool checkImpact();
	bool isFinish();
	void calcPoint();
	int getPoint();
};