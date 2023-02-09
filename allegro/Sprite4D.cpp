#include "Sprite4D.hpp"
#include <iostream>

Allegro::Sprite4D::Sprite4D(){}

// Allegro::Sprite4D::Sprite4D(Sprite* spriteEsquerda, Sprite* spriteBaixo, Sprite* spriteDireita, Sprite* spriteCima):bitmapEsquerda{spriteEsquerda->getBitmap()}, bitmapBaixo{spriteBaixo->getBitmap()}, bitmapDireita{spriteDireita->getBitmap()}, bitmapCima{spriteCima->getBitmap()}{
// }

Allegro::Sprite4D::~Sprite4D(){}

void Allegro::Sprite4D::setSpritePrincipal(int direcao){
    // TODO meio ruim essas constantes mas n sei como fazer melhor
    std::cout << "Principal: ";
    switch (direcao){
        case ESQ:
            this->bitmap = this->bitmapEsquerda;
            std::cout << "esquerda" << std::endl;
            break;
        case BAI:
            this->bitmap = this->bitmapBaixo;
            std::cout << "baixo" << std::endl;
            break;
        case DIR:
            this->bitmap = this->bitmapDireita;
            std::cout << "direita" << std::endl;
            break;
        case CIM:
            this->bitmap = this->bitmapCima;
            std::cout << "cima" << std::endl;
            break;
    }
}

void Allegro::Sprite4D::inicializarSprite(const Sprite *sprite, const unsigned int inicioX, const unsigned int inicioY, const unsigned int larg, const unsigned int alt, int direcao){
    al_create_sub_bitmap(sprite->getBitmap(), inicioX, inicioY, larg, alt);
}

// ALLEGRO_BITMAP *Allegro::Sprite4D::getBitmapPrincipal() const{
//     return this->bitmap;
// }

const ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapEsquerda() const{
    return this->bitmapEsquerda;
}
void Allegro::Sprite4D::setBitmapEsquerda(ALLEGRO_BITMAP* bitmapEsquerda){
    this->bitmapEsquerda = bitmapEsquerda;
}

const ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapDireita() const{
    return this->bitmapDireita;
}
void Allegro::Sprite4D::setBitmapDireita(ALLEGRO_BITMAP* bitmapDireita){
    this->bitmapDireita = bitmapDireita;
}

const ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapCima() const{
    return this->bitmapCima;
}
void Allegro::Sprite4D::setBitmapCima(ALLEGRO_BITMAP* bitmapCima){
    this->bitmapCima = bitmapCima;
}

const ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapBaixo() const{
    return this->bitmapBaixo;
}
void Allegro::Sprite4D::setBitmapBaixo(ALLEGRO_BITMAP* bitmapBaixo){
    this->bitmapBaixo = bitmapBaixo;
}