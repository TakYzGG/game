// -- Clase del enemigo del juego --

#ifndef ENEMY_H
#define ENEMY_H

// -- Librerias --
#include "generic_entity.h"
#include "player.h"

// -- Enemy Class --
class Enemy: public GenericEntity {
    public:
        // -- Constructor --
        Enemy(int x, int y);

        // -- Methods --
        void move(void);
        int isDead(void);
        void killPlayer(void);
};

#endif
