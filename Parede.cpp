#include "Parede.hpp"

Parede::Parede(){}

Parede::Parede(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, unsigned short int vida):Objeto{x,y,tamanhoSprite}{
    this->vida = (unsigned char)vida; 
}

Parede::~Parede(){}

const unsigned short int Parede::getVida() const {
    return this->vida;
}
void Parede::setVida (const unsigned short int vida) {
    this->vida = (unsigned char)vida;
}
