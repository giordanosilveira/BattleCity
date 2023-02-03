#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Tanque.hpp"
#include "EnumDirecao.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Player : public Tanque {
    public:
        Player(/* args */);

        ~Player();

        virtual void setDirecao() override;
    
};


#endif