// -- Clase del jugador --

// -- Librerias --
#include <raylib.h>
#include <stdlib.h>

#include "player.h"
#include "generic_entity.h"
#include "shoot.h"
#include "functions.h"

Player player;

// -- Player Class --
// -- Constructor --
Player::Player()
    :GenericEntity(0, 0, 1, 8)
    {
        setCooldown(0.5f);
        setShootSpeed(1.0f);
        setShootRadio(5);
        setShootDistance(100);
        setTimer(0.0f);
        setFiring(0);
        setWasFiring(0);
    }

// -- Private Methods --
int Player::upgrateIntAtribute(int max) {
    int upgrate = 0;
    int n = rand() % max;

    for (int i = 0; i <= n; i++) {
        upgrate++;
    }

    return upgrate;
}

float Player::upgrateFloatAtribute(int max) {
    float upgrate = 0.0f;
    int n = rand() % max; // maximo 0.50

    for (int i = 0; i <= n; i++) {
        upgrate += 0.10f;
    }

    return upgrate;
}

// mejoras
void Player::upgrateSpeed(void) {
    setSpeed(getSpeed() + upgrateFloatAtribute(5));
}

void Player::upgrateRadio(void) {
    setRadio(getRadio() - upgrateIntAtribute(3));
}

void Player::upgrateCooldown(void) {
    setCooldown(getCooldown() - upgrateFloatAtribute(3));
}

void Player::upgrateShootSpeed(void) {
    setShootSpeed(getShootSpeed() - upgrateFloatAtribute(4));
}

void Player::upgrateShootRadio(void) {
    setShootRadio(getShootRadio() + upgrateIntAtribute(3));
}

void Player::upgrateShootDistance(void) {
    // el valor minimo de esto es 50 (49 de la suma y 1 del minimo de la func)
    setShootDistance(getShootDistance() + (upgrateIntAtribute(100) + 49));
}

// downgrate
void Player::downgrateSpeed(void) {
    setSpeed(getSpeed() - upgrateFloatAtribute(5));
}

void Player::downgrateRadio(void) {
    setRadio(getRadio() + upgrateIntAtribute(3));
}

void Player::downgrateCooldown(void) {
    setCooldown(getCooldown() + upgrateFloatAtribute(3));
}

void Player::downgrateShootSpeed(void) {
    setShootSpeed(getShootSpeed() + upgrateFloatAtribute(4));
}

void Player::downgrateShootRadio(void) {
    setShootRadio(getShootRadio() - upgrateIntAtribute(3));
}

void Player::downgrateShootDistance(void) {
    // el valor minimo de esto es 50 (49 de la suma y 1 del minimo de la func)
    setShootDistance(getShootDistance() - (upgrateIntAtribute(100) + 49));
}

// -- Getters --
float Player::getCooldown(void) {return cooldown;}
float Player::getShootSpeed(void) {return shootSpeed;}
int Player::getShootRadio(void) {return shootRadio;}
float Player::getShootDistance(void) {return shootDistance;}
float Player::getTimer(void) {return timer;}
int Player::getFiring(void) {return firing;}
int Player::getWasFiring(void) {return wasFiring;}

// -- Setters --
void Player::setPosition(void) {
    setPosX(GetScreenWidth() / 2);
    setPosY(GetScreenHeight() / 2);
}

// modificar el cooldown entre disparos
void Player::setCooldown(float cooldown) {
    if ((cooldown >= 0.1f) && (cooldown <= 1.0f)) {
        this->cooldown = cooldown;
    }
}

// modificar la velocidad de los disparos
void Player::setShootSpeed(float speed) {
    if ((speed >= 0.5f) && (speed <= 2.0f)) {
        this->shootSpeed = speed;
    }
}

// modificar el radio de los disparos
void Player::setShootRadio(int radio) {
    if ((radio >= 5) && (radio <= 10)) {
        this->shootRadio = radio;
    }
}

// modificar la distancia maxima de los disparos
void Player::setShootDistance(float distance) {
    if ((distance >= 50.0f) && (distance <= 350.0f)) {
        this->shootDistance = distance;
    }
}

void Player::setTimer(float timer) {
    if (timer >= 0.0f) {
        this->timer = timer;
    } 
}

void Player::setFiring(int firing) {
    if ((firing == 1) || (firing == 0)) {
        this->firing = firing;
    }
}

void Player::setWasFiring(int wasFiring) {
    if ((wasFiring == 1) || (wasFiring == 0)) {
        this->wasFiring = wasFiring;
    }
}

// -- Methods --
// movimiento del jugador
void Player::move(void) {
    float speed = calcSpeed(getSpeed());
    // arriba
    if (IsKeyDown(KEY_W)) {
        setPosY(getPosY() - speed);
    }

    // izquierda
    if (IsKeyDown(KEY_A)) {
        setPosX(getPosX() - speed);
    }

    // abajo
    if (IsKeyDown(KEY_S)) {
        setPosY(getPosY() + speed);
    }

    // derecha
    if (IsKeyDown(KEY_D)) {
        setPosX(getPosX() + speed);
    }
}

// comprobar si el jugador esta dispando
int Player::isFiring(void) {
    if (IsKeyDown(KEY_UP)) return 1;
    if (IsKeyDown(KEY_LEFT)) return 1;
    if (IsKeyDown(KEY_DOWN)) return 1;
    if (IsKeyDown(KEY_RIGHT)) return 1;
    return 0;
}

// hacer que el jugador pueda disparar
void Player::shoot(void) {
    // arriba izquierda
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'E'));
        return;
    }

    // arriba derecha
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'F'));
        return;
    }

    // abajo izquierda
    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'G'));
        return;
    }

    // abajo derecha
    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'H'));
        return;
    }

    // arriba
    if (IsKeyDown(KEY_UP)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'A'));
        return;
    }

    // izquierda
    if (IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'B'));
        return;
    }

    // abajo
    if (IsKeyDown(KEY_DOWN)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'C'));
        return;
    }

    // derecha
    if (IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'D'));
        return;
    }
}

// mejoras del jugador
void Player::upgrate(void) {
    int num = rand() % 6; // generar numero aleatorio para elegir que mejorar

    // todos los casos posibles
    switch (num) {
        case 0: upgrateSpeed(); break;
        case 1: upgrateRadio(); break;
        case 2: upgrateCooldown(); break;
        case 3: upgrateShootSpeed(); break;
        case 4: upgrateShootRadio(); break;
        case 5: upgrateShootDistance(); break;
    }
}

// downgrate del jugador
void Player::downgrate(void) {
    int num = rand() % 6; // generar numero aleatorio para elegir que empeorar

    // todos los casos posibles
    switch (num) {
        case 0: downgrateSpeed(); break;
        case 1: downgrateRadio(); break;
        case 2: downgrateCooldown(); break;
        case 3: downgrateShootSpeed(); break;
        case 4: downgrateShootRadio(); break;
        case 5: downgrateShootDistance(); break;
    }
}
