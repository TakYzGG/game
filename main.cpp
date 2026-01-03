// -- Jugeo

// -- Librerias --
#include <iostream>
#include "classes.h"
using namespace std;

// -- Funcion principal --
int main(void) {
    GenericEntity entity(0, 0, 1, 5);

    cout << entity.getPosX() << endl;
    cout << entity.getPosY() << endl;
    cout << entity.getSpeed() << endl;
    cout << entity.getRadio() << endl;

    return 0;
}
