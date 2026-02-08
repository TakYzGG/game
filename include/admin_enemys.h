// -- Clase para generar a los enemigos --

#ifndef ADMIN_ENEMYS_H
#define ADMIN_ENEMYS_H

// -- Librerias --
#include <vector>

#include "enemy.h"

using namespace std;

class AdminEnemys {
    private:
        vector<Enemy*> enemys;
        int count_enemys = 0;

    public:
        // -- Getters --
        int getEnemysCount(void);
        Enemy* getEnemy(int index);

        // -- Methods --
        void addEnemys(void);
        void generate(void);
        void updateEnemys(void);
        void remove(Enemy *enemy);
        void reset(void);
};

#endif
