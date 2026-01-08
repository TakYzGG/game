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
    DrawText(TextFormat("Player X: %f", player.getPosX()), 10, 520, 20, BLACK);
    DrawText(TextFormat("Player Y: %f", player.getPosY()), 10, 540, 20, BLACK);
    DrawText(TextFormat("Player id: %p", &player), 10, 560, 20, BLACK);
    DrawText(TextFormat("Count shoots: %d", shoots.size()), 10, 580, 20, BLACK);
}

// dibujar la hud del juego
void Interface::drawHud(void) {
    DrawText(TextFormat("Speed: %f", player.getSpeed()), 10, 10, 20, BLACK);
    DrawText(TextFormat("Radio: %f", player.getRadio()), 10, 30, 20, BLACK);
    DrawText(TextFormat("Shoot distance: %f", player.getShootDistance()), 10, 50, 20, BLACK);
    DrawText(TextFormat("Shoot speed: %f", player.getShootSpeed()), 10, 70, 20, BLACK);
    DrawText(TextFormat("Shoot radio: %d", player.getShootRadio()), 10, 90, 20, BLACK);

    DrawText(TextFormat("FPS: %d", GetFPS()), 700, 10, 20, BLACK);
}

// dibujar al jugador
void Interface::drawPlayer(void) {
    DrawCircle(player.getPosX(), player.getPosY(), player.getRadio(), RED);
}

void Interface::drawEnemys(void) {
    for (int i = 0; i < enemys.size(); i++) {
        DrawCircle(enemys[i]->getPosX(), enemys[i]->getPosY(), enemys[i]->getRadio(), GREEN);
    }
}

// dibujar los disparos
void Interface::drawShoots(void) {
    for (int i = 0; i < shoots.size(); i++) {
        DrawCircle(shoots[i]->getPosX(), shoots[i]->getPosY(), shoots[i]->getRadio(), BLUE);
    }
}
