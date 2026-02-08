// -- Clase del enemigo del juego --

// -- Librerias --
#include <raylib.h>

#include "enemy.h"
#include "generic_entity.h"
#include "player.h"
#include "shoot.h"
#include "functions.h"

// -- Enemy Class --
// -- Constructor --
Enemy::Enemy(int x, int y)
    :GenericEntity(x, y, 1, 8)
    {
    }

// mover al enemigo a la posicion del jugador
void Enemy::move(void) {
    float speed = calcSpeed(getSpeed());
    if (getPosX() <= player.getPosX()) {
        float new_x = player.getPosX() - getPosX();
        setPosX(getPosX() + speed);
    }

    if (getPosX() >= player.getPosX()) {
        float new_x = player.getPosX() - getPosX();
        setPosX(getPosX() - speed);
    }

    if (getPosY() <= player.getPosY()) {
        float new_x = player.getPosY() - getPosY();
        setPosY(getPosY() + speed);
    }

    if (getPosY() >= player.getPosY()) {
        float new_x = player.getPosY() - getPosY();
        setPosY(getPosY() - speed);
    }
}

// comprobar si el disparo ya recorrio la distancia maxima
int Enemy::isDead(void) {
  for (int i = 0; i < shoots.size(); i++)
    {
        // diferencia de posiciones
        float dx = getPosX() - shoots[i]->getPosX();
        float dy = getPosY() - shoots[i]->getPosY();

        float distSq = dx*dx + dy*dy;
        float radiusSum = getRadio() + shoots[i]->getRadio();

        // comprobar si el disparo esta dentro del radio del enemigo
        if (distSq <= radiusSum * radiusSum)
        {
            shoots[i]->setStatus(1);
            return 1;
        }
    }
    return 0;
}

// -- matar al jugador --
void Enemy::killPlayer(void) {
    // hay que mejorar esta linea porque es demaciado fea
    if (IsCircleInOtherCircle(
                player.getPosX(), player.getPosY(), player.getRadio(),
                getPosX(), getPosY(), getRadio())
            ) player.setIsDead(1);
}
