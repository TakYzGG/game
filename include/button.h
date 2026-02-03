// -- Clase boton para hacer menus --

#ifndef BUTTONS_H
#define BUTTONS_H

#include <raylib.h>

class Button {
    private:
        int x;
        int y;
        int width;
        int height;
        const char *text;

    public:
        // -- Constructor --
        Button(int x, int y, int width, int height, const char *text);

        // -- Getters --
        int getPosX(void);
        int getPosY(void);
        int getWidth(void);
        int getHeight(void);
        const char *getText(void);

        // -- Setters --
        void setPosX(int x);
        void setPosY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setText(const char *text);

        // -- Methods --
        int centerPosX(void);
        int centerPosY(void);
        void drawRectangle(Color color);
        void drawText(Color color);
};

#endif
