// -- Clase encargada de ejecutar el bucle del juego --

#ifndef GAME_H
#define GAME_H

// -- Librerias --
#include "interface.h"

// Game Class
class Game {
    private:
        // -- Atributes --
        Interface interface;
        int round = 1;
        int mejoras = 0;

    public:
        // -- Constructor --
        Game();

        // -- Methods --
        int update(void);
        void draw(void);
};

#endif
