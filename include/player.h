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
        int points;
        int isDead;

        // -- Private Methods --
        void upgrateSpeed(void);
        void upgrateRadio(void);
        void upgrateCooldown(void);
        void upgrateShootSpeed(void);
        void upgrateShootRadio(void);
        void upgrateShootDistance(void);

        void downgrateSpeed(void);
        void downgrateRadio(void);
        void downgrateCooldown(void);
        void downgrateShootSpeed(void);
        void downgrateShootRadio(void);
        void downgrateShootDistance(void);

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
        int getPoints(void);
        int getIsDead(void);
        
        // -- Setters --
        void setPosition(void);
        void setCooldown(float cooldown);
        void setShootSpeed(float speed);
        void setShootRadio(int radio);
        void setShootDistance(float distance);
        void setTimer(float timer);
        void setFiring(int firing);
        void setWasFiring(int wasFiring);
        void setPoints(int points);
        void setIsDead(int state);

        // -- Methods --
        void move(void);
        int isFiring(void);
        void shoot(void);
        void upgrate(void);
        void downgrate(void);
        void reset(void);
};

extern Player player;

#endif
