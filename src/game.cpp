// -- Clase encargada de ejecutar el bucle del juego --

// -- Librerias --
#include <raylib.h>
#include <string>

#include "game.h"
#include "shoot.h"
#include "player.h"
#include "interface.h"
#include "enemy.h"
#include "functions.h"

// -- Game Class --
// -- Constructor --
Game::Game()
    :interface()
    {
    }

// -- Methods --
// actualizar el str de la ronda
void Game::updateRoundStr(void) {
    this-> roundStr = "Ronda: " + std::to_string(round);
}

// actualizar datos del juego
int Game::update(void) {
    // -- Update --

    // si no hay mas enemigos los genera nuevamente
    if (enemys.size() == 0) {
        generateEnemys(round);
        player.setPoints(player.getPoints() + 1);

        if ((round != 0) && (round % 3 == 0)) mejoras = 1;

        round += 1;
        updateRoundStr();
    }

    // activar el menu de pausa
    if (IsKeyPressed(KEY_ENTER)) {
        return 2;
    }

    // modificar el timer del jugador
    player.setTimer(player.getTimer() + GetFrameTime());

    // mover al jugador
    player.move();

    // comprobar si el jugador esta disparando
    player.setFiring(player.isFiring());

    // hacer que el jugador dispare instantaneamente si no estaba disparando
    if (player.getFiring() && !player.getWasFiring()) {
        player.shoot();
        player.setTimer(0.0f);
    }

    // hacer que el jugador dispare si ya estaba disparando
    else if (player.getFiring() && (player.getTimer() >= player.getCooldown())) {
        player.shoot();
        player.setTimer(0.0f);
    }

    // guardar el ultimo estado de disparo del jugador
    player.setWasFiring(player.getFiring());

    // actualizar enemigos
    for (int i = 0; i < enemys.size(); i++) {
        enemys[i]->move();
        enemys[i]->killPlayer();
        enemys[i]->remove();
    }

    // actualizar disparos
    if (shoots.size() > 0) travelShoots();

    if (mejoras) {
        mejoras = 0;
        return 1;
    }

    if (player.getIsDead()) {
        return 3;
    }

    return 0;

}

// actualizar GUI
void Game::draw(void) {
    ClearBackground(WHITE);
    interface.drawHudDebbug();
    interface.drawHud();
    interface.drawShoots();
    interface.drawPlayer();
    interface.drawEnemys();
    DrawText(roundStr.c_str(), calcCenterText(roundStr.c_str(), 20), 580, 20, BLACK);
}

void Game::restart(void) {
    round = 0;
    mejoras = 0;
    player.setPosition();
    player.setIsDead(0);
    enemys.clear();
    shoots.clear();
}
