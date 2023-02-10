#include "Player.hpp"
#include "Parede.hpp"
#include "Tanque.hpp"
#include "Tiro.hpp"
#include "allegro/ControleJogo.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "enums/EnumDirecao.hpp"
#include "allegro/Sprite.hpp"
#include "allegro/Sprite4D.hpp"

Player::Player(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, 
                const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, 
                EnumDirecao direcao, Allegro::Sprite4D* const &sprites)
                :Tanque{x, y, tamanhoSprite, imortal, estado, vida, velocidade, direcao, sprites}
{
    this->sprites = sprites;
    this->sprites->setSpritePrincipal(this->sprites->BAI);
}

Player::~Player()
{
}

bool Player::algumaColisao(const std::vector<const Parede *> &paredes){
    std::vector<const Parede *>::const_iterator it;
    it = paredes.begin();
    for (; it < paredes.end(); ++it)
        if (this->colisao(*it))
            return true;
    return false;
}

const bool Player::colisao(const Parede *parede) const {

    const Coordenada *coordInferiorDireita = parede->getInferiorDireita();
    const Coordenada *coordSuperiorEsquerda = parede->getSuperiorEsquerda();
    if (this->superiorEsquerda->getY() >= coordInferiorDireita->getY()) return false;
    if (this->inferiorDireita->getY() <= coordSuperiorEsquerda->getY()) return false;
    if (this->superiorEsquerda->getX() >= coordInferiorDireita->getX()) return false;
    if (this->inferiorDireita->getX() <= coordSuperiorEsquerda->getX()) return false;

    return true;
}


void Player::mover(const std::vector<const Parede *> &paredes, const std::vector<const Parede *> &paredesInvenciveis){
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
        if (this->algumaColisao(paredes) || this->algumaColisao(paredesInvenciveis)) {
            this->setSuperiorEsquerda(old_x, old_y);
        }
        

}
