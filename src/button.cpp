// -- Clase boton para hacer menus --

// -- Librerias --
#include <raylib.h>

#include "button.h"

// -- Constructor --
Button::Button(int x, int y, int width, int height, const char *text) {
    setPosX(x);
    setPosY(y);
    setWidth(width);
    setHeight(height);
    setText(text);
}

// -- Getters --
int Button::getPosX(void) {return x;}
int Button::getPosY(void) {return y;}
int Button::getWidth(void) {return width;}
int Button::getHeight(void) {return height;}
const char *Button::getText(void) {return text;}

// -- Setters --
void Button::setPosX(int x) {
    this->x = x;
}

void Button::setPosY(int y) {
    this->y = y;
}

void Button::setWidth(int width) {
    this->width = width;
}

void Button::setHeight(int height) {
    this->height = height;
}

void Button::setText(const char *text) {
    this->text = text;
}

// -- Methods --
int Button::centerPosX(void) {
    return x - (width / 2);
}

int Button::centerPosY(void) {
    return y - (height / 2);
}

void Button::drawRectangle(Color color) {
    DrawRectangle(centerPosX(), centerPosY(), width, height, color);
}

void Button::drawText(Color color) {
    DrawText(TextFormat("%s", text), centerPosX(), centerPosY(), 20, color);
}
