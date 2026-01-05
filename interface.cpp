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

void Interface::drawHud(void) {
    DrawText(TextFormat("Player X: %d", player.getPosX()), 10, 10, 20, BLACK);
    DrawText(TextFormat("Player Y: %d", player.getPosY()), 10, 30, 20, BLACK);
    DrawText(TextFormat("Player id: %p", &player), 10, 50, 20, BLACK);
    DrawText(TextFormat("Count shoots: %d", shoots.size()), 10, 70, 20, BLACK);
}

void Interface::drawPlayer(void) {
    DrawCircle(player.getPosX(), player.getPosY(), player.getRadio(), RED);
}

void Interface::drawShoots(void) {
    for (int i = 0; i < shoots.size(); i++) {
        DrawCircle(shoots[i]->getPosX(), shoots[i]->getPosY(), shoots[i]->getRadio(), BLUE);
    }
}
