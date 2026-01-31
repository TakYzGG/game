// -- Clase del enemigo del juego --

#ifndef ENEMY_H
#define ENEMY_H

// -- Librerias --
#include <vector>

#include "generic_entity.h"
#include "player.h"

using namespace std;

// -- Enemy Class --
class Enemy: public GenericEntity {
    public:
        // -- Constructor --
        Enemy(int x, int y);

        // -- Methods --
        void move(void);
        int isDead(void);
        void remove(void);
        void killPlayer(void);
};

extern vector<Enemy*> enemys;
void generateEnemys(int round);

#endif
