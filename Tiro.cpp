#include "allegro/Sprite4D.hpp"
#include "Tiro.hpp"
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


bool Tiro::algumaColisao(const std::list<Parede *> &paredes){
    std::list<Parede *>::const_iterator it;
    it = paredes.begin();

    for (; it != paredes.end(); ++it)
        if (this->Objeto::colisao(*it)){
            (*it)->levarDano(1);
            return true;
        }
    return false;
}

const bool Tiro::colisao(const Tanque *tanque) const {
    const Coordenada *coordSuperiorEsquerda = tanque->getSuperiorEsquerda();
    const Coordenada *coordInferiorDireita = tanque->getInferiorDireita();
    
    std::cerr << "Tiro X: " << this->getSuperiorEsquerda()->getX() << " " << "Y: " << this->getSuperiorEsquerda()->getY() << std::endl;
    std::cerr << "Tiro X: " << this->getInferiorDireita()->getX() << " " << "Y: " << this->getInferiorDireita()->getY() << std::endl;
    std::cerr << "X: " << coordSuperiorEsquerda->getX() << " " << "Y: " << coordSuperiorEsquerda->getY() << std::endl;
    std::cerr << "X: " << coordInferiorDireita->getX() << " " << "Y: " << coordInferiorDireita->getY() << std::endl;  

    if (this->superiorEsquerda->getY() >= coordInferiorDireita->getY()) return false;
    if (this->inferiorDireita->getY() <= coordSuperiorEsquerda->getY()) return false;
    if (this->superiorEsquerda->getX() >= coordInferiorDireita->getX()) return false;
    if (this->inferiorDireita->getX() <= coordSuperiorEsquerda->getX()) return false;

    return true;
}


bool Tiro::algumaColisao(Tanque * tanque) {

    if (this->Tiro::colisao(tanque)) {
        std::cerr << "Aqui po" << std::endl;
        tanque->levarDano(1);
        return true;
    }
    return false;

}



void Tiro::mover(std::list<Parede *>&paredes, std::list<Parede *> &paredes2, Tanque *inimigo){

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
    if (this->algumaColisao(paredes) || this->algumaColisao(paredes2) || this->algumaColisao(inimigo))  {
        this->morrer();
    }
}
