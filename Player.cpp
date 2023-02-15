#include "Player.hpp"
#include "Tanque.hpp"
#include "Tiro.hpp"
#include "allegro/ControleJogo.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "enums/EnumDirecao.hpp"
#include "allegro/Sprite.hpp"
#include "allegro/Sprite4D.hpp"

Player::Player(
    const unsigned int x,
    const unsigned int y, 
    unsigned short int tamanhoSprite, 
    const unsigned short imortal, 
    EnumEstadoObjeto estado, 
    const unsigned short vida, 
    const unsigned short velocidade, 
    EnumDirecao direcao, 
    allegro::Sprite4D* const &sprites, 
    allegro::Sprite4D* const &tiroSprites
    ):Tanque{x, y, tamanhoSprite, imortal, estado, vida, velocidade, direcao, sprites, tiroSprites}
{

}

Player::~Player()
{
}
