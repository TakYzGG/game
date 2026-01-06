// -- Jugeo

// -- Librerias --
#include <iostream>
#include <raylib.h>
#include "classes.h"
#include "interface.h"
using namespace std;

// -- Funcion principal --
int main(void) {
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Game");

    SetTargetFPS(60);

    // crear al jugador
    Player player;
    Interface interface(player);

    cout << &player << endl;

    float cooldown = 0.5f;
    float timer = 0.0f;

    int firing = 0;
    int wasFiring = 0;

    while (!WindowShouldClose()) {
        // update
        timer += GetFrameTime();
        player.move();

        firing = player.isFiring();

        if (firing && !wasFiring) {
            player.shoot();
            timer = 0.0f;
        }

        else if (firing && timer >= cooldown) {
            player.shoot();
            timer = 0.0f;
        }

        wasFiring = firing;

        travelShoots();

        // draw
        BeginDrawing();
            ClearBackground(WHITE);
            interface.drawHudDebbug();
            interface.drawHud();
            interface.drawShoots();
            interface.drawPlayer();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
