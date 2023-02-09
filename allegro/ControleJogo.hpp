#ifndef ALLEGRO_HPP
#define ALLEGRO_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <vector>
#include <string>

#include "Sprite.hpp"

namespace Allegro{

// Utiliza padrão singleton 
class ControleJogo{
    public:
        ~ControleJogo();
        ControleJogo(ControleJogo &outro) = delete;
        void operator=(const ControleJogo &outro) = delete;

        static ControleJogo *getInstancia();

        static constexpr double FRAMERATE = 1.0/30.0;
        static const unsigned int KEY_SEEN = 1;
        static const unsigned int KEY_RELEASED = 2;

        /* ===== AÇÕES DE CONTROLE DO JOGO ===== */

        /*
            Testa se foi feita uma ação para sair imediatamente do jogo
        */
        bool sairJogo() const;

        /* ===== MÉTODOS DE FILA DE EVENTOS ===== */
        unsigned short int getEvento() const;
        void esperarEvento();
        void esvaziarFila();

        /* ===== MÉTODOS DE TECLADO ===== */
        void visualizarTeclas();
        void pressionarTecla();
        void soltarTecla();
        bool teclaPressionada(const unsigned short int tecla) const;

        void registrarTela(ALLEGRO_DISPLAY *display);

        ALLEGRO_BITMAP* carregarSpritesheet(const std::string &nomeArquivo);
        ALLEGRO_BITMAP* pegarSprite(ALLEGRO_BITMAP *sheet, const unsigned int x, const unsigned int y, const unsigned int w, const unsigned int h);
        

        enum evento{
            TEMPO_QUADRO,
            TECLA_PRESSIONADA,
            TECLA_SOLTA,
            INDEFINIDO
        };

        enum tecla{
            SETA_ESQUERDA = ALLEGRO_KEY_LEFT,
            SETA_DIREITA,
            SETA_CIMA,
            SETA_BAIXO
        };

    private:
        ControleJogo();
        static ControleJogo *instancia;

        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT event;
        ALLEGRO_EVENT_QUEUE* queue;

        std::vector<unsigned char> key;

};

}
#endif