// -- Clase para generar entidades genericas --

// -- Librerias --
#include <raylib.h>

#include "generic_entity.h"

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
    if ((x >= 0.0f) && (x <= GetScreenWidth())) {
        this->x = x;
    }
}

// modificar posicion y
void GenericEntity::setPosY(float y) {
    if ((y >= 0.0f) && (y <= GetScreenHeight())) {
        this->y = y;
    }
}

// modificar velocidad
void GenericEntity::setSpeed(float speed) {
    if ((speed >= 0.5f) && (speed <= 5.0f)) { // talvez 5 es mucho pero XD
        this->speed = speed;
    }
}

// modificar radio
void GenericEntity::setRadio(int radio) {
    if ((radio >= 5) && (radio <= 10)) {
        this->radio = radio;
        return;
    }

    if (radio > 10) {
        this->radio = 10;
        return;
    }
}
