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
        float x; // posicion x
        float y; // posicion y
        float speed; // velocidad
        int radio; // radio

    public:
        // -- Constructor --
        GenericEntity(float x, float y, float speed, int radio);

        // -- Getters --
        float getPosX(void);
        float getPosY(void);
        float getSpeed(void);
        int getRadio(void);

        // -- Setters --
        void setPosX(float x);
        void setPosY(float y);
        void setSpeed(float speed);
        void setRadio(int radio);
};

// -- Shoot Class --
class Shoot: public GenericEntity {
    private:
        // -- Atributes --
        float distance; // distancia maxima a reccorer
        float travel = 0; // distancia recorrida
        char direction; // direccion del disapro

    public:
        // -- Constructor --
        Shoot(float x, float y, float speed, int radio, float distance, char direction);

        // -- Getters --
        float getDistance(void);
        float getTravel(void);
        char getDirection(void);

        // -- Setters --
        void setDistance(float distance);
        void setTravel(float travel);
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
        float cooldown = 0.5f; // tiempo entre disparo y disparo
        int shootSpeed = 1.0f; // velocidad del disparo
        int shootRadio = 5; // radio del disparo
        int shootDistance = 100; // distancia maxima del disparo

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

// -- Enemy Class --
class Enemy: public GenericEntity {
    public:
        // -- Constructor --
        Enemy(int x, int y);

        // -- Methods --
        int isDead(void);
        void remove(void);
};

// Variables
extern vector<Shoot*> shoots;
extern vector<Enemy*> enemys;

// -- Funciones
// -- Recorrer el vector de Shoots --
void travelShoots(void);

// -- Eliminar a los enemigos --
void removeEnemys();

#endif
