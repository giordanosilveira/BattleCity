#include "Sprite4D.hpp"

Allegro::Sprite4D::Sprite4D(){}

Allegro::Sprite4D::Sprite4D(ALLEGRO_BITMAP* bitmapEsquerda, ALLEGRO_BITMAP* bitmapDireita,
    ALLEGRO_BITMAP* bitmapCima, ALLEGRO_BITMAP* bitmapBaixo):bitmapEsquerda{bitmapEsquerda}, bitmapDireita{bitmapDireita}, bitmapCima{bitmapCima}, bitmapBaixo{bitmapBaixo}{
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