#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Tanque.hpp"
#include "allegro/Sprite4D.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "allegro/Sprite.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Player : public Tanque {
    public:
        Player(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, 
                const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, 
                EnumDirecao direcao, allegro::Sprite4D* const &sprites, allegro::Sprite4D* const &tiroSprites);

        virtual ~Player();

};


#endif