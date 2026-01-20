// -- Menu principal del juego --

// -- Librerias --
#include <raylib.h>

#include "main_menu.h"

// -- Main menu Class --
// comprobar si se preciono entre
int MainMenu::update(void) {
    if (IsKeyPressed(KEY_ENTER)) {
        return 1;
    }
    
    return 0;
}

// dibujar pantalla de inicio
void MainMenu::draw(void) {
    ClearBackground(BLACK);
    DrawText("Preciona ENTER para comenzar", 100, 300, 40, WHITE);
}
