// -- Clases --

// -- Librerias --
#include "classes.h"
#include <bits/stdc++.h>
#include <raylib.h>
#include <vector>
using namespace std;

// -- Variables --
vector<Shoot*> shoots;

// -- Generic Class --
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
void Shoot::setDistance(int distance) {
    this->distance = distance;
}

void Shoot::setTravel(int travel) {
    this->travel = travel;
}

// -- Methods --
void Shoot::move(void) {
    switch (getDirection()) {
        case 'A': setPosY(getPosY() - getSpeed()); break; // arriba
        case 'B': setPosX(getPosX() - getSpeed()); break; // izquierda
        case 'C': setPosY(getPosY() + getSpeed()); break; // abajo
        case 'D': setPosX(getPosX() + getSpeed()); break; // derecha

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
    this->travel += getSpeed();
}

int Shoot::isDead(void) {
    if (getTravel() == getDistance()) {
        return 1;
    }

    return 0;
}

void Shoot::remove(void) {
    auto it = find(shoots.begin(), shoots.end(), this);
    if (it != shoots.end() && (*it)->isDead()) {
        delete *it;
        shoots.erase(it);
    }
}

// -- Player Class --
Player::Player(int x, int y, int speed, int radio) 
    :GenericEntity(x, y, speed, radio)
    {
    }

// -- Methods --
void Player::move(void) {
    if (IsKeyDown(KEY_W) && (getPosY() > 0)) {
        setPosY(getPosY() - getSpeed());
    }

    if (IsKeyDown(KEY_A) && (getPosX() > 0)) {
        setPosX(getPosX() - getSpeed());
    }

    if (IsKeyDown(KEY_S) && (getPosY() < GetScreenHeight())) {
        setPosY(getPosY() + getSpeed());
    }

    if (IsKeyDown(KEY_D) && (getPosX() < GetScreenWidth())) {
        setPosX(getPosX() + getSpeed());
    }
}

void Player::shoot(void) {
    // Direcciones diagonales
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'E'));
        return;
    }

    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'F'));
        return;
    }

    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'G'));
        return;
    }

    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'H'));
        return;
    }

    // Direcciones simples
    if (IsKeyDown(KEY_UP)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'A'));
    }

    if (IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'B'));
    }

    if (IsKeyDown(KEY_DOWN)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), 1, 5, 100, 'C'));
    }

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
