// -- Interfaz del juego --

// -- Librerias --
#include <raylib.h>
#include <iostream>
#include "classes.h"
#include "interface.h"

using namespace std;

// -- Clase de la interfaz --
// -- Constructor --
Interface::Interface(Player& player)
    : player(player)
    {
    }

// -- Methods --
// dibujar el hud debbug 
void Interface::drawHudDebbug(void) {
    DrawText(TextFormat("Player move: %f", GetFrameTime() * 6.0f * (player.getSpeed() * 10.0f) ), 10, 500, 20, BLACK);
    DrawText(TextFormat("Player X: %d", player.getPosX()), 10, 520, 20, BLACK);
    DrawText(TextFormat("Player Y: %d", player.getPosY()), 10, 540, 20, BLACK);
    DrawText(TextFormat("Player id: %p", &player), 10, 560, 20, BLACK);
    DrawText(TextFormat("Count shoots: %d", shoots.size()), 10, 580, 20, BLACK);
}

// dibujar la hud del juego
void Interface::drawHud(void) {
    DrawText(TextFormat("Speed: %d", player.getSpeed()), 10, 10, 20, BLACK);
    DrawText(TextFormat("Radio: %d", player.getRadio()), 10, 30, 20, BLACK);
    DrawText(TextFormat("Shoot distance: %d", player.getShootDistance()), 10, 50, 20, BLACK);
    DrawText(TextFormat("Shoot speed: %d", player.getShootSpeed()), 10, 70, 20, BLACK);
    DrawText(TextFormat("Shoot radio: %d", player.getShootRadio()), 10, 90, 20, BLACK);

    DrawText(TextFormat("FPS: %d", GetFPS()), 700, 10, 20, BLACK);
}

// dibujar al jugador
void Interface::drawPlayer(void) {
    DrawCircle(player.getPosX(), player.getPosY(), player.getRadio(), RED);
}

// dibujar los disparos
void Interface::drawShoots(void) {
    for (int i = 0; i < shoots.size(); i++) {
        DrawCircle(shoots[i]->getPosX(), shoots[i]->getPosY(), shoots[i]->getRadio(), BLUE);
    }
}
