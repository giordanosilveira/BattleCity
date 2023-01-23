#include "Coordenada.hpp"

Coordenada::Coordenada()      
{
}

Coordenada::Coordenada(const unsigned short int x, const unsigned short int y):x{x}, y{y}      
{
}

Coordenada::~Coordenada()
{
}

const unsigned short int Coordenada::getX() const {
    return this->x;
}
void Coordenada::setX(const unsigned short int x) {

    this->x = x;
}

const unsigned short int Coordenada::getY() const {
    return this->y;
}

void Coordenada::setY(const unsigned short int y){
    this->y = y;
}