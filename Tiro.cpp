#include "allegro/Sprite4D.hpp"
#include "Tiro.hpp"
#include "Tanque.hpp"

Tiro::Tiro(){}

Tiro::Tiro(
    const unsigned int x, 
    const unsigned int y, 
    const unsigned short int tamanhoSprite, 
    const unsigned short imortal, 
    EnumEstadoObjeto estado, 
    const unsigned short vida,
    const unsigned short velocidade, 
    EnumDirecao direcao,
    Allegro::Sprite4D* const &sprites): Objeto{x,y,tamanhoSprite, imortal, estado, vida, velocidade, direcao}{
    this->sprites = sprites;
    sprites->setSpritePrincipal(sprites->CIM);
}

Tiro::~Tiro(){}


void Tiro::setTanque (Tanque *tanque) {
    if (tanque == nullptr)
        throw std::runtime_error{"Ponteiro nulo: setTanque"};
        
    this->tanque = tanque;
    this->tanque->tiros.push_back(this);

    if (this->tanque != nullptr);
}

// const bool Tiro::colisao(std::list<Objeto*>&objetos) const {

//     unsigned short x_tiro = this->coordenada->getX();
//     unsigned short y_tiro = this->coordenada->getY();
//     unsigned short tam_tiro = (unsigned short)this->getTamanhoSprite();
    
//     std::list<Objeto*>::const_iterator it;

//     it = objetos.begin();
//     for (it; it != objetos.end(); ++it) {
        
//         unsigned short int x_obj = this->coordenada->getX();
//         unsigned short int y_obj = this->coordenada->getY();
//         unsigned short int tam_obj = (unsigned short) (*it)->getTamanhoSprite();

//         switch (this->direcao)
//         {
//             case (unsigned char)EnumDirecao::DIREITA:
//                 if ((y_tiro >= y_obj && y_tiro <= y_obj + tam_obj)) {
//                     if (x_tiro + tam_tiro >= x_obj)
//                         return true;
//                 }
//                 break;
//             case (unsigned char)EnumDirecao::ESQUERDA:
//                 if ((y_tiro >= y_obj && y_tiro <= y_obj + tam_obj)) {
//                     if (x_tiro <= x_obj + tam_obj)
//                         return true;
//                 }
//                 break;
//             case (unsigned char)EnumDirecao::BAIXO:
//                 if ((x_tiro >= x_obj && x_tiro <= x_obj + tam_obj)) {
//                     if (y_tiro + tam_tiro >= x_obj)
//                         return true;
//                 }
//                 break;
//             case (unsigned char)EnumDirecao::CIMA:
//                 if ((x_tiro >= x_obj && x_tiro <= x_obj + tam_obj)) {
//                     if (y_tiro <= y_obj + tam_obj)
//                         return true;
//                 }
//                 break;
//         }
//     }
//     return false;

// }