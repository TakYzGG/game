// -- Clases --

// -- Librerias --
#include "classes.h"
#include <bits/stdc++.h>
#include <raylib.h>
#include <vector>
using namespace std;

// -- Variables --
vector<Shoot*> shoots; // vector con los disparos generados por el jugador

// -- Generic Class --
// -- Constructor --
GenericEntity::GenericEntity(int x, int y, int speed, int radio) {
    setPosX(x);
    setPosY(y);
    setSpeed(speed);
    setRadio(radio);
}

// -- Getters --
int GenericEntity::getPosX(void) {return x;}
int GenericEntity::getPosY(void) {return y;}
int GenericEntity::getSpeed(void) {return speed;}
int GenericEntity::getRadio(void) {return radio;}

// -- Setters --
void GenericEntity::setPosX(int x) {
    this->x = x;
}

void GenericEntity::setPosY(int y) {
    this->y = y;
}

void GenericEntity::setSpeed(int speed) {
    this->speed = speed;
}

void GenericEntity::setRadio(int radio) {
    this->radio = radio;
}

// -- Shoot Class --
// -- Constructor --
Shoot::Shoot(int x, int y, int speed, int radio, int distance, char direction)
    :GenericEntity(x, y, speed, radio)
    {
        setDistance(distance);
        setTravel(travel);
        this->direction = direction;
    }

// -- Getters --
int Shoot::getDistance(void) {return distance;}
int Shoot::getTravel(void) {return travel;}
char Shoot::getDirection(void) {return direction;}

// -- Setters --
// obtener la distancia maxima que puede recorrer el disparo
void Shoot::setDistance(int distance) {
    this->distance = distance;
}

// obtener la distancia recorrida por el disparo
void Shoot::setTravel(int travel) {
    this->travel = travel;
}

// -- Methods --
// movimiento de los disparos
void Shoot::move(void) {
    switch (getDirection()) {
        // arriba
        case 'A': setPosY(getPosY() - getSpeed());
                  break;

        // izquierda
        case 'B': setPosX(getPosX() - getSpeed());
                  break;

        // abajo
        case 'C': setPosY(getPosY() + getSpeed());
                  break;

        // derecha
        case 'D': setPosX(getPosX() + getSpeed());
                  break;

        // arriba izquierda
        case 'E':
                  setPosX(getPosX() - getSpeed());
                  setPosY(getPosY() - getSpeed());
                  break;

        // arriba derecha
        case 'F': setPosX(getPosX() + getSpeed());
                  setPosY(getPosY() - getSpeed());
                  break;

        // abajo izquierda
        case 'G': setPosX(getPosX() - getSpeed());
                  setPosY(getPosY() + getSpeed());
                  break;

        // abajo derecha
        case 'H': setPosX(getPosX() + getSpeed());
                  setPosY(getPosY() + getSpeed());
                  break;
    }

    // sumar distancia recorrida
    this->travel += getSpeed();
}

// comprobar si el disparo ya recorrio la distancia maxima
int Shoot::isDead(void) {
    if (getTravel() == getDistance()) {
        return 1;
    }

    return 0;
}

// eliminar un disparo del vector
void Shoot::remove(void) {
    auto it = find(shoots.begin(), shoots.end(), this);
    if (it != shoots.end() && (*it)->isDead()) {
        delete *it;
        shoots.erase(it);
    }
}

// -- Player Class --
// -- Constructor --
Player::Player(int x, int y, int speed, int radio) 
    :GenericEntity(x, y, speed, radio)
    {
    }

// -- Methods --
// movimiento del jugador
void Player::move(void) {
    // arriba
    if (IsKeyDown(KEY_W) && (getPosY() > 0)) {
        setPosY(getPosY() - getSpeed());
    }

    // izquierda
    if (IsKeyDown(KEY_A) && (getPosX() > 0)) {
        setPosX(getPosX() - getSpeed());
    }

    // abajo
    if (IsKeyDown(KEY_S) && (getPosY() < GetScreenHeight())) {
        setPosY(getPosY() + getSpeed());
    }

    // derecha
    if (IsKeyDown(KEY_D) && (getPosX() < GetScreenWidth())) {
        setPosX(getPosX() + getSpeed());
    }
}

// hacer que el jugador pueda disparar
void Player::shoot(void) {
    // arriba izquierda
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'E'));
        return;
    }

    // arriba derecha
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'F'));
        return;
    }

    // abajo izquierda
    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'G'));
        return;
    }

    // abajo derecha
    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'H'));
        return;
    }

    // arriba
    if (IsKeyDown(KEY_UP)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'A'));
    }

    // izquierda
    if (IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'B'));
    }

    // abajo
    if (IsKeyDown(KEY_DOWN)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'C'));
    }

    // derecha
    if (IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'D'));
    }
}


// -- Funciones --
// -- Recorer el vector de Shoots --
void travelShoots(void) {
    for (int i = 0; i < shoots.size(); i++) {
        shoots[i]->move();
        shoots[i]->remove();
    }
}
