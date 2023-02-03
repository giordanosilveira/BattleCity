#include "Objeto.hpp"

Objeto::Objeto(){}

Objeto::Objeto(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, const unsigned short imortal, const unsigned short estado, const unsigned short velocidade, const unsigned short direcao){
    Coordenada *c{new Coordenada{x, y}};
    this->coordenada = c;
    this->tamanhoSprite = tamanhoSprite;
    this->imortal = (unsigned char)imortal;
    this->estado = (unsigned char)estado;
    this->velocidade = (unsigned char)velocidade;
    this->direcao = (unsigned char)direcao;
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

const unsigned short int Objeto::getVelocidade() const {
    return this->velocidade;
}
void Objeto::setVelocidade(const unsigned short int velocidade) {
    this->velocidade = (unsigned char)velocidade;
}

const unsigned short int Objeto::getDirecao() const {
    return this->direcao;
}
void Objeto::setDirecao(const unsigned short int direcao){
    this->direcao = (unsigned char)direcao;
}

void Objeto::mover() {
    
    unsigned int y;
    unsigned int x;

    /**
     * @todo: verificação se ele pode se mover. 
     * 
     */
    switch (this->direcao)
    {
        case (unsigned char)EnumDirecao::DIREITA:
            y = this->coordenada->getY();
            x += this->velocidade; 
            break;
        case (unsigned char)EnumDirecao::ESQUERDA:
            y = this->coordenada->getY();
            x -= this->velocidade;
            break; 
        case (unsigned char)EnumDirecao::CIMA:
            y -= this->velocidade;
            x = this->coordenada->getX();
            break; 
        case (unsigned char)EnumDirecao::BAIXO:
            y += this->velocidade;
            x = this->coordenada->getX();
            break;
    }

    this->setCoordenada(x, y);
}

