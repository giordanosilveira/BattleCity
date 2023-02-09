#include "Sprite4D.hpp"
#include <iostream>

Allegro::Sprite4D::Sprite4D()
        :Sprite{},bitmapEsquerda{nullptr},bitmapBaixo{nullptr},bitmapDireita{nullptr},bitmapCima{nullptr}{
}

// Allegro::Sprite4D::Sprite4D(Sprite* spriteEsquerda, Sprite* spriteBaixo, Sprite* spriteDireita, Sprite* spriteCima):bitmapEsquerda{spriteEsquerda->getBitmap()}, bitmapBaixo{spriteBaixo->getBitmap()}, bitmapDireita{spriteDireita->getBitmap()}, bitmapCima{spriteCima->getBitmap()}{
// }

Allegro::Sprite4D::~Sprite4D(){}

void Allegro::Sprite4D::setSpritePrincipal(const int direcao){
    // TODO meio ruim essas constantes mas n sei como fazer melhor
    switch (direcao){
        case CIM:
            this->bitmap = this->bitmapCima;
            break;
        case ESQ:
            this->bitmap = this->bitmapEsquerda;
            break;
        case BAI:
            this->bitmap = this->bitmapBaixo;
            break;
        case DIR:
            this->bitmap = this->bitmapDireita;
            break;
    }
}

void Allegro::Sprite4D::inicializarSprite(const Sprite * const sprite, const unsigned int inicioX, const unsigned int inicioY, const unsigned int larg, const unsigned int alt, const int direcao){
    ALLEGRO_BITMAP* bmap = al_create_sub_bitmap(sprite->getBitmap(), inicioX, inicioY, larg, alt);

    switch (direcao){
        case this->ESQ:
            this->bitmapEsquerda = bmap;
        break;
        case this->BAI:
            this->bitmapBaixo = bmap;
        break;
        case this->DIR:
            this->bitmapDireita = bmap;
        break;
        case this->CIM:
            this->bitmapCima = bmap;
        break;
    }

}

ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapPrincipal() const{
    return this->bitmap;
}

// const ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapEsquerda() const{
//     return this->bitmapEsquerda;
// }
// void Allegro::Sprite4D::setBitmapEsquerda(ALLEGRO_BITMAP* bitmapEsquerda){
//     this->bitmapEsquerda = bitmapEsquerda;
// }

// const ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapDireita() const{
//     return this->bitmapDireita;
// }
// void Allegro::Sprite4D::setBitmapDireita(ALLEGRO_BITMAP* bitmapDireita){
//     this->bitmapDireita = bitmapDireita;
// }

// const ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapCima() const{
//     return this->bitmapCima;
// }
// void Allegro::Sprite4D::setBitmapCima(ALLEGRO_BITMAP* bitmapCima){
//     this->bitmapCima = bitmapCima;
// }

// const ALLEGRO_BITMAP* Allegro::Sprite4D::getBitmapBaixo() const{
//     return this->bitmapBaixo;
// }
// void Allegro::Sprite4D::setBitmapBaixo(ALLEGRO_BITMAP* bitmapBaixo){
//     this->bitmapBaixo = bitmapBaixo;
// }