// -- Clase encargada de ejecutar el bucle del juego --

#ifndef GAME_H
#define GAME_H

// -- Librerias --
#include <string>

#include "interface.h"

// Game Class
class Game {
    private:
        // -- Atributes --
        Interface interface;
        int round = 1;
        int mejoras = 0;
        std::string roundStr;

    public:
        // -- Constructor --
        Game();

        // -- Methods --
        void updateRoundStr(void);
        int update(void);
        void draw(void);
};

#endif
