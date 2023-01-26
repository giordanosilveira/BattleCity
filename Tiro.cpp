#include "Tiro.hpp"

Tiro::Tiro(){}

Tiro::Tiro(const unsigned int x, const unsigned int y, const unsigned short int tamanhoSprite, const unsigned short imortal, const unsigned short estado, const unsigned short int velocidade, const unsigned short int direcao):
    Objeto{x,y,tamanhoSprite, imortal, estado}{
    this->velocidade = (unsigned char) velocidade;
    this->direcao = (unsigned char) direcao;
}

Tiro::~Tiro(){}

const unsigned short int Tiro::getVelocidade() const {
    return this->velocidade;
}
void Tiro::setVelocidade(const unsigned short int velocidade) {
    this->velocidade = (unsigned char)velocidade;
}

const unsigned short int Tiro::getDirecao() const {
    return this->direcao;
}
void Tiro::setDirecao(const unsigned short int direcao){
    this->direcao = (unsigned char)direcao;
}
