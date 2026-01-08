// -- Jugeo

// -- Librerias --
#include <iostream>
#include <raylib.h>
#include "scenes.h"
using namespace std;

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

// -- Funcion principal --
int main(void) {
    int screenWidth = 800;
    int screenHeight = 600;
    
    GameScreen currentScreen = GAMEPLAY;

    InitWindow(screenWidth, screenHeight, "Game");

    SetTargetFPS(60);

    // crear al jugador
    Game game;

    while (!WindowShouldClose()) {
        // update
        switch (currentScreen) {
            case GAMEPLAY:
                game.update();
                break;
        }

        // draw
        BeginDrawing();
        switch (currentScreen) {
            case GAMEPLAY:
                game.draw();
                break;
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
