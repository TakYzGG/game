// -- Jugeo

// -- Librerias --
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
    Player player((screenWidth / 2), (screenHeight / 2), 1, 8);
    Interface interface(player);

    while (!WindowShouldClose()) {
        // update

        // draw
        BeginDrawing();
            ClearBackground(WHITE);
            interface.drawPlayer();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
