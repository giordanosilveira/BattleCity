#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Tanque.hpp"
#include "EnumDirecao.hpp"
#include "EnumEstadoObjeto.hpp"
#include "Sprite.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Player : public Tanque {
    public:
        Player(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, 
                const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short velocidade, 
                EnumDirecao direcao, Allegro::Sprite *sprite);

        ~Player();

        // virtual void setDirecao() override;
    
};


#endif