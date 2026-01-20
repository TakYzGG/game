// -- Clase del disparo --

#ifndef SHOOT_H
#define SHOOT_H

// -- Librerias --
#include <vector>
#include "generic_entity.h"
using namespace std;

// -- Shoot Class --
class Shoot: public GenericEntity {
    private:
        // -- Atributes --
        float distance; // distancia maxima a reccorer
        float travel = 0; // distancia recorrida
        char direction; // direccion del disapro
        int status = 0; // estado del disparo (1 muerto, 0 vivo)

    public:
        // -- Constructor --
        Shoot(float x, float y, float speed, int radio, float distance, char direction);

        // -- Getters --
        float getDistance(void);
        float getTravel(void);
        char getDirection(void);
        int getStatus(void);

        // -- Setters --
        void setDistance(float distance);
        void setTravel(float travel);
        void setDirection(char direction);
        void setStatus(int status);

        // -- Methods --
        void move(void);
        void isDead(void);
        void remove(void);
};

// Variables
extern vector<Shoot*> shoots;

// -- Funciones
// -- Recorrer el vector de Shoots --
void travelShoots(void);

#endif
