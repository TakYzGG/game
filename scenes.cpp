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
    // update
    player.setTimer(player.getTimer() + GetFrameTime());
    player.move();

    player.setFiring(player.isFiring());

    if (player.getFiring() && !player.getWasFiring()) {
        player.shoot();
        player.setTimer(0.0f);
    }

    else if (player.getFiring() && (player.getTimer() >= player.getCooldown())) {
        player.shoot();
        player.setTimer(0.0f);
    }

    player.setWasFiring(player.getFiring());

    for (int i = 0; i < enemys.size(); i++) {
        enemys[i]->move(player);
        enemys[i]->remove();
    }

    if (shoots.size() > 0) travelShoots();
}

void Game::draw(void) {
    ClearBackground(WHITE);
    interface.drawHudDebbug();
    interface.drawHud();
    interface.drawShoots();
    interface.drawPlayer();
    interface.drawEnemys();
}
