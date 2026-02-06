// -- Interfaz del juego --

// -- Librerias --
#include <raylib.h>

#include "shoot.h"
#include "player.h"
#include "interface.h"
#include "enemy.h"

using namespace std;

// -- Methods --
// dibujar el hud debbug 
void Interface::drawHudDebbug(void) {
    DrawText(TextFormat("Count Enemis: %d", enemys.size()), 10, 480, 20, BLACK);
    DrawText(TextFormat("Player move: %f", GetFrameTime() * 6.0f * (player.getSpeed() * 10.0f) ), 10, 500, 20, BLACK);
    DrawText(TextFormat("Player X: %f", player.getPosX()), 10, 520, 20, BLACK);
    DrawText(TextFormat("Player Y: %f", player.getPosY()), 10, 540, 20, BLACK);
    DrawText(TextFormat("Player id: %p", &player), 10, 560, 20, BLACK);
    DrawText(TextFormat("Count shoots: %d", shoots.size()), 10, 580, 20, BLACK);
    DrawCircle(player.getPosX(), player.getPosY(), 80, YELLOW);

}

// dibujar la hud del juego
void Interface::drawHud(void) {
    DrawText("Estadisticas:", 10, 10, 20, BLACK);
    DrawText(TextFormat("Velocidad: %.2f", player.getSpeed()), 10, 30, 20, RED);
    DrawText(TextFormat("Tamano: %d", player.getRadio()), 10, 50, 20, RED);
    DrawText(TextFormat("Fire rate: %.2f", player.getCooldown()), 10, 70, 20, RED);
    DrawText(TextFormat("Velocidad disparo: %.2f", player.getShootSpeed()), 10, 90, 20, BLUE);
    DrawText(TextFormat("Tamano disparo: %d", player.getShootRadio()), 10, 110, 20, BLUE);
    DrawText(TextFormat("Distancia: %.0f", player.getShootDistance()), 10, 130, 20, BLUE);

    DrawText(TextFormat("FPS: %d", GetFPS()), 700, 10, 20, BLACK);
}

// dibujar al jugador
void Interface::drawPlayer(void) {
    DrawCircle(player.getPosX(), player.getPosY(), player.getRadio(), RED);
}

// dibujar a los enemigos
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
