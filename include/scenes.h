// -- Escenas del juego --

#ifndef SCENES_H
#define SCENES_H

// -- Librerias -
#include "classes.h"
#include "interface.h"

// Game Class
class Game {
    private:
        // -- Atributes --
        Player player;
        Interface interface;
        int round = 0;

    public:
        // -- Constructor --
        Game();

        // -- Getters --

        // -- Setters --

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
