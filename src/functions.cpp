// -- Funciones utiles --

#include "functions.h"
#include <raylib.h>

float calcSpeed(float speed) {
    return GetFrameTime() * 6.0f * (speed * 10.0f);
}
