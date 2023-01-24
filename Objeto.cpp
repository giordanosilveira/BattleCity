#include "Objeto.hpp"

Objeto::Objeto(){}

Objeto::Objeto(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite){
    Coordenada *c{new Coordenada{x, y}};
    this->coordenada = c;
    this->tamanhoSprite = tamanhoSprite;
}

Objeto::~Objeto(){}

const Coordenada* Objeto::getCoordenada() const{
    return this->coordenada;
}
void Objeto::setCoordenada (const unsigned short int x, unsigned short int y){
    this->coordenada->setX(x);
    this->coordenada->setY(x);
}

const ALLEGRO_BITMAP* Objeto::getSprite(const int index) const{
    // Erro caso o num seja maior que x
    return this->sprites.at(index);
}
void Objeto::adicionarSprite(ALLEGRO_BITMAP* sprite, const int qtdSprites){
    // Se a quantidade for maior que qtdSprites lança um erro
    this->sprites.push_back(sprite);
}

const unsigned short int Objeto::getTamanhoSprite() const{
    return (unsigned short int)this->tamanhoSprite;
}
void Objeto::setTamanhoSprite(unsigned short int tamanhoSprite){
    this->tamanhoSprite = (unsigned char)tamanhoSprite;
}