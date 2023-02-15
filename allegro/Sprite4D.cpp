#include "Sprite4D.hpp"
#include <iostream>

allegro::Sprite4D::Sprite4D()
        :Sprite{},bitmapEsquerda{nullptr},bitmapBaixo{nullptr},bitmapDireita{nullptr},bitmapCima{nullptr}{
}

// allegro::Sprite4D::Sprite4D(Sprite* spriteEsquerda, Sprite* spriteBaixo, Sprite* spriteDireita, Sprite* spriteCima):bitmapEsquerda{spriteEsquerda->getBitmap()}, bitmapBaixo{spriteBaixo->getBitmap()}, bitmapDireita{spriteDireita->getBitmap()}, bitmapCima{spriteCima->getBitmap()}{
// }

allegro::Sprite4D::~Sprite4D(){}

void allegro::Sprite4D::setSpritePrincipal(int direcao){
    // TODO meio ruim essas constantes mas n sei como fazer melhor
    switch (direcao){
        case ESQ:
            this->bitmap = this->bitmapEsquerda;
            break;
        case BAI:
            this->bitmap = this->bitmapBaixo;
            break;
        case DIR:
            this->bitmap = this->bitmapDireita;
            break;
        case CIM:
            this->bitmap = this->bitmapCima;
            break;
    }
}

void allegro::Sprite4D::inicializarSprite(const Sprite *sprite, const unsigned int inicioX, const unsigned int inicioY, const unsigned int larg, const unsigned int alt, int direcao){
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

// ALLEGRO_BITMAP *allegro::Sprite4D::getBitmapPrincipal() const{
//     return this->bitmap;
// }

const ALLEGRO_BITMAP* allegro::Sprite4D::getBitmapEsquerda() const{
    return this->bitmapEsquerda;
}
void allegro::Sprite4D::setBitmapEsquerda(ALLEGRO_BITMAP* bitmapEsquerda){
    this->bitmapEsquerda = bitmapEsquerda;
}

const ALLEGRO_BITMAP* allegro::Sprite4D::getBitmapDireita() const{
    return this->bitmapDireita;
}
void allegro::Sprite4D::setBitmapDireita(ALLEGRO_BITMAP* bitmapDireita){
    this->bitmapDireita = bitmapDireita;
}

const ALLEGRO_BITMAP* allegro::Sprite4D::getBitmapCima() const{
    return this->bitmapCima;
}
void allegro::Sprite4D::setBitmapCima(ALLEGRO_BITMAP* bitmapCima){
    this->bitmapCima = bitmapCima;
}

const ALLEGRO_BITMAP* allegro::Sprite4D::getBitmapBaixo() const{
    return this->bitmapBaixo;
}
void allegro::Sprite4D::setBitmapBaixo(ALLEGRO_BITMAP* bitmapBaixo){
    this->bitmapBaixo = bitmapBaixo;
}