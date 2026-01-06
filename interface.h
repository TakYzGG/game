// -- Interfaz del juego --

#ifndef INTERFACE_H
#define INTERFACE_H

// -- Librerias --
#include "classes.h"

// -- Clase de la interfaz --
class Interface {
    private:
        // -- Atributes --
        int screenWidth;
        int screenHeight;
        int FPS;
        Player& player;

    public:
        // -- Constructor
        Interface(Player& player);

        // -- Methods --
        void drawHudDebbug(void);
        void drawHud(void);
        void drawPlayer(void);
        void drawEnemys(void);
        void drawShoots(void);
};

#endif
