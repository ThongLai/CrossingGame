#include "Menu.h"
#include "Bird.h"
#include "Alien.h"
#include "Vans.h"
#include "Player.h"

#include "CGame.h"

using namespace std;

int buf = 0;
void SubThread() {
    CGame game;
    game.drawGame();
    int time = 0;

    while (true) {

        game.updatePosPeople(buf);
        buf = 0;
        ++time;

        game.updatePosAnimal();
        game.updatePosVehicle(time);

        //Đây là if kết thúc
        if (game.getPeople().Y() == SIDEWALK[1]) {
            cout << "WIN";
            break;
        }

        //If impact ở đây
        if (game.checkImpact())
        {
            game.getPeople().drawDead();
      	}
        
        Sleep(100);
    }
}
int main()
{
    StartUp();

    thread sub(SubThread);

    do {
        buf = toupper(_getch());
    } while (buf != ESC);

    sub.join();
    return 0;
}