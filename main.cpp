// -- Jugeo

// -- Librerias --
#include <iostream>
#include "classes.h"
using namespace std;

// -- Funcion principal --
int main(void) {
    GenericEntity entity(0, 0, 1, 5);
    Player player(0, 0, 1, 5);
    Shoot shoot(0, 0, 1, 5, 100, 0);

    /*
    player.shoot();
    player.shoot();
    player.shoot();
    player.shoot();
    */
    player.shoot();

    cout << "GenericEntity: " << endl;
    cout << entity.getPosX() << endl;
    cout << entity.getPosY() << endl;
    cout << entity.getSpeed() << endl;
    cout << entity.getRadio() << endl;

    cout << endl;

    cout << "Player: " << endl;
    cout << player.getPosX() << endl;
    cout << player.getPosY() << endl;
    cout << player.getSpeed() << endl;
    cout << player.getRadio() << endl;

    cout << endl;

    cout << "Shoot: " << endl;
    cout << shoot.getPosX() << endl;
    cout << shoot.getPosY() << endl;
    cout << shoot.getSpeed() << endl;
    cout << shoot.getRadio() << endl;
    cout << shoot.getDistance() << endl;
    cout << shoot.getTravel() << endl;

    cout << endl;
    for (int i = 0; i <= 100; i++) {
        travelShoots();
    }


    return 0;
}
