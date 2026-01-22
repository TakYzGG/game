// -- Menu de pausa --

// -- Librerias --
#include <raylib.h>

#include "pause.h"

int Pause::update(void) {
    if (IsKeyPressed(KEY_ENTER)) {
        return 1;
    }

    return 0;
}

void Pause::draw(void) {
    ClearBackground(GRAY);
    DrawText("Pausado", 400, 300, 30, RED);
}
