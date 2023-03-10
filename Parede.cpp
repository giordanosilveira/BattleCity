#include "Parede.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"

Parede::Parede(){}

Parede::Parede(
    const unsigned int x, 
    const unsigned int y, 
    const unsigned short int tamanhoSprite, 
    const unsigned short int imortal,
    EnumEstadoObjeto estado, 
    const unsigned short int velocidade,
    const unsigned short int vida,
    EnumDirecao direcao, 
    const allegro::Sprite *sprite):Objeto{x,y,tamanhoSprite,imortal,estado, vida, velocidade, direcao}{
    this->vida = (unsigned char)vida;
    this->sprite = sprite;
}

Parede::~Parede(){}

