// -- Funciones utiles --

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// -- Formula para calcular la velocidad de las cosas --
float calcSpeed(float speed);

// -- Formula para centarr el texto usando el ancho de la ventana --
int calcCenterText(const char *str, int font_size);

// -- Comprobar si un circulo esta dentro de otro
int IsCircleInOtherCircle(float ax, float ay, float ar, float bx, float by, float br);

#endif
