#include "Player.hpp"
#include "Parede.hpp"
#include "Tanque.hpp"
#include "allegro/ControleJogo.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "enums/EnumDirecao.hpp"
#include "allegro/Sprite.hpp"

Player::Player(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, 
                const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, 
                EnumDirecao direcao, Allegro::Sprite *sprite, const std::vector<Allegro::Sprite*> sprites)
                :Tanque{x, y, tamanhoSprite, imortal, estado, vida, velocidade, direcao}
{
    this->sprite = sprite;
    std::vector<Allegro::Sprite*>::const_iterator it = sprites.begin();
    for (; it != sprites.end(); ++it)
        this->sprites.push_back(*it);
    
}

Player::~Player()
{
}

bool Player::algumaColisao(const std::vector<const Parede *> &paredes){
    std::vector<const Parede *>::const_iterator it;
    for (; it < paredes.end(); ++it)
        if (this->colisao(*it))
            return true;
    return false;
}

void Player::mover(const std::vector<const Parede *> &paredes){
        unsigned int old_x = this->superiorEsquerda->getX();
        unsigned int old_y = this->superiorEsquerda->getY();

        unsigned int x = this->superiorEsquerda->getX();
        unsigned int y = this->superiorEsquerda->getY();

        switch (this->direcao)
        {
            case EnumDirecao::DIREITA:
                x += this->velocidade;
                this->sprite = sprites[6];

                break;
            case EnumDirecao::ESQUERDA:
                x -= this->velocidade;
                this->sprite = sprites[2];
                break; 
            case EnumDirecao::CIMA:
                y -= this->velocidade;
                this->sprite = sprites[0];
                break; 
            case EnumDirecao::BAIXO:
                y += this->velocidade;
                this->sprite = sprites[4];
                break;
        }


        this->setSuperiorEsquerda(x, y);
        this->setSuperiorEsquerda(x_old, y_old);
        

}
