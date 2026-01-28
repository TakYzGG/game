// -- Clase para generar entidades genericas --

// -- Librerias --
#include <raylib.h>

#include "generic_entity.h"
#include "min_max_atributes.h"

// -- Generic Class --
// -- Constructor --
GenericEntity::GenericEntity(float x, float y, float speed, int radio) {
    setPosX(x);
    setPosY(y);
    setSpeed(speed);
    setRadio(radio);
}

// -- Getters --
float GenericEntity::getPosX(void) {return x;}
float GenericEntity::getPosY(void) {return y;}
float GenericEntity::getSpeed(void) {return speed;}
int GenericEntity::getRadio(void) {return radio;}

// -- Setters --
// modificar posicion x
void GenericEntity::setPosX(float x) {
    if ((x >= MINPOSX) && (x <= MAXPOSX)) {
        this->x = x;
    }
}

// modificar posicion y
void GenericEntity::setPosY(float y) {
    if ((y >= MINPOSY) && (y <= MAXPOSY)) {
        this->y = y;
    }
}

// modificar velocidad
void GenericEntity::setSpeed(float speed) {
    if ((speed >= MINSPEED) && (speed <= MAXSPEED)) {
        this->speed = speed;
    }

    if (speed < MINSPEED) {
        this->speed = MINSPEED;
    }

    if (speed > MAXSPEED) {
        this->speed = MAXSPEED;
    }
}

// modificar radio
void GenericEntity::setRadio(int radio) {
    if ((radio >= MINRADIO) && (radio <= MAXRADIO)) {
        this->radio = radio;
        return;
    }

    if (radio < MINRADIO) {
        this->radio = MINRADIO;
        return;
    }

    if (radio > MAXRADIO) {
        this->radio = MAXRADIO;
        return;
    }
}
