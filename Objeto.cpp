#include "Objeto.hpp"
#include "EnumEstadoObjeto.hpp"
#include "EnumDirecao.hpp"

Objeto::Objeto(){}

Objeto::Objeto(const unsigned int x, const unsigned int y, const unsigned short int tamanhoSprite, const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short velocidade, EnumDirecao direcao){
    Coordenada *c{new Coordenada{x, y}};
    this->coordenada = c;
    this->tamanhoSprite = tamanhoSprite;
    this->imortal = (unsigned char)imortal;
    this->estado = (unsigned char)estado;
    this->velocidade = (unsigned char)velocidade;
    this->direcao = (unsigned char)direcao;
}

// void colidiu (){
//     colidiu_x = !(fim_xa < inicio_xb || fim_xb < inicio_xa);
//     colidiu_y = !(fim_ya < inicio_yb || fim_yb < inicio_ya);
//     return colidiu_x && colidiu_y;
// }


Objeto::~Objeto(){}

const Coordenada* Objeto::getCoordenada() const{
    return this->coordenada;
}
void Objeto::setCoordenada (const unsigned short int x, unsigned short int y){
    this->coordenada->setX(x);
    this->coordenada->setY(x);
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
    
    unsigned int y = this->coordenada->getY();
    unsigned int x = this->coordenada->getX();

    /**
     * @todo: verificação se ele pode se mover. 
     * 
     */
    switch (this->direcao)
    {
        case (unsigned char)EnumDirecao::DIREITA:
            x += this->velocidade; 
            break;
        case (unsigned char)EnumDirecao::ESQUERDA:
            x -= this->velocidade;
            break; 
        case (unsigned char)EnumDirecao::CIMA:
            y -= this->velocidade;
            break; 
        case (unsigned char)EnumDirecao::BAIXO:
            y += this->velocidade;
            break;
    }

    this->setCoordenada(x, y);
}

