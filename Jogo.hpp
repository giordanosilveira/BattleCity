#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <memory>
#include "Sprite.hpp"
#include "Player.hpp"

class Jogo{
    public:
        ~Jogo();
        Jogo(Jogo &outro) = delete;
        void operator=(const Jogo &outro) = delete;

        static Jogo *getInstancia();

        Player *player;
    private:
        Jogo();
        static Jogo *instancia;

        void carregarSprites();

        std::list<std::shared_ptr<Objeto>> elementosTela;

        Allegro::Sprite *spritesheet;
        std::vector< std::vector<Allegro::Sprite*> > spritesTanque;

        const unsigned short int TANK_MAT_WID = 8;
        const unsigned short int TANK_MAT_HEI = 8;
        const unsigned short int TANK_WID = 16;
        const unsigned short int TANK_HEI = 16;
        enum corTanque {
            TANQUE_AMARELO = 0,
            TANQUE_VERMELHO
        };
        
};

#endif