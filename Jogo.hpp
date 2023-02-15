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
#include "Insignia.hpp"
// #include "Parede.hpp"
// #include "Explosao.hpp"
// #include "Mato.hpp"
// #include "Agua.hpp"

class Jogo{
    public:
        virtual ~Jogo();
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
        std::list<Tiro*> tiros;
        std::list<Tiro*> tirosInimigos;
        unsigned short int n_tanques;
        Insignia *insignia;
        

        void moverPlayer();
        
        void atualizarEntidades();

        void acaoInimigos();
        void moverTanque(Tanque *tanque);
        void decrementarTimerTirosInimigos();
        void matarInimigos();
        void criarInimigos();


        void desenharParedes() const;
        void desenharTiros() const;
        void desenharInimigos() const;
        void desenharTanquesPontos() const;
        void desenharPontos() const;
        void desenharVida() const;
        
        allegro::Sprite *spritesheet;
        allegro::Sprite *parede;
        allegro::Sprite *paredeInvencivelSprite;
        allegro::Sprite4D *tiroSprite;
        allegro::Sprite *backgroudPontuacao;
        allegro::Sprite* tanquePonto;
        allegro::Sprite* vida;
        std::vector<allegro::Sprite*>insignias;

        bool getVencido();
        void setVencido(const bool vencido);

        void adicionarTiro(Tiro * const tiro);
        void adicionarTirosInimigos(Tiro * const tiro);

        const unsigned int getPontos() const;
        void aumentarPontos();


    private:
        Jogo();
        static Jogo *instancia;

        void carregarSprites();

        /* Funções auxiliares */
        void criarParedesBorda();
        void geraListaColisaoTanque(std::list<Objeto*> &objetos);
        void geraListaColisaoTiroPlayer(std::list<Objeto*> &objetos);
        void geraListaColisaoTiroTanque(std::list<Objeto*> &objetos);

        void atualizarTiros();
        void atualizarTirosPlayer();
        void atualizarTirosInimigos();
        void atualizarInsignia();
        void atualizarParedes();
        void atualizarPlayer();
        void atualizarInimigos();
        

        unsigned int pontos;

        std::list<std::shared_ptr<Objeto>> elementosTela;

        std::vector<allegro::Sprite4D*>spritesTanque;
        std::vector<allegro::Sprite4D*>spritesTanqueInimigos;
        std::vector<allegro::Sprite4D*>spritesTanquePlayer;
        
        bool vencido;

        const unsigned short int LIMITE_TIROS_PLAYER = 3;
        const unsigned short int LIMITE_INIMIGOS = 3;
        const unsigned short int MAX_TANQUES = 20;
        const unsigned short int LIMITE_TIROS_INIMIGOS = 3;
        
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