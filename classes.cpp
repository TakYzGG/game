// -- Clases --

// -- Librerias --
#include "classes.h"
#include <bits/stdc++.h>
#include <raylib.h>
#include <vector>
using namespace std;

// -- Variables --
vector<Shoot*> shoots; // vector con los disparos generados por el jugador
vector<Enemy*> enemys;

// -- Generic Class --
// -- Constructor --
GenericEntity::GenericEntity(float x, float y, float speed, int radio) {
    setPosX(x);
    setPosY(y);
    setSpeed(speed);
    setRadio(radio);
}

// -- Getters --
float GenericEntity::getPosX(void) {return x;}
float GenericEntity::getPosY(void) {return y;}
float GenericEntity::getSpeed(void) {return speed;}
int GenericEntity::getRadio(void) {return radio;}

// -- Setters --
// modificar posicion x
void GenericEntity::setPosX(float x) {
    this->x = x;
}

// modificar posicion y
void GenericEntity::setPosY(float y) {
    this->y = y;
}

// modificar velocidad
void GenericEntity::setSpeed(float speed) {
    this->speed = speed;
}

// modificar radio
void GenericEntity::setRadio(int radio) {
    this->radio = radio;
}

// -- Shoot Class --
// -- Constructor --
Shoot::Shoot(float x, float y, float speed, int radio, float distance, char direction)
    :GenericEntity(x, y, speed, radio)
    {
        setDistance(distance);
        setTravel(travel);
        setDirection(direction);
    }

// -- Getters --
float Shoot::getDistance(void) {return distance;}
float Shoot::getTravel(void) {return travel;}
char Shoot::getDirection(void) {return direction;}

// -- Setters --
// modificar la distancia maxima que puede recorrer el disparo
void Shoot::setDistance(float distance) {
    this->distance = distance;
}

// modificar la distancia recorrida por el disparo
void Shoot::setTravel(float travel) {
    this->travel = travel;
}

// direcciones validas para los disparos
void Shoot::setDirection(char direction) {
    switch (direction) {
        case 'A': this->direction = direction; break;
        case 'B': this->direction = direction; break;
        case 'C': this->direction = direction; break;
        case 'D': this->direction = direction; break;
        case 'E': this->direction = direction; break;
        case 'F': this->direction = direction; break;
        case 'G': this->direction = direction; break;
        case 'H': this->direction = direction; break;
    }
}

// -- Methods --
// movimiento de los disparos
void Shoot::move(void) {
    float speed = GetFrameTime() * 6.0f * (getSpeed() * 10.0f);

    switch (getDirection()) {
        // arriba
        case 'A': setPosY(getPosY() - speed);
                  break;

        // izquierda
        case 'B': setPosX(getPosX() - speed);
                  break;

        // abajo
        case 'C': setPosY(getPosY() + speed);
                  break;

        // derecha
        case 'D': setPosX(getPosX() + speed);
                  break;

        // arriba izquierda
        case 'E':
                  setPosX(getPosX() - speed);
                  setPosY(getPosY() - speed);
                  break;

        // arriba derecha
        case 'F': setPosX(getPosX() + speed);
                  setPosY(getPosY() - speed);
                  break;

        // abajo izquierda
        case 'G': setPosX(getPosX() - speed);
                  setPosY(getPosY() + speed);
                  break;

        // abajo derecha
        case 'H': setPosX(getPosX() + speed);
                  setPosY(getPosY() + speed);
                  break;
    }

    // sumar distancia recorrida
    this->travel += speed;
}

// comprobar si el disparo ya recorrio la distancia maxima
int Shoot::isDead(void) {
    if (getTravel() >= getDistance()) {
        return 1;
    }

    return 0;
}

// eliminar un disparo del vector
void Shoot::remove(void) {
    auto it = find(shoots.begin(), shoots.end(), this);
    if (it != shoots.end() && (*it)->isDead()) {
        delete *it;
        shoots.erase(it);
    }
}

// -- Player Class --
// -- Constructor --
Player::Player()
    :GenericEntity((GetScreenWidth() / 2), (GetScreenHeight() / 2), 1, 8)
    {
    }

