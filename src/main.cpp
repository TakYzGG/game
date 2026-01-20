// -- Archivo principal del programa --

// -- Librerias --
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#include "main_menu.h"
#include "game.h"
#include "player.h"
using namespace std;

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

// -- Funcion principal --
int main(void) {
    srand(time(NULL));
    int screenWidth = 800;
    int screenHeight = 600;
    
    // primera escena del juego
    GameScreen currentScreen = TITLE;

    // crear la ventana
    InitWindow(screenWidth, screenHeight, "Game");

    // settear los fps
    SetTargetFPS(60);

    // crear objetos de clase
    MainMenu menu;
    Game game;
    player.setPosition();

    // bucle principal
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

    // cerrar la ventana
    CloseWindow();

    return 0;
}
