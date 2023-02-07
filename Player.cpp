#include "Player.hpp"
#include "Tanque.hpp"
#include "ControleJogo.hpp"
#include "EnumEstadoObjeto.hpp"
#include "EnumDirecao.hpp"
#include "Sprite.hpp"

Player::Player(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, 
                const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short velocidade, 
                EnumDirecao direcao, Allegro::Sprite *sprite)
                :Tanque{x, y, tamanhoSprite, imortal, estado, velocidade, direcao}
{
    this->sprite = sprite;
}

Player::~Player()
{
}

// void Player::setDirecao(){
//     Allegro::ControleJogo *al = Allegro::ControleJogo::getInstancia();
//     if (al->teclaPressionada(al->SETA_CIMA)){
//         this->direcao = (unsigned char)EnumDirecao::CIMA;
//     }
//     else if (al->teclaPressionada(al->SETA_BAIXO)) {
//         this->direcao = (unsigned char)EnumDirecao::BAIXO;
//     }
//     else if (al->teclaPressionada(al->SETA_ESQUERDA)) {
//         this->direcao = (unsigned char)EnumDirecao::ESQUERDA;
//     }
//     else if (al->teclaPressionada(al->SETA_DIREITA)) {
//         this->direcao = (unsigned char)EnumDirecao::DIREITA;
//     }

// }

