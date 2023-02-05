#include "Player.hpp"
#include "ControleJogo.hpp"

Player::Player(/* args */)
{
}

Player::~Player()
{
}

void Player::setDirecao(){

    if (Allegro::ControleJogo::teclaPressionada(ALLEGRO_KEY_UP)){
        this->direcao = (unsigned char)EnumDirecao::CIMA;
    }
    else if (Allegro::ControleJogo::teclaPressionada(ALLEGRO_KEY_DOWN)) {
        this->direcao = (unsigned char)EnumDirecao::BAIXO;
    }
    else if (Allegro::ControleJogo::teclaPressionada(ALLEGRO_KEY_LEFT)) {
        this->direcao = (unsigned char)EnumDirecao::ESQUERDA;
    }
    else if (Allegro::ControleJogo::teclaPressionada(ALLEGRO_KEY_RIGHT)) {
        this->direcao = (unsigned char)EnumDirecao::DIREITA;
    }

}

