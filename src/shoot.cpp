// -- Clase del disparo --

// -- Librerias --
#include <bits/stdc++.h>
#include <vector>

#include "generic_entity.h"
#include "shoot.h"
#include "min_max_atributes.h"
#include "functions.h"
using namespace std;

// -- Variables --
vector<Shoot*> shoots; // vector con los disparos generados por el jugador

// -- Shoot Class --
// -- Constructor --
Shoot::Shoot(float x, float y, float speed, int radio, float distance, char direction)
    :GenericEntity(x, y, speed, radio)
    {
        setDistance(distance);
        setTravel(travel);
        setDirection(direction);
    }

// -- Getters --
float Shoot::getDistance(void) {return distance;}
float Shoot::getTravel(void) {return travel;}
char Shoot::getDirection(void) {return direction;}
int Shoot::getStatus(void) {return status;}

// -- Setters --
// modificar la distancia maxima que puede recorrer el disparo
void Shoot::setDistance(float distance) {
    if ((distance >= MINDISTANCE) && (distance <= MAXDISTANCE)) {
        this->distance = distance;
        return;
    }

    if (distance < MINDISTANCE) {
        this->distance = MINDISTANCE;
        return;
    }

    if (distance > MAXDISTANCE) {
        this->distance = MAXDISTANCE;
        return;
    }
}

// modificar la distancia recorrida por el disparo
void Shoot::setTravel(float travel) {
    if (travel >= 0) {
        this->travel = travel;
    }
}

// direcciones validas para los disparos
void Shoot::setDirection(char direction) {
    switch (direction) {
        case 'A': this->direction = direction; break;
        case 'B': this->direction = direction; break;
        case 'C': this->direction = direction; break;
        case 'D': this->direction = direction; break;
        case 'E': this->direction = direction; break;
        case 'F': this->direction = direction; break;
        case 'G': this->direction = direction; break;
        case 'H': this->direction = direction; break;
    }
}

// cambiar el estado del disparo
void Shoot::setStatus(int status) {
    if ((status == 1) || (status == 0)) {
        this->status = status;
    }
}

// -- Methods --
// movimiento de los disparos
void Shoot::move(void) {
    float speed = calcSpeed(getSpeed());

    switch (getDirection()) {
        // arriba
        case 'A': setPosY(getPosY() - speed);
                  break;

        // izquierda
        case 'B': setPosX(getPosX() - speed);
                  break;

        // abajo
        case 'C': setPosY(getPosY() + speed);
                  break;

        // derecha
        case 'D': setPosX(getPosX() + speed);
                  break;

        // arriba izquierda
        case 'E':
                  setPosX(getPosX() - speed);
                  setPosY(getPosY() - speed);
                  break;

        // arriba derecha
        case 'F': setPosX(getPosX() + speed);
                  setPosY(getPosY() - speed);
                  break;

        // abajo izquierda
        case 'G': setPosX(getPosX() - speed);
                  setPosY(getPosY() + speed);
                  break;

        // abajo derecha
        case 'H': setPosX(getPosX() + speed);
                  setPosY(getPosY() + speed);
                  break;
    }

    // sumar distancia recorrida
    this->travel += speed;
}

// comprobar si el disparo ya recorrio la distancia maxima
void Shoot::isDead(void) {
    if (getTravel() >= getDistance()) {
        setStatus(1);
    }
}

// eliminar un disparo del vector
void Shoot::remove(void) {
    auto it = find(shoots.begin(), shoots.end(), this);
    if (it != shoots.end() && (*it)->getStatus()) {
        delete *it;
        shoots.erase(it);
    }
}

// -- Funciones --
// -- Recorer el vector de Shoots --
void travelShoots(void) {
    for (int i = 0; i < shoots.size(); i++) {
        shoots[i]->move();
        shoots[i]->isDead();
        shoots[i]->remove();
    }
}
