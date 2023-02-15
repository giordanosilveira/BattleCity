#include "allegro/Sprite4D.hpp"
#include "Tiro.hpp"
#include "Parede.hpp"
#include "Tanque.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"

Tiro::Tiro(){}

Tiro::Tiro(
        const unsigned int x, 
        const unsigned int y, 
        const unsigned short int tamanhoSprite, 
        const unsigned short imortal, 
        EnumEstadoObjeto estado, 
        const unsigned short vida,
        const unsigned short velocidade, 
        EnumDirecao direcao,
        allegro::Sprite4D* const &sprites, const unsigned int direcao_tiro)
        : Objeto{x,y,tamanhoSprite, imortal, estado, vida, velocidade, direcao}{
    this->sprites = new allegro::Sprite4D{*sprites}; // shallow copy
    this->sprites->setSpritePrincipal(direcao_tiro);
}

void Tiro::mover(std::list<Objeto*> objetos){

    unsigned int x = this->superiorEsquerda->getX();
    unsigned int y = this->superiorEsquerda->getY();

    switch (this->direcao)
    {
        case EnumDirecao::DIREITA:
            x += this->velocidade;
            break;
        case EnumDirecao::ESQUERDA:
            x -= this->velocidade;
            break; 
        case EnumDirecao::CIMA:
            y -= this->velocidade;
            break; 
        case EnumDirecao::BAIXO:
            y += this->velocidade;
            break;
        case EnumDirecao::PARADO:
            break;
    }

    this->setSuperiorEsquerda(x, y);
    Objeto *obj = this->algumaColisao(objetos);
    if (obj != nullptr){
        obj->levarDano(1);
        this->morrer();
    }
    
}

Tiro::~Tiro() {}
    //delete this->sprites;
