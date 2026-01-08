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

    public:
        // -- Constructor --
        Game();

        // -- Getters --
        float getTimer(void);
        int getFiring(void);
        int getWasFiring(void);

        // -- Setters --
        void setTimer(float timer);
        void setFiring(int firing);
        void getWasFiring(int wasfiring);

        // -- Methods --
        void update(void);
        void draw(void);
};

#endif
