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

        static constexpr double FRAMERATE = 1.0/60.0;
        static const unsigned int KEY_SEEN = 1;
        static const unsigned int KEY_RELEASED = 2;

        /* ===== AÇÕES DE CONTROLE DO JOGO ===== */
        void inicializar();

        /*
            Testa se foi feita uma ação para sair imediatamente do jogo
        */
        bool sairJogo();
        void finalizar();

        /* ===== MÉTODOS DE FILA DE EVENTOS ===== */
        unsigned short int getEvento();
        void esperarEvento();
        void esvaziarFila();

        /* ===== MÉTODOS DE TECLADO ===== */
        void visualizarTeclas();
        void pressionarTecla();
        void soltarTecla();

        void registrarTela(ALLEGRO_DISPLAY *display);

        ALLEGRO_BITMAP* carregarSpritesheet(const std::string &nomeArquivo);
        ALLEGRO_BITMAP *pegarSprite(ALLEGRO_BITMAP *sheet, int x, int y, int w, int h);
        
        enum evento{
            TEMPO_QUADRO,
            TECLA_PRESSIONADA,
            TECLA_SOLTA,
            INDEFINIDO
        };


    private:
        ControleJogo();
        static ControleJogo *instancia;

        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT event;
        ALLEGRO_EVENT_QUEUE* queue;

        std::vector<unsigned char> key;

        void testInit(bool test, const std::string message);
};

}
#endif