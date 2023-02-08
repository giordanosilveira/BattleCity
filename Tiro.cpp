#include "Tiro.hpp"
#include "Tanque.hpp"

Tiro::Tiro(){}

Tiro::Tiro(
    const unsigned int x, 
    const unsigned int y, 
    const unsigned short int tamanhoSprite, 
    const unsigned short imortal, 
    EnumEstadoObjeto estado, 
    const unsigned short velocidade, 
    EnumDirecao direcao): Objeto{x,y,tamanhoSprite, imortal, estado, velocidade, direcao}{
}

Tiro::~Tiro(){}


void Tiro::setTanque (Tanque *tanque) {
    if (tanque == nullptr)
        throw std::runtime_error{"Ponteiro nulo: setTanque"};
        
    this->tanque = tanque;
    if (this->tanque != nullptr);
}