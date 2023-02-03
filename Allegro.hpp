#ifndef ALLEGRO_HPP
#define ALLEGRO_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <vector>
#include <string>

class Allegro{
    public:
        Allegro() = delete;

        static constexpr double FRAMERATE = 1.0/60.0;
        static const unsigned int KEY_SEEN = 1;
        static const unsigned int KEY_RELEASED = 2;

        static void inicializar();
        static unsigned short int getEvento();
        static void esperarEvento();

        static void visualizarTeclas();
        static void pressionarTecla();
        static void soltarTecla();

        static void limparTelaCor();
        static void desenharTexto();
        static void trocarDisplay();

        static void esvaziarFila();

        static bool sairJogo();
        static void finalizar();
        
        enum evento{
            TEMPO_QUADRO,
            TECLA_PRESSIONADA,
            TECLA_SOLTA,
            INDEFINIDO
        };


    private:

        static ALLEGRO_DISPLAY* display;
        static ALLEGRO_FONT* font;
        static ALLEGRO_TIMER* timer;
        static ALLEGRO_EVENT event;
        static ALLEGRO_EVENT_QUEUE* queue;

        static std::vector<unsigned char> key;

        static void testInit(bool test, const std::string message);
};

#endif