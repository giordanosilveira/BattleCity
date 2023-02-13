#include "Tanque.hpp"
#include "Tiro.hpp"
#include "allegro/Sprite.hpp"
#include "allegro/Sprite4D.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include <iostream>

// #include "Tiro.hpp"

Tanque::Tanque(
    const unsigned int x, 
    const unsigned int y, 
    unsigned short int tamanhoSprite, 
    const unsigned short imortal, 
    EnumEstadoObjeto estado, 
    const unsigned short vida, 
    const unsigned short velocidade, 
    EnumDirecao direcao, 
    Allegro::Sprite4D* const &sprites, 
    Allegro::Sprite4D* const &tiroSprites) :Objeto{x, y, tamanhoSprite, imortal, estado, vida, velocidade, direcao}, timerTiro{0}
{        
    this->sprites = new Allegro::Sprite4D{*sprites};
    this->sprites->setSpritePrincipal(this->sprites->BAI);
    this->tiroSprites = tiroSprites;
}

Tanque::~Tanque(){
    
}

void Tanque::setSprite(Allegro::Sprite4D*  sprite){
    this->sprites = sprite;
}

void Tanque::decrementarTimerTiro(){
    if (this->timerTiro)
        this->timerTiro--;
}

// TODO tentar criar uma lista apenas, mas não sei se da tempo
const bool Tanque::mover(const std::list<Objeto*> &objetos){
        unsigned int old_x = this->superiorEsquerda->getX();
        unsigned int old_y = this->superiorEsquerda->getY();

        unsigned int x = this->superiorEsquerda->getX();
        unsigned int y = this->superiorEsquerda->getY();

        switch (this->direcao)
        {
            case EnumDirecao::DIREITA:
                x += this->velocidade;
                this->sprites->setSpritePrincipal(this->sprites->DIR);
                break;
            case EnumDirecao::ESQUERDA:
                x -= this->velocidade;
                this->sprites->setSpritePrincipal(this->sprites->ESQ);
                break; 
            case EnumDirecao::CIMA:
                y -= this->velocidade;
                this->sprites->setSpritePrincipal(this->sprites->CIM);
                break; 
            case EnumDirecao::BAIXO:
                y += this->velocidade;
                this->sprites->setSpritePrincipal(this->sprites->BAI);
                break;
            case EnumDirecao::PARADO:
                break;
        }

        this->setSuperiorEsquerda(x, y);

        if (this->algumaColisao(objetos) != nullptr) {
            this->setSuperiorEsquerda(old_x, old_y);
            return false;
        }
    
    return true;

}

/**
 * @todo: Colocar a velocidade como uma constante 
 * 
 * TODO tamanho do sprite deve ser atributo
 * TODO repositorio com todos os sprites
 */
Tiro* Tanque::atirar(const unsigned short int tamanhoTiro, const unsigned short int velocidadeTiro) {
    if (this->timerTiro > 0) return nullptr;

    this->timerTiro = this->TIMER_INICIAL_TIRO;

    const bool imortal = false;

    unsigned int y;
    unsigned int x;
    unsigned int direcao_tiro;

    switch (this->direcao)
    {
        case EnumDirecao::DIREITA:
            y = this->superiorEsquerda->getY() + this->getTamanhoSprite()/2 - tamanhoTiro/2;
            x = this->inferiorDireita->getX();
            direcao_tiro = this->tiroSprites->DIR;
            this->tiroSprites->setSpritePrincipal(this->tiroSprites->DIR);
        break;
        case EnumDirecao::ESQUERDA:
            y = this->superiorEsquerda->getY() + this->getTamanhoSprite()/2 - tamanhoTiro/2; 
            x = this->superiorEsquerda->getX() - tamanhoTiro; 
            direcao_tiro = this->tiroSprites->ESQ;
            this->tiroSprites->setSpritePrincipal(this->tiroSprites->ESQ);
        break;
        case EnumDirecao::CIMA:
            y = this->superiorEsquerda->getY() - tamanhoTiro; 
            x = this->superiorEsquerda->getX() + this->getTamanhoSprite()/2 - tamanhoTiro/2; 
            direcao_tiro = this->tiroSprites->CIM;
            this->tiroSprites->setSpritePrincipal(this->tiroSprites->CIM);
        break;
        case EnumDirecao::BAIXO:
            y = this->inferiorDireita->getY();
            x = this->superiorEsquerda->getX() + this->getTamanhoSprite()/2 - tamanhoTiro/2;  
            direcao_tiro = this->tiroSprites->BAI;
            this->tiroSprites->setSpritePrincipal(this->tiroSprites->BAI);
        break;
    }


    Tiro *tiro{nullptr};
    try {
        tiro = new Tiro{x, y, tamanhoTiro, imortal, EnumEstadoObjeto::VIVO, 1, velocidadeTiro, this->direcao, this->tiroSprites, direcao_tiro};
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "Erro na alocação do tiro" << std::endl;
    }
    catch (std::runtime_error& re) {
        std::cerr << "Erro na alocação do tiro" << std::endl;
    }
    return tiro;

}
