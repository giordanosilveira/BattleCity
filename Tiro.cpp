#include "allegro/Sprite4D.hpp"
#include "Tiro.hpp"
#include "enums/EnumDirecao.hpp"

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
        Allegro::Sprite4D* const &sprites, const unsigned int direcao_tiro)
        : Objeto{x,y,tamanhoSprite, imortal, estado, vida, velocidade, direcao}{
    this->sprites = new Allegro::Sprite4D{*sprites}; // shallow copy
    this->sprites->setSpritePrincipal(direcao_tiro);
}

Tiro::~Tiro(){}


void Tiro::mover(){

    unsigned int old_x = this->superiorEsquerda->getX();
    unsigned int old_y = this->superiorEsquerda->getY();

    unsigned int x = this->superiorEsquerda->getX();
    unsigned int y = this->superiorEsquerda->getY();

    switch (this->direcao)
    {
        case EnumDirecao::DIREITA:
            x += this->velocidade;
            break;
        case EnumDirecao::ESQUERDA:
            x -= this->velocidade;
            break; 
        case EnumDirecao::CIMA:
            y -= this->velocidade;
            break; 
        case EnumDirecao::BAIXO:
            y += this->velocidade;
            break;
        case EnumDirecao::PARADO:
            break;
    }

    this->setSuperiorEsquerda(x, y);
    // if (this->algumaColisao(paredes) || this->algumaColisao(paredesInvenciveis)) {
    //     this->setSuperiorEsquerda(old_x, old_y);
    // }
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