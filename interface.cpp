// -- Interfaz del juego --

// -- Librerias --
#include <raylib.h>
#include <iostream>
#include "classes.h"
#include "interface.h"

using namespace std;

// -- Clase de la interfaz --
Interface::Interface(Player& player)
    : player(player)
    {
    }

void Interface::drawPlayer(void) {
    DrawCircle(player.getPosX(), player.getPosY(), player.getRadio(), RED);
}
