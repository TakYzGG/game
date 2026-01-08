// -- Escenas del juego --

#ifndef SCENES_H
#define SCENES_H

// -- Librerias -
#include "classes.h"
#include "interface.h"

class Game {
    private:
        // -- Atributes --
        Player player;
        Interface interface;
        float timer = 0.0f;

        int firing = 0;
        int wasFiring = 0;

    public:
        Game();
        // -- Getters --
        Player getPlayer(void);

        // -- Methods --
        void update(void);
        void draw(void);
};

#endif
