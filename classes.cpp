// -- Clases --

// -- Librerias --
#include "classes.h"
#include <iostream>
#include <vector>
using namespace std;

// -- Variables --
vector<Shoot> shoots;

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

// -- Player Class --
Player::Player(int x, int y, int speed, int radio) 
    :GenericEntity(x, y, speed, radio)
    {
    }

// -- Methods --
void Player::shoot(void) {
    shoots.emplace_back(10, 10, 1, 5, 100, 0);
}


// -- Recorer el vector de Shoots --
void travelShoots(void) {
    for (Shoot& s: shoots) {
        cout << s.getPosX() << endl;
    }
}
