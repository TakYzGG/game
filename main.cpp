// -- Jugeo

// -- Librerias --
#include <iostream>
#include <raylib.h>
#include "scenes.h"
using namespace std;

// -- Funcion principal --
int main(void) {
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Game");

    SetTargetFPS(60);

    // crear al jugador
    Game game;

    while (!WindowShouldClose()) {
        // update
        game.update();

        // draw
        BeginDrawing();
            game.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
