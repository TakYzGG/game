// -- Escenas del juego --

// -- Librerias --
#include <raylib.h>
#include "scenes.h"
#include "classes.h"
#include "interface.h"

Game::Game()
    : player(), interface(player)
    {}

void Game::update(void) {
        // update
        timer += GetFrameTime();
        player.move();

        firing = player.isFiring();

        if (firing && !wasFiring) {
            player.shoot();
            timer = 0.0f;
        }

        else if (firing && (timer >= player.getCooldown())) {
            player.shoot();
            timer = 0.0f;
        }

        wasFiring = firing;

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
