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
        int travel = 0; // distancia recorrida
        char direction;

    public:
        // -- Constructor --
        Shoot(int x, int y, int speed, int radio, int distance, char direction);

        // -- Getters --
        int getDistance(void);
        int getTravel(void);
        char getDirection(void);

        // -- Setters --
        void setDistance(int distance);
        void setTravel(int travel);
        void setDirection(char direction);

        // -- Methods --
        void move(void);
        int isDead(void);
        void remove(void);
};

// -- Player Class --
class Player: public GenericEntity {
    private:
        // -- Atributes --
        float cooldown = 0.5; // tiempo entre disparo y disparo
        int shootSpeed = 1;
        int shootRadio = 5;
        int shootDistance = 100;

    public:
        // -- Constructor --
        Player();

        // -- Getters --
        float getCooldown(void);
        int getShootSpeed(void);
        int getShootRadio(void);
        int getShootDistance(void);
        
        // -- Setters --
        void setCooldown(float cooldown);
        void setShootSpeed(int speed);
        void setShootRadio(int radio);
        void setShootDistance(int distance);

        // -- Methods --
        void move(void);
        int isFiring(void);
        void shoot(void);
};

// Variables
extern vector<Shoot*> shoots;

// -- Funciones
// -- Recorrer el vector de Shoots --
void travelShoots(void);

#endif
