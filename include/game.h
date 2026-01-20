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
        int round = 0;

    public:
        // -- Constructor --
        Game();

        // -- Methods --
        void update(void);
        void draw(void);
};

#endif
