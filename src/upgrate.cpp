// -- Escena para elegir las mejoras --

// -- Librerias --
#include <raylib.h>
#include <iostream> // esto es temporal

#include "upgrate.h"
#include "player.h"
#include "functions.h"
#include "button.h"

using namespace std; // esto es temporal

Button buttons[] = {Button(400, 100, 100, 40, "Mejora Basica"),
                    Button(400, 150, 100, 40, "Mejora Normal"),
                    Button(400, 200, 100, 40, "Mejora Pro"),
                    Button(400, 250, 100, 40, "Continuar"),
                    };

int buttons_size = sizeof(buttons) / sizeof(buttons[0]);

// -- Upgrate Class --
Upgrate::Upgrate() {
}

void Upgrate::basicUpgrate(void) {
    if (player.getPoints() >= 3) {
        player.upgrate();
        player.downgrate();

        player.setPoints(player.getPoints() - 3);
    }
}

void Upgrate::normalUpgrate(void) {
    if (player.getPoints() >= 6) {
        player.upgrate();
        player.upgrate();
        player.downgrate();

        player.setPoints(player.getPoints() - 6);
    }
}

void Upgrate::bestUpgrate(void) {
    if (player.getPoints() >= 9) {
        player.upgrate();
        player.upgrate();
        player.upgrate();

        player.setPoints(player.getPoints() - 9);
    }
}

int Upgrate::exec_buttons(void) {
    switch (index) {
        case 0: basicUpgrate(); break;
        case 1: normalUpgrate(); break;
        case 2: bestUpgrate(); break;
        case 3: index = 0; return 1;
    }

    return 0;
}

int Upgrate::update(void) {
    if (IsKeyPressed(KEY_UP) && index > 0) index--;

    if (IsKeyPressed(KEY_DOWN) && index < (buttons_size -1)) index++;

    if (IsKeyPressed(KEY_ENTER)) return exec_buttons();

    return 0;
}

void Upgrate::draw(void) {
    ClearBackground(GRAY);
    for (int i = 0; i < buttons_size; i++) {
        if (index == i) {
            buttons[i].drawRectangle(DARKBLUE);
        } else {
            buttons[i].drawRectangle(BLUE);
        }
        buttons[i].drawText(BLACK);
    }
}
