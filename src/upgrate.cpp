// -- Escena para elegir las mejoras --

// -- Librerias --
#include <raylib.h>
#include <iostream> // esto es temporal

#include "upgrate.h"
#include "player.h"

using namespace std; // esto es temporal

// -- Upgrate Class --
Upgrate::Upgrate() {
}

void Upgrate::basicUpgrate(void) {
    player.upgrate();
    player.downgrate();

    player.setPoints(player.getPoints() - 3);
}

void Upgrate::normalUpgrate(void) {
    player.upgrate();
    player.upgrate();
    player.downgrate();

    player.setPoints(player.getPoints() - 6);
}

void Upgrate::bestUpgrate(void) {
    player.upgrate();
    player.upgrate();
    player.upgrate();

    player.setPoints(player.getPoints() - 9);
}

int Upgrate::update(void) {
    if (IsKeyPressed(KEY_ONE) && (player.getPoints() >= 3)) {
        cout << "Mejora basica" << endl;
        basicUpgrate();
        return 1;
    }

    if (IsKeyPressed(KEY_TWO) && (player.getPoints() >= 6)) {
        cout << "Mejora nolmal" << endl;
        normalUpgrate();
        return 1;
    }

    if (IsKeyPressed(KEY_THREE) && (player.getPoints() >= 9)) {
        cout << "Mejora pro" << endl;
        bestUpgrate();
        return 1;
    }

    if (IsKeyPressed(KEY_FOUR)) {
        cout << "Skip mejoras" << endl;
        return 1;
    }

    return 0;
}

void Upgrate::draw(void) {
    ClearBackground(GRAY);
    DrawText("1. Mejora basica [3 puntos]", 300, 100, 20, BLACK);
    DrawText("2. Mejora normal [6 puntos]", 300, 120, 20, BLACK);
    DrawText("3. Mejora pro [9 puntos]", 300, 140, 20, BLACK);
    DrawText("4. Skip mejoras", 300, 160, 20, BLACK);
}
