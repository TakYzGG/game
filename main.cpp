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
    Player player((screenWidth / 2), (screenHeight / 2));
    Interface interface(player);

    cout << &player << endl;

    while (!WindowShouldClose()) {
        // update
        player.move();
        player.shoot();
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
