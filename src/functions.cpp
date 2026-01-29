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
