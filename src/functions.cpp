// -- Funciones utiles --

// -- Librerias --
#include <raylib.h>

#include "functions.h"

// -- Formula para calcular la velocidad de las cosas --
float calcSpeed(float speed) {
    return GetFrameTime() * 6.0f * (speed * 10.0f);
}

// -- Formula para centrar el texto usando el ancho de la ventana --
int calcCenterText(const char *str, int font_size) {
    return (GetScreenWidth() - MeasureText(str, font_size)) / 2;
}

// -- Comprobar si un circulo esta dentro de otro
int IsCircleInOtherCircle(float ax, float ay, float ar, float bx, float by, float br) {
    float dx = ax - bx;
    float dy = ay - by;

    float distSq = dx * dx + dy * dy;
    float radiusSum = (ar / 2) + (br / 2);

    if (distSq <= radiusSum * radiusSum) return 1;

    return 0;
}
