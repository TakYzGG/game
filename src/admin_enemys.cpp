// -- Clase para generar a los enemigos --

// -- Librerias --
#include <raylib.h>
#include <vector>
#include <stdlib.h>
#include <bits/stdc++.h>

#include "admin_enemys.h"
#include "enemy.h"
#include "player.h"

using namespace std;

int AdminEnemys::getEnemysCount(void) {
    return enemys.size();
}

Enemy* AdminEnemys::getEnemy(int index) {
    return enemys[index];
}

// -- aumentar el contador de enemigos --
void AdminEnemys::addEnemys(void) {
    count_enemys += (rand() % 5) + 1;
}

// -- Generar a los enemigos --
void AdminEnemys::generate(void) {
    addEnemys();

    int i = 0;

    while (i < count_enemys) {
        int x = rand() % GetScreenWidth();
        int y = rand() % GetScreenHeight();

        float dx = x - player.getPosX();
        float dy = y - player.getPosY();
        float dist = sqrtf(dx * dx + dy * dy);

        /* 8 es el radio del enemigo, 80 es el radio del circulo imbicible donde
           no pueden spawnear */
        if (dist + 8 <= 80) {
            continue;
        }

        enemys.push_back(new Enemy(x, y));
        i++;
    }
}

void AdminEnemys::updateEnemys(void) {
    for (int i = 0; i < enemys.size(); i++) {
        enemys[i]->move();
        enemys[i]->killPlayer();
        remove(enemys[i]);
    }
}

void AdminEnemys::remove(Enemy *enemy) {
    auto it = find(enemys.begin(), enemys.end(), enemy);
    if (it != enemys.end() && (*it)->isDead()) {
        delete *it;
        enemys.erase(it);
    }
}

void AdminEnemys::reset(void) {
    enemys.clear();
    count_enemys = 0;
}
