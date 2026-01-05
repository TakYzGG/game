// -- Classes --

#ifndef CLASSES_H
#define CLASSES_H

//#include <memory>
#include <vector>
using namespace std;

// -- Generic Class --
class GenericEntity {
    private:
        // -- Atributes --
        int x;
        int y;
        int speed;
        int radio;

    public:
        // -- Constructor --
        GenericEntity(int x, int y, int speed, int radio);

        // -- Getters --
        int getPosX(void);
        int getPosY(void);
        int getSpeed(void);
        int getRadio(void);

        // -- Setters --
        void setPosX(int x);
        void setPosY(int y);
        void setSpeed(int speed);
        void setRadio(int radio);
};


// -- Shoot Class --
class Shoot: public GenericEntity {
    private:
        // -- Atributes --
        int distance; // distancia maxima a reccorer
        int travel; // distancia recorrida

    public:
        // -- Constructor --
        Shoot(int x, int y, int speed, int radio, int distance, int travel);

        // -- Getters --
        int getDistance(void);
        int getTravel(void);

        // -- Setters --
        void setDistance(int distance);
        void setTravel(int travel);

        // -- Methods --
        void move(void);
        int isDead(void);
        void remove(void);
};

// -- Player Class --
class Player: public GenericEntity {
    public:
        // -- Constructor --
        Player(int x, int y, int speed, int radio);

        // -- Methods --
        void move(void);
        void shoot(void);
};

// Variables
extern vector<Shoot*> shoots;

// -- Funciones
// -- Recorrer el vector de Shoots --
void travelShoots(void);

#endif
