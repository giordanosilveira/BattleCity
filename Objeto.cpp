#include "Objeto.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "enums/EnumDirecao.hpp"

Objeto::Objeto(){}

Objeto::Objeto(
    const unsigned int x,
    const unsigned int y,
    const unsigned short int tamanhoSprite, 
    const unsigned short imortal, 
    EnumEstadoObjeto estado, 
    const unsigned short vida,
    const unsigned short velocidade, 
    EnumDirecao direcao
    ){
    
    Coordenada *cse{new Coordenada{x, y}};
    Coordenada *cid{new Coordenada{x + tamanhoSprite, y + tamanhoSprite}};
    this->superiorEsquerda = cse;
    this->inferiorDireita = cid;
    this->tamanhoSprite = tamanhoSprite;
    this->imortal = (unsigned char)imortal;
    this->estado = (unsigned char)estado;
    this->vida = (unsigned char)vida;
    this->velocidade = (unsigned char)velocidade;
    this->direcao = direcao;
}

// void colidiu (){
//     colidiu_x = !(fim_xa < inicio_xb || fim_xb < inicio_xa);
//     colidiu_y = !(fim_ya < inicio_yb || fim_yb < inicio_ya);
//     return colidiu_x && colidiu_y;
// }


Objeto::~Objeto(){}

const Coordenada* Objeto::getSuperiorEsquerda() const{
    return this->superiorEsquerda;
}

const Coordenada* Objeto::getInferiorDireita() const {
    return this->inferiorDireita;
}

void Objeto::setSuperiorEsquerda (const unsigned short int x, unsigned short int y){
    this->superiorEsquerda->setX(x);
    this->superiorEsquerda->setY(y);
    
    // TODO Talvez mudar para updateInferiorDireita (só diferença semântica mesmo)
    this->setInferiorDireita(x, y);
}
void Objeto::setInferiorDireita (const unsigned short int x, unsigned short int y){
    this->inferiorDireita->setX(x + this->tamanhoSprite);
    this->inferiorDireita->setY(y + this->tamanhoSprite);
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

const EnumDirecao Objeto::getDirecao() const {
    return this->direcao;
}
void Objeto::setDirecao(EnumDirecao direcao){
    this->direcao = direcao;
}

const Allegro::Sprite* Objeto::getSprite() const{
    return this->sprite;
}

// const bool Objeto::colisao(const Objeto *obj) const {
//     const Coordenada *coordInferiorDireita = obj->superiorEsquerda;
//     const Coordenada *coordSuperiorEsquerda = obj->inferiorDireita;
//     if (this->superiorEsquerda->getX() > coordInferiorDireita->getX()) return false;
//     if (this->inferiorDireita->getX() < coordSuperiorEsquerda->getX()) return false;
//     if (this->superiorEsquerda->getY() > coordInferiorDireita->getY()) return false;
//     if (this->inferiorDireita->getY() < coordSuperiorEsquerda->getY()) return false;

//     return true;
// }

// void Objeto::mover(const std::vector<const Parede *> &paredes) {
//     unsigned int old_x = this->superiorEsquerda->getX();
//     unsigned int old_y = this->superiorEsquerda->getY();

//     unsigned int x = this->superiorEsquerda->getX();
//     unsigned int y = this->superiorEsquerda->getY();

//     switch (this->direcao)
//     {
//         case EnumDirecao::DIREITA:
//             x += this->velocidade; 
//             break;
//         case EnumDirecao::ESQUERDA:
//             x -= this->velocidade;
//             break; 
//         case EnumDirecao::CIMA:
//             y -= this->velocidade;
//             break; 
//         case EnumDirecao::BAIXO:
//             y += this->velocidade;
//             break;
//     }


//     this->setSuperiorEsquerda(x, y);
//     this->setSuperiorEsquerda(old_x, old_y); 
// }

