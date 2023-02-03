#include "Player.hpp"

Player::Player(/* args */)
{
}

Player::~Player()
{
}

void Player::setDirecao(){

    if (Allegro::teclaPressionada(ALLEGRO_KEY_UP)){
        this->direcao = (unsigned char)EnumDirecao::CIMA;
    }
    else if (Allegro::teclaPressionada(ALLEGRO_KEY_DOWN)) {
        this->direcao = (unsigned char)EnumDirecao::BAIXO;
    }
    else if (Allegro::teclaPressionada(ALLEGRO_KEY_LEFT)) {
        this->direcao = (unsigned char)EnumDirecao::ESQUERDA;
    }
    else if (Allegro::teclaPressionada(ALLEGRO_KEY_RIGHT)) {
        this->direcao = (unsigned char)EnumDirecao::DIREITA;
    }

}

