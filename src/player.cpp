// -- Clase del jugador --

// -- Librerias --
#include <raylib.h>
#include <stdlib.h>
#include <iostream>

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
        setPoints(0);
    }

// -- Private Methods --
void Player::upgrateSpeed(void) {
    setSpeed(getSpeed() + 0.10f);
}

void Player::upgrateRadio(void) {
    setRadio(getRadio() - 1);
}

void Player::upgrateCooldown(void) {
    setCooldown(getCooldown() - 0.10f);
}

void Player::upgrateShootSpeed(void) {
    setShootSpeed(getShootSpeed() + 0.10f);
}

void Player::upgrateShootRadio(void) {
    setShootRadio(getShootRadio() + 1);
}

void Player::upgrateShootDistance(void) {
    setShootDistance(getShootDistance() + 50);
}

// downgrate
void Player::downgrateSpeed(void) {
    setSpeed(getSpeed() - 0.10f);
}

void Player::downgrateRadio(void) {
    setRadio(getRadio() + 1);
}

void Player::downgrateCooldown(void) {
    setCooldown(getCooldown() + 0.10f);
}

void Player::downgrateShootSpeed(void) {
    setShootSpeed(getShootSpeed() - 0.10f);
}

void Player::downgrateShootRadio(void) {
    setShootRadio(getShootRadio() - 1);
}

void Player::downgrateShootDistance(void) {
    setShootDistance(getShootDistance() - 50);
}

// -- Getters --
float Player::getCooldown(void) {return cooldown;}
float Player::getShootSpeed(void) {return shootSpeed;}
int Player::getShootRadio(void) {return shootRadio;}
float Player::getShootDistance(void) {return shootDistance;}
float Player::getTimer(void) {return timer;}
int Player::getFiring(void) {return firing;}
int Player::getWasFiring(void) {return wasFiring;}
int Player::getPoints(void) {return points;}

// -- Setters --
void Player::setPosition(void) {
    setPosX(GetScreenWidth() / 2);
    setPosY(GetScreenHeight() / 2);
}

// modificar el cooldown entre disparos
void Player::setCooldown(float cooldown) {
    if ((cooldown >= 0.1f) && (cooldown <= 1.0f)) {
        this->cooldown = cooldown;
        return;
    }

    if (cooldown > 1.0f) {
        this->cooldown = 1.0f;
        return;
    }

    if (cooldown < 0.1f) {
        this->cooldown = 0.1f;
        return;
    }
}

// modificar la velocidad de los disparos
void Player::setShootSpeed(float speed) {
    if ((speed >= 0.5f) && (speed <= 2.0f)) {
        this->shootSpeed = speed;
        return;
    }

    if (speed > 2.0f) {
        this->shootSpeed = 2.0f;
        return;
    }

    if (speed < 0.5f) {
        this->shootSpeed = 0.5f;
        return;
    }
}

// modificar el radio de los disparos
void Player::setShootRadio(int radio) {
    if ((radio >= 5) && (radio <= 10)) {
        this->shootRadio = radio;
        return;
    }

    if (radio > 10) {
        this->shootRadio = 10;
        return;
    }

    if (radio < 5) {
        this->shootRadio = 5;
        return;
    }
}

// modificar la distancia maxima de los disparos
void Player::setShootDistance(float distance) {
    if ((distance >= 50.0f) && (distance <= 350.0f)) {
        this->shootDistance = distance;
        return;
    }

    if (distance < 50.0f) {
        this->shootDistance = 50;
        return;
    }

    if (distance > 350.0f) {
        this->shootDistance = 350;
        return;
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

void Player::setPoints(int points) {
    this->points = points;
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
        case 0: upgrateSpeed(); cout << "up velocidad" << endl; break;
        case 1: upgrateRadio(); cout << "up radio" << endl; break;
        case 2: upgrateCooldown(); cout << "up cooldown" << endl; break;
        case 3: upgrateShootSpeed(); cout << "up shoot speed" << endl; break;
        case 4: upgrateShootRadio(); cout << "up shoot radio" << endl; break;
        case 5: upgrateShootDistance(); cout << "up shoot distance" << endl; break;
    }
}

// downgrate del jugador
void Player::downgrate(void) {
    int num = rand() % 6; // generar numero aleatorio para elegir que empeorar

    // todos los casos posibles
    switch (num) {
        case 0: downgrateSpeed(); cout << "down Velocidad" << endl; break;
        case 1: downgrateRadio(); cout << "down Radio" << endl;break;
        case 2: downgrateCooldown();cout << "down Cooldown" << endl; break;
        case 3: downgrateShootSpeed(); cout << "down Velocidad disparo" << endl;break;
        case 4: downgrateShootRadio(); cout << "down radio disparo" << endl;break;
        case 5: downgrateShootDistance(); cout << "down distance disparo" << endl;break;
    }
}
