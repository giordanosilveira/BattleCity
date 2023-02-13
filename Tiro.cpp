#include "allegro/Sprite4D.hpp"
#include "Tiro.hpp"
#include "Parede.hpp"
#include "Tanque.hpp"
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


// Objeto* Tiro::algumaColisao(const std::list<Objeto *> &objetos){
//     std::list<Objeto *>::const_iterator it;
//     it = objetos.begin();

//     for (; it != objetos.end(); ++it)
//         if (this->Objeto::colisao(*it))
//             return *it;
//     return nullptr;
// }

// const bool Tiro::colisao(const Tanque *tanque) const {
    
//     if (tanque == nullptr)
//         return false;

//     const Coordenada *coordSuperiorEsquerda = tanque->getSuperiorEsquerda();
//     const Coordenada *coordInferiorDireita = tanque->getInferiorDireita();
    
//     if (this->superiorEsquerda->getY() >= coordInferiorDireita->getY()) return false;
//     if (this->inferiorDireita->getY() <= coordSuperiorEsquerda->getY()) return false;
//     if (this->superiorEsquerda->getX() >= coordInferiorDireita->getX()) return false;
//     if (this->inferiorDireita->getX() <= coordSuperiorEsquerda->getX()) return false;

//     return true;
// }


void Tiro::mover(std::list<Objeto*> objetos){

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
    Objeto *obj = this->algumaColisao(objetos);
    if (obj != nullptr){
        obj->levarDano(1);
        this->morrer();
    }
    
}
