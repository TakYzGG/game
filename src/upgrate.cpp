// -- Escena para elegir las mejoras --

// -- Librerias --
#include <raylib.h>
#include <iostream> // esto es temporal

#include "upgrate.h"
#include "player.h"
#include "functions.h"

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
    DrawText(basic_upgrate, calcCenterText(basic_upgrate, font_size), 100, font_size, RED);
    DrawText(normal_upgrate, calcCenterText(normal_upgrate, font_size), 130, font_size, YELLOW);
    DrawText(pro_upgrate, calcCenterText(pro_upgrate, font_size), 160, font_size, GREEN);
    DrawText(skip_upgrate, calcCenterText(skip_upgrate, font_size), 190, font_size, BLACK);
}