// -- Getters --
float Player::getCooldown(void) {return cooldown;}
int Player::getShootSpeed(void) {return shootSpeed;}
int Player::getShootRadio(void) {return shootRadio;}
int Player::getShootDistance(void) {return shootDistance;}

// -- Setters --
// modificar el cooldown entre disparos
void Player::setCooldown(float cooldown) {
    if (cooldown >= 0.1) {
        this->cooldown = cooldown;
    }
}

// modificar la velocidad de los disparos
void Player::setShootSpeed(int speed) {
    if (speed > 0) {
        this->shootSpeed = speed;
    }
}

// modificar el radio de los disparos
void Player::setShootRadio(int radio) {
    if (radio >= 5) {
        this->shootRadio = radio;
    }
}

// modificar la distancia maxima de los disparos
void Player::setShootDistance(int distance) {
    if (distance >= 50) {
        this->shootDistance = distance;
    }
}

// -- Methods --
// movimiento del jugador
void Player::move(void) {
    float speed = GetFrameTime() * 6.0f * (getSpeed() * 10.0f);
    // arriba
    if (IsKeyDown(KEY_W) && (getPosY() > 0)) {
        setPosY(getPosY() - speed);
    }

    // izquierda
    if (IsKeyDown(KEY_A) && (getPosX() > 0)) {
        setPosX(getPosX() - speed);
    }

    // abajo
    if (IsKeyDown(KEY_S) && (getPosY() < GetScreenHeight())) {
        setPosY(getPosY() + speed);
    }

    // derecha
    if (IsKeyDown(KEY_D) && (getPosX() < GetScreenWidth())) {
        setPosX(getPosX() + speed);
    }
}

// comprobar si el jugador esta dispando
int Player::isFiring(void) {
    if (IsKeyDown(KEY_UP)) return 1;
    if (IsKeyDown(KEY_LEFT)) return 1;
    if (IsKeyDown(KEY_DOWN)) return 1;
    if (IsKeyDown(KEY_RIGHT)) return 1;
    return 0;
}

// hacer que el jugador pueda disparar
void Player::shoot(void) {
    // arriba izquierda
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'E'));
        return;
    }

    // arriba derecha
    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'F'));
        return;
    }

    // abajo izquierda
    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'G'));
        return;
    }

    // abajo derecha
    if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'H'));
        return;
    }

    // arriba
    if (IsKeyDown(KEY_UP)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'A'));
        return;
    }

    // izquierda
    if (IsKeyDown(KEY_LEFT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'B'));
        return;
    }

    // abajo
    if (IsKeyDown(KEY_DOWN)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'C'));
        return;
    }

    // derecha
    if (IsKeyDown(KEY_RIGHT)) {
        shoots.push_back(new Shoot(getPosX(), getPosY(), getShootSpeed(),
                         getShootRadio(), getShootDistance(), 'D'));
        return;
    }
}

// -- Enemy Class --
// -- Constructor --
Enemy::Enemy(int x, int y)
    :GenericEntity(x, y, 1, 8)
    {
    }

// comprobar si el disparo ya recorrio la distancia maxima
int Enemy::isDead(void) {
  for (int i = 0; i < shoots.size(); i++)
    {
        // diferencia de posiciones
        float dx = getPosX() - shoots[i]->getPosX();
        float dy = getPosY() - shoots[i]->getPosY();

        float distSq = dx*dx + dy*dy;
        float radiusSum = getRadio() + shoots[i]->getRadio();

        // comprobar si el disparo esta dentro del radio del enemigo
        if (distSq <= radiusSum * radiusSum)
        {
            return 1;
        }
    }
    return 0;
}

// eliminar un disparo del vector
void Enemy::remove(void) {
    auto it = find(enemys.begin(), enemys.end(), this);
    if (it != enemys.end() && (*it)->isDead()) {
        delete *it;
        enemys.erase(it);
    }
}

// -- Funciones --
// -- Recorer el vector de Shoots --
void travelShoots(void) {
    for (int i = 0; i < shoots.size(); i++) {
        shoots[i]->move();
        shoots[i]->remove();
    }
}

// -- Eliminar a los enemigos del vector --
void removeEnemys(void) {
    for (int i = 0; i < enemys.size(); i++) {
        enemys[i]->remove();
    }
}
