// -- Escenas del juego --

// -- Librerias --
#include <raylib.h>
#include "scenes.h"
#include "classes.h"
#include "interface.h"

// -- Game Class --
// -- Constructor --
Game::Game()
    : player(), interface(player)
    {
    }

// -- Methods --
// actualizar datos del juego
void Game::update(void) {
    // -- Update --
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
        enemys[i]->move(player);
        enemys[i]->remove();
    }

    // actualizar disparos
    if (shoots.size() > 0) travelShoots();
}

// actualizar GUI
void Game::draw(void) {
    ClearBackground(WHITE);
    interface.drawHudDebbug();
    interface.drawHud();
    interface.drawShoots();
    interface.drawPlayer();
    interface.drawEnemys();
}
