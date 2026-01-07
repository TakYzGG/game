# Mi primer juego hecho con c++ y raylib

## Dependencias
- compilador de c++
- raylib

## Instalacion
- compilar todos los archivos .cpp
- comando (linux): 'g++ *.cpp'

## Variables globales
- vector<Shoot*> shoots: guarda los disparos generados por el jugador

## Clases
### GenericEntity
Atributos:
- float x: guarda la posicion en el eje x
- float y: guarda la posicion en el eje y
- float speed: guarda la velocidad
- int radio: guarda el radio

Constructor:
- float x
- float y
- float speed
- int radio

Getters:
- getPosX(): retorna un float con la posicion en el eje x
- getPosY(): retorna un float con la posicion en el eje y
- getSpeed(): retorna un float con la velocidad
- getRadio(): retorna un int con el radio

Setters:
- setPosX(float x): pide un float y lo guarda en el atributo x
- setPosY(float y): pide un float y lo guarda en el atributo y
- setSpeed(float speed): pide un float y lo guarda en el atributo speed
- setRadio(int radio): pide un int y lo guarda en el atributo radio

### Shoot -> GenericEntity
Atributos:
- float distance: guarda la distancia maxima que puede recorrer
- float travel: guarda la distancia recorrida
- char direction: guarda la direccion
    - 'A': arriba
    - 'B': izquierda
    - 'C': abajo
    - 'D': derecha
    - 'E': arriba izquierda
    - 'F': arriba derecha
    - 'G': abajo izquierda
    - 'H': abajo derecha

Constructor:
- float x;
- float y;
- float speed;
- int radio;
- float distance;
- char direction;

Getters:
- getDistance(): retorna un float con la distancia maxima que puede recorrer
- getTravel(): retorna un float con la distancia recorrida
- getDirection(): retorna un char con la direccion

Setters:
- setDistance(float distance): pide un float y lo guarda en el atributo distance
- setTravel(float travel): pide un float y lo guarda en el atributo travel
- setDirection(char direction): pide un char y lo guarda en el atributo direction

Methods:
- move(): mueve el disparo dependiendo su direccion
- isDead(): comprueba si la distancia recorrida (travel) es igual o mayor a la
distancia maxima(distance), retorna 1 si la condicion se cumple
- remove(): si isDead() retorna 1 (verdadero) remueve el disparo del vector de disparos

### Player -> GenericEntity
Atributos:
- float cooldown: tiempo de espera entre cada disparo
- float shootSpeed: velocidad de los disparos
- int shootRadio: radio de los disparos
- float shootDistance: distancia maxima que pueden recorrer los disparos

Getters:
- float getCooldown(): retorna un float con el cooldown entre disparos
- float getShootSpeed(): retorna un float con la velocidad de los disparos
- float getShootRadio(): retorna un int con el radio de los disparos
- float getShootDistance(): retorna un float con la distancia maxima que pueden
recorrer los disparos

Setters:
- setCooldown(float cooldown): pide un float y lo guarda en el atributo cooldown
- setShootSpeed(float speed): pide un float y lo guarda en el atributo shootSpeed
- setShootRadio(int radio): pide un int y lo guarda en el atributo shootRadio
- setShootDistance(float distance): pide un float y lo guarda en el atributo shootDistance

Methods:
- move(): mueve al jugador dependiendo que teclas esten precionadas
- isFiring(): comprueba si el jugador esta disparando o no
- shoot(): genera una instancia de Shoot y lo guarda en el vector shoots
