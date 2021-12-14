#pragma once

#include "Car.h"
#include "Van.h"
#include "Alien.h"
#include "Bird.h"
#include "Player.h"
#include "Trafficlight.h"
#include "Menu.h"

class CGame
{
private:	
	//Obstacles
	vector <Van> vans;
	vector <Car> cars;
	vector <Alien> aliens;
	vector <Bird> birds;

	//Player Character
	Player player;

	//Trafficlight for Van and Car
	Trafficlight vanLight;
	Trafficlight carLight;

	//Current level
	int level;

	//The number of objects each road
	int objNum;

	//Current score
	int score;

	//Check point array to prevent count again the score of a road
	bool checkPoint[4]; 

	//Timer indices
	clock_t START_TIME;
	clock_t TIME;
	clock_t PAUSE_TIME;

	//Catch other buttons from the keyboard to check whether it is a command or not
	string buf;

	//Indicate the UNDEAD mode
	bool UnDeadCMD;


	//Pause the thread
	bool pause;

	//Indicate whether it is in game or not
	bool running;

public:
	CGame(); //Contructor
	~CGame(); //Destructor

	void Init(); //Initialize important parameters in the game
	void drawGame(); //Draw the gameplay screen
	void drawPauseScreen(); //Draw pause game screen
	void displayCommand(); //Display command that has been invoked
	void Remove(); //Remove all the current objects on the screen

	Player getPlayer();//Get the player object
	vector <CVEHICLE*>& getVehicle();//Get the vehicles objects
	vector <CANIMAL*>& getAnimal(); //Get the animal objects
	int getPoint(); //Return the [score] attribute

	void resetGame(); //Operate the reset game process
	void exitGame(); //Operate the exit game process
	void loadGame(); //Operate the load game process
	void saveGame(); //Operate the save game process
	void pauseThread(); //Change the [pause] attribute to 'true'
	void pauseGame(); //Operate the pause game process by saving the current [TIME] then calling [pauseThread] method
	void resumeThread(); //Change the [pause] attribute to 'false'
	void resumeGame(); //Operate the resume game process by load the current [TIME] then calling [resumeThread] method

	bool updatePosPlayer(char); //Update the position of the player object
	void updatePosVehicle(int); //Update the position of the vehicle objects
	void updatePosAnimal(); //Update the position of the aniaml objects
	void updateTime(); //Update the [TIME] attribute
	void updateGameStatus(); //Udate status: [level] and [score]
	void calcScore(); //Check player's current position and calculate the corresponding score
	void resetData(); //Reset values all of the attributes

	void nextLevel(); //Setup new attributes for the following level
	void processAfterGame(); //Process after an impact

	bool checkImpact(); //Check whether the Player impact with an obstacle
	void checkDrawLines(); //Draw back the START and FINISH line if the player step on it
	bool isFinish(); //Check if the player crosses the FINISH line
	bool isPause(); //Return the [pause] attribute
	bool isPlaying(); //Return the [running] attribute

	void addBuf(char key); //Catch a key from keyboard
	void CheckUnDeadCMD(); //Check whether the player types a command or not
};
