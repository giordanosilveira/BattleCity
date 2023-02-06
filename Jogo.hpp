#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include "Sprite.hpp"

class Jogo{
    public:
        ~Jogo();
        Jogo(Jogo &outro) = delete;
        void operator=(const Jogo &outro) = delete;

        static Jogo *getInstancia();

    private:
        Jogo();
        static Jogo *instancia;

        void carregarSprites();

        Allegro::Sprite *spritesheet;
        std::vector< std::vector<Allegro::Sprite*> > spritesTanque;

        const unsigned short int TANK_MAT_WID = 8;
        const unsigned short int TANK_MAT_HEI = 8;
        const unsigned short int TANK_WID = 16;
        const unsigned short int TANK_HEI = 16;
        
};

#endif