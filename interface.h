// -- Interfaz del juego --

#ifndef INTERFACE_H
#define INTERFACE_H

// -- Librerias --
#include "classes.h"

// -- Clase de la interfaz --
class Interface {
    private:
        int screenWidth;
        int screenHeight;
        int FPS;
        Player& player;

    public:
        Interface(Player& player);
        void drawHud(void);
        void drawPlayer(void);
        void drawShoots(void);
};

#endif
