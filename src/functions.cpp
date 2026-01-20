// -- Funciones utiles --

// -- Librerias --
#include <raylib.h>

#include "functions.h"

// -- Formula para calcular la velocidad de las cosas --
float calcSpeed(float speed) {
    return GetFrameTime() * 6.0f * (speed * 10.0f);
}
