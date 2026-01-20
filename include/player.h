// -- Clase del jugador --

#ifndef PLAYER_H
#define PLAYER_H

// -- Libreiras --
#include "generic_entity.h"

// -- Player Class --
class Player: public GenericEntity {
    private:
        // -- Atributes --
        float cooldown; // tiempo entre disparo y disparo
        float shootSpeed; // velocidad del disparo
        int shootRadio; // radio del disparo
        float shootDistance; // distancia maxima del disparo
        float timer;
        int firing;
        int wasFiring;

    public:
        // -- Constructor --
        Player();

        // -- Getters --
        float getCooldown(void);
        float getShootSpeed(void);
        int getShootRadio(void);
        float getShootDistance(void);
        float getTimer(void);
        int getFiring(void);
        int getWasFiring(void);
        
        // -- Setters --
        void setPosition(void);
        void setCooldown(float cooldown);
        void setShootSpeed(float speed);
        void setShootRadio(int radio);
        void setShootDistance(float distance);
        void setTimer(float timer);
        void setFiring(int firing);
        void setWasFiring(int wasFiring);

        // -- Methods --
        void move(void);
        int isFiring(void);
        void shoot(void);
};

extern Player player;

#endif
