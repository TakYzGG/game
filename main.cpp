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
    
    GameScreen currentScreen = TITLE;

    InitWindow(screenWidth, screenHeight, "Game");

    SetTargetFPS(60);

    MainMenu menu;
    Game game;

    while (!WindowShouldClose()) {
        // update
        switch (currentScreen) {
            case TITLE:
                if (menu.update()) {
                    currentScreen = GAMEPLAY;
                }
                break;

            case GAMEPLAY:
                game.update();
                break;
        }

        // draw
        BeginDrawing();
        switch (currentScreen) {
            case TITLE:
                menu.draw();
                break;

            case GAMEPLAY:
                game.draw();
                break;
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
