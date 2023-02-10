#include "Tanque.hpp"
#include "Tiro.hpp"
#include "allegro/Sprite.hpp"
#include "allegro/Sprite4D.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include <iostream>

// #include "Tiro.hpp"

Tanque::Tanque(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, // TODO colocar const?
        const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, 
        EnumDirecao direcao)
        :Objeto{x, y, tamanhoSprite, imortal, estado, vida, velocidade, direcao}{
    
}

Tanque::~Tanque(){
    
}

void Tanque::setSprite(Allegro::Sprite4D*  sprite){
    this->sprites = sprite;
}

/**
 * @todo: Colocar a velocidade como uma constante 
 * 
 * TODO tamanho do sprite deve ser atributo
 * TODO repositorio com todos os sprites
 */
void Tanque::atirar() {

    unsigned int y;
    unsigned int x;

    switch (this->direcao)
    {
        case EnumDirecao::DIREITA:
            y = this->superiorEsquerda->getY() + this->getTamanhoSprite()/2;
            x = this->inferiorDireita->getX();
        break;
        case EnumDirecao::ESQUERDA:
            y = this->superiorEsquerda->getY() + this->getTamanhoSprite()/2;
            x = this->superiorEsquerda->getX() - this->getTamanhoSprite(); // tem que ser o sprite do tiro
        break;
        case EnumDirecao::CIMA:
            y = this->superiorEsquerda->getY() - this->getTamanhoSprite(); // tem que ser sprite do tiro
            x = this->superiorEsquerda->getX() + this->getTamanhoSprite()/2;
        break;
        case EnumDirecao::BAIXO:
            y = this->inferiorDireita->getY();
            x = this->superiorEsquerda->getX() + this->getTamanhoSprite()/2;
        break;
        case EnumDirecao::PARADO:
        break;
    }

    unsigned short int tamanhoSprite = 4;
    bool imortal = false;

    try {
        Tiro *tiro{new Tiro{x, y, tamanhoSprite, imortal, EnumEstadoObjeto::VIVO, 1, 3, this->direcao, this->sprites}};
        tiro->setTanque(this);
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "Erro na alocação do tiro" << std::endl;
    }
    catch (std::runtime_error& re) {
        std::cerr << "Erro na alocação do tiro" << std::endl;
    }

}
