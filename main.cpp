// -- Jugeo

// -- Librerias --
#include <iostream>
#include "classes.h"
using namespace std;

// -- Funcion principal --
int main(void) {
    GenericEntity entity(0, 0, 1, 5);
    Player player(0, 0, 1, 5);

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

    return 0;
}
