#include "Tanque.hpp"
#include "EnumDirecao.hpp"
#include "EnumEstadoObjeto.hpp"

Tanque::Tanque(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, // TODO colocar const?
        const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short velocidade, 
        EnumDirecao direcao)
        :Objeto{x, y, tamanhoSprite, imortal, estado, velocidade, direcao}{
    
}

Tanque::~Tanque(){
    
}

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
