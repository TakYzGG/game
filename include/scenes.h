// -- Escenas del juego --

#ifndef SCENES_H
#define SCENES_H

// -- Librerias -
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

// -- Main menu Class --
class MainMenu {
    public:
        int update(void);
        void draw(void);
};

#endif
