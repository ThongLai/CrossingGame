#pragma once
#include <string>
using namespace std;

class ConsoleTask
{
public:
	static void setConsoleWindow(int, int);	//Điều chỉnh cửa sổ Console
	static void fixConsoleWindow();			//Cố định cửa sổ Console
	static void removeConsoleScrollbar();	//Bỏ thanh cuộn Console
	static void setConsoleTitle();			//Thiết lập tiêu đề Console
	static void clrscr();					//Xóa màn hình
	static void showCursor();				//Hiện con trỏ
	static void hideCursor();				//Ẩn con trỏ
public:
	//Di chuyển
	static void gotoXY(int, int);				//Di chuyển đến tọa độ cho trước
	static void gotoXY(int, int, string);		//Di chuyển đến tọa độ và viết một câu
	static void gotoXY(int, int, string, int);	//Di chuyển đến tọa độ và viết một câu có màu
	static void gotoXY(int, int, int, int);		//Di chuyển đến tọa độ và viết một số có màu
	static void gotoXY(int, int, char);			//Di chuyển đến tọa độ và viết một kí tự	
	static void gotoXY(int pX, int pY, char c, int color);
	
public:
	static void setTextColor(int);			//Đổi màu chữ
};