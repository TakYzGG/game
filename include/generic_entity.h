// -- Clase Gener

#ifndef GENERIC_ENTITY_H
#define GENERIC_ENTITY_H

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

#endif
