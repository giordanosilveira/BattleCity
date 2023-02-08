#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <memory>
#include "allegro/Sprite.hpp"
#include "Player.hpp"
#include "Parede.hpp"
// #include "Muro.hpp"
// #include "Parede.hpp"
// #include "Tanque.hpp"
// #include "Explosao.hpp"
// #include "Mato.hpp"
// #include "Agua.hpp"
// #include "Insignia.hpp"

class Jogo{
    public:
        ~Jogo();
        Jogo(Jogo &outro) = delete;
        void operator=(const Jogo &outro) = delete;

        static Jogo *getInstancia();

        Player *player;
        std::vector<const Parede *> paredes;
        
        void moverPlayer();

        /**
         * @todo: Instanciar todas as classes do jogo aqui
         */
        //std::list<>
        void desenharParedes();

        Allegro::Sprite *spritesheet;
        Allegro::Sprite *muro;
        Allegro::Sprite *agua;
        Allegro::Sprite *mato;
        Allegro::Sprite *parede;
        Allegro::Sprite *paredeInvencivel;
        std::vector<Allegro::Sprite*>insignias;

    private:
        Jogo();
        static Jogo *instancia;

        void carregarSprites();

        void criarParedesBorda();

        std::list<std::shared_ptr<Objeto>> elementosTela;

        std::vector< std::vector<Allegro::Sprite*> > spritesTanque;

        const unsigned short int TANK_MAT_WID = 8;
        const unsigned short int TANK_MAT_HEI = 8;
        const unsigned short int TANK_WID = 16;
        const unsigned short int TANK_HEI = 16;
        const unsigned short int PAREDE_SIZE = 8;
        const unsigned short int BLOCO_SIZE = 16;
        enum corTanque {
            TANQUE_AMARELO = 0,
            TANQUE_VERMELHO
        };
        
};

#endif