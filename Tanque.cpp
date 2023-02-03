#include "Tanque.hpp"
#include "EnumDirecao.hpp"
#include "EnumEstadoObjeto.hpp"

/**
 * @todo: Colocar a velocidade como uma constante 
 * 
 */
void Tanque::atirar() {

    unsigned int y;
    unsigned int x;

    switch (this->direcao)
    {
        case (unsigned char)EnumDirecao::DIREITA:
            y = (this->coordenada->getY() + this->getTamanhoSprite())/2;
            x = this->coordenada->getX() + this->getTamanhoSprite();
        break;
        case (unsigned char)EnumDirecao::ESQUERDA:
            y = (this->coordenada->getY() + this->getTamanhoSprite())/2;
            x = this->coordenada->getX();
        break;
        case (unsigned char)EnumDirecao::CIMA:
            y = this->coordenada->getY();
            x = (this->coordenada->getX() + this->getTamanhoSprite())/2;
        break;
        case (unsigned char)EnumDirecao::BAIXO:
            y = (this->coordenada->getY() + this->getTamanhoSprite());
            x = (this->coordenada->getX() + this->getTamanhoSprite())/2;
        break;
    }

    unsigned short int tamanhoSprite = 4;
    bool imortal = false;
    unsigned char estado = (unsigned char)EnumEstadoObjeto::VIVO;

    try {
        Tiro *tiro{new Tiro{x, y, tamanhoSprite, imortal, estado, 2, (unsigned char)EnumDirecao::DIREITA}};
        tiro->setTanque(this);
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "Erro na alocação do tiro" << std::endl;
    }
    catch (std::runtime_error& re) {
        std::cerr << "Erro na alocação do tiro" << std::endl;
    }

}

void Tanque::mover() {
    
    unsigned int y;
    unsigned int x;

    /**
     * @todo: verificação se ele pode se mover. 
     * 
     */
    switch (this->direcao)
    {
        case (unsigned char)EnumDirecao::DIREITA:
            y = this->coordenada->getY();
            x += this->velocidade; 
            break;
        case (unsigned char)EnumDirecao::ESQUERDA:
            y = this->coordenada->getY();
            x -= this->velocidade;
            break; 
        case (unsigned char)EnumDirecao::CIMA:
            y -= this->velocidade;
            x = this->coordenada->getX();
            break; 
        case (unsigned char)EnumDirecao::BAIXO:
            y += this->velocidade;
            x = this->coordenada->getX();
            break;
    }

    this->setCoordenada(x, y);
}

void Tanque::setDirecao() {

    unsigned short int direcao = rand()%(51 - 48 + 1) + 48;
    this->direcao = direcao
}