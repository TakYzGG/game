// -- Clases --

// -- Librerias --
#include "classes.h"

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

// -- Player Class --
Player::Player(int x, int y, int speed, int radio) 
    :GenericEntity(x, y, speed, radio)
    {
    }

// -- Shoot Class --
Shoot::Shoot(int x, int y, int speed, int radio, int distance, int travel)
    :GenericEntity(x, y, speed, radio)
    {
        setDistance(distance);
        setTravel(travel);
    }

// -- Getters --
int Shoot::getDistance(void) {return distance;}
int Shoot::getTravel(void) {return travel;}

// -- Setters --
void Shoot::setDistance(int distance) {
    this->distance = distance;
}

void Shoot::setTravel(int travel) {
    this->travel = travel;
}
