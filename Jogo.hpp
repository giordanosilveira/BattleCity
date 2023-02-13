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

        const unsigned short int TIRO_SIZE = 4;
        const unsigned short int TIRO_VELOCIDADE = 3;
        const unsigned short int TANQUE_SIZE = 16;
        const unsigned short int TANQUE_VELOCIDADE = 2;

        Mapa *mapa;
        Player *player;
        std::list<Parede*> paredes;
        std::list<Parede*> paredeInvencivel;
        std::list<Tanque*> inimigos;
        //std::list<Tanque*> proximosInimigos;
        std::list<Tiro*> tiros;
        std::list<Tiro*> tirosInimigos;
        
        void moverPlayer();
        void atualizarTiros();
        void atualizarTirosPlayer();
        void atualizarTirosInimigos();

        void atualizarParedes();
        void atualizarPlayer();
        void atualizarInimigos();
        void acaoInimigos();
        void moverTanque(Tanque *tanque);
        void decrementarTimerTirosInimigos();
        void matarInimigos();
        void criarInimigos();

        /**
         * @todo: Instanciar todas as classes do jogo aqui
         */
        //std::list<>
        void desenharParedes() const;
        void desenharTanque(const Tanque* tanque) const;
        void desenharTiros() const;
        void desenharInimigos() const;

        Allegro::Sprite *spritesheet;
        Allegro::Sprite *parede;
        Allegro::Sprite *paredeInvencivelSprite;
        Allegro::Sprite4D *tiroSprite;
        std::vector<Allegro::Sprite*>insignias;

        void adicionarTiro(Tiro * const tiro);
        void adicionarTirosInimigos(Tiro * const tiro);

    private:
        Jogo();
        static Jogo *instancia;

        void montarObjetos();
        void carregarSprites();

        /* Funções auxiliares */
        void criarParedesBorda();

        std::list<std::shared_ptr<Objeto>> elementosTela;

        std::vector<Allegro::Sprite4D*>spritesTanque;
        std::vector<Allegro::Sprite4D*>spritesTanqueInimigos;
        std::vector<Allegro::Sprite4D*>spritesTanquePlayer;

        const unsigned short int LIMITE_TIROS_PLAYER = 3;
        const unsigned short int LIMITE_INIMIGOS = 3;
        const unsigned short int LIMITE_TIROS_INIMIGOS = 10;
        
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