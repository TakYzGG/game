// -- Interfaz del juego --

#ifndef INTERFACE_H
#define INTERFACE_H

// -- Clase de la interfaz --
class Interface {
    private:
        // -- Atributes --
        int screenWidth;
        int screenHeight;
        int FPS;

    public:
        // -- Methods --
        void drawHudDebbug(void);
        void drawHud(void);
        void drawPlayer(void);
        void drawEnemys(void);
        void drawShoots(void);
};

#endif
