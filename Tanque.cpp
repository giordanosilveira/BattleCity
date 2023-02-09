#include "Tanque.hpp"
#include "allegro/Sprite.hpp"
#include "allegro/Sprite4D.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include <iostream>

Tanque::Tanque(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, // TODO colocar const?
        const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, 
        EnumDirecao direcao)
        :Objeto{x, y, tamanhoSprite, imortal, estado, vida, velocidade, direcao}{
    
}

Tanque::~Tanque(){
    
}

void Tanque::setSprite(Allegro::Sprite4D* sprite){
    this->sprites = sprite;
}

// const Allegro::Sprite* Tanque::getSprite() const{

//     switch (this->direcao){
//         case EnumDirecao::ESQUERDA:
//             // return 
//             break;
//         case EnumDirecao::BAIXO:
//             break;
//         case EnumDirecao::DIREITA:
//             break;
//         case EnumDirecao::CIMA:
//             break;
//         case EnumDirecao::PARADO:
//             break;
//     }
//     return nullptr;
// }

/**
 * @todo: Colocar a velocidade como uma constante 
 * 
 */
// void Tanque::atirar() {

//     unsigned int y;
//     unsigned int x;

//     switch (this->direcao)
//     {
//         case (unsigned char)EnumDirecao::DIREITA:
//             y = (this->coordenada->getY() + this->getTamanhoSprite())/2;
//             x = this->coordenada->getX() + this->getTamanhoSprite();
//         break;
//         case (unsigned char)EnumDirecao::ESQUERDA:
//             y = (this->coordenada->getY() + this->getTamanhoSprite())/2;
//             x = this->coordenada->getX();
//         break;
//         case (unsigned char)EnumDirecao::CIMA:
//             y = this->coordenada->getY();
//             x = (this->coordenada->getX() + this->getTamanhoSprite())/2;
//         break;
//         case (unsigned char)EnumDirecao::BAIXO:
//             y = (this->coordenada->getY() + this->getTamanhoSprite());
//             x = (this->coordenada->getX() + this->getTamanhoSprite())/2;
//         break;
//     }

//     unsigned short int tamanhoSprite = 4;
//     bool imortal = false;
//     unsigned char estado = (unsigned char)EnumEstadoObjeto::VIVO;

//     try {
//         Tiro *tiro{new Tiro{x, y, tamanhoSprite, imortal, estado, 2, (unsigned char)EnumDirecao::DIREITA}};
//         tiro->setTanque(this);
//     }
//     catch (std::bad_alloc& ba) {
//         std::cerr << "Erro na alocação do tiro" << std::endl;
//     }
//     catch (std::runtime_error& re) {
//         std::cerr << "Erro na alocação do tiro" << std::endl;
//     }

// }
