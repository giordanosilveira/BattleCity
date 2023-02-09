#ifndef JOGO_HPP
#define JOGO_HPP

#include <vector>
#include <memory>
#include "allegro/Sprite.hpp"
#include "Player.hpp"
#include "Parede.hpp"
#include "allegro/Sprite4D.hpp"
#include "Tanque.hpp"
#include "Mapa.hpp"
// #include "Parede.hpp"
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

        Mapa *mapa;
        Player *player;
        std::vector<const Parede *> paredes;
        std::vector<const Parede *> paredeInvencivel;
        std::list<const Tanque *> tanques;
        
        
        void moverPlayer();

        /**
         * @todo: Instanciar todas as classes do jogo aqui
         */
        //std::list<>
        void desenharParedes() const;
        void desenharTanque(const Tanque* tanque) const;

        Allegro::Sprite *spritesheet;
        Allegro::Sprite *parede;
        Allegro::Sprite *paredeInvencivelSprite;
        std::vector<Allegro::Sprite*>insignias;


    private:
        Jogo();
        static Jogo *instancia;

        void montarObjetos();
        void carregarSprites();

        /* Funções auxiliares */
        void criarParedesBorda();

        std::list<std::shared_ptr<Objeto>> elementosTela;

        std::vector<Allegro::Sprite4D*>spritesTanque;
        std::vector<Allegro::Sprite4D*>spritesTanquePlayer;

        const unsigned short int TANK_MAT_WID = 8;
        const unsigned short int TANK_MAT_HEI = 8;
        const unsigned short int TANK_WID = 16;
        const unsigned short int TANK_HEI = 16;
        const unsigned short int PAREDE_SIZE = 8;
        const unsigned short int BLOCO_SIZE = 16;
        const unsigned short int OFFSET = 8;
        enum corTanque {
            TANQUE_AMARELO = 0,
            TANQUE_VERMELHO
        };
        
};

#endif