// -- Classes --

#ifndef CLASSES_H
#define CLASSES_H

// -- Generic Class --
class GenericEntity {
    private:
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

#endif
