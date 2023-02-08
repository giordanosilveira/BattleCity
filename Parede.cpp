#include "Parede.hpp"
#include "enums/EnumDirecao.hpp"

Parede::Parede(){}

Parede::Parede(
    const unsigned int x, 
    const unsigned int y, 
    unsigned short int tamanhoSprite, 
    const unsigned short imortal,
    const unsigned short estado, 
    const unsigned short velocidade, 
    const unsigned short direcao, 
    unsigned short int vida):Objeto{x,y,tamanhoSprite,imortal,estado, velocidade, direcao}{
    this->vida = (unsigned char)vida; 
}

Parede::~Parede(){}

const unsigned short int Parede::getVida() const {
    return this->vida;
}
void Parede::setVida (const unsigned short int vida) {
    this->vida = (unsigned char)vida;
}
