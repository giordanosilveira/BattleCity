#include "Sprite4D.hpp"

Allegro::Sprite4D::Sprite4D(){}

Allegro::Sprite4D::Sprite4D(Sprite* spriteEsquerda, Sprite* spriteBaixo, Sprite* spriteDireita, Sprite* spriteCima):bitmapEsquerda{spriteEsquerda->getBitmap()}, bitmapBaixo{spriteBaixo->getBitmap()}, bitmapDireita{spriteDireita->getBitmap()}, bitmapCima{spriteCima->getBitmap()}{
}

Allegro::Sprite4D::~Sprite4D(){}

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