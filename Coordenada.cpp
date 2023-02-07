#include "Coordenada.hpp"

Coordenada::Coordenada()      
{
}

Coordenada::Coordenada(const unsigned int x, const unsigned int y):x{x}, y{y}      
{
}

Coordenada::~Coordenada()
{
}

const unsigned int Coordenada::getX() const {
    return this->x;
}
void Coordenada::setX(const unsigned int x) {

    this->x = x;
}

const unsigned int Coordenada::getY() const {
    return this->y;
}

void Coordenada::setY(const unsigned int y){
    this->y = y;
}