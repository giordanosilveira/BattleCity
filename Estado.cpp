#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include <vector>
#include <string>
#include <iostream>

#include "Estado.hpp"

short int Estado::atual = Estado::INICIALIZAR;

ALLEGRO_DISPLAY* disp;
ALLEGRO_FONT* font;
ALLEGRO_TIMER* timer;
ALLEGRO_EVENT event;
ALLEGRO_EVENT_QUEUE* queue;


const unsigned int KEY_SEEN = 1;
const unsigned int KEY_RELEASED = 2;
const double FRAMERATE = 1.0/60.0;
std::vector<unsigned char> key(ALLEGRO_KEY_MAX, 0);

void test_init(bool test, const std::string message)
// Testa retorno de função de inicialização do Allegro
{
    if (test) return;
    std::cerr << "Erro ao inicializar " << message << " :(\n";
    exit(1);
}

void Estado::inicializar(){
    // Inicializa Allegro
    al_init();

    // inicializa fila de eventos
    queue = al_create_event_queue();
    test_init(queue, "fila de eventos");

    // inicializa teclado
    test_init(al_install_keyboard(), "teclado");

    // Inicializa fonte e display
    disp = al_create_display(640, 480);

    // inicializa timer de 1/FRAMERATE segundos
    timer = al_create_timer(FRAMERATE);
    test_init(timer, "temporizador");

    // inicializa variáveis de controle
    al_start_timer(timer);

    font = al_create_builtin_font();

    // registra teclado, display e timer como fontes de eventos da fila queue
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    Estado::atual = Estado::JOGO;
}

void Estado::jogo(){
    bool done = false;
    unsigned int x = 0, y = 0;

    al_flush_event_queue(queue);
    for (;;){
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER){
            // seta todas as teclas como vistas
            for(int i = 0; i < ALLEGRO_KEY_MAX; ++i)
                key[i] &= KEY_SEEN;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_DOWN){
            key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
        }
        else if (event.type == ALLEGRO_EVENT_KEY_UP){
            key[event.keyboard.keycode] &= KEY_RELEASED;
        }

        if (key[ALLEGRO_KEY_ESCAPE] ){ // Jogador apertou esc
            done = true;
            Estado::atual = Estado::ENCERRAR;
        }

        if (done) break;

        al_clear_to_color(al_map_rgb(107, 63, 160));
        al_draw_text(font, al_map_rgb(0, 255, 0), x++, y++, 0, "Hello, world!");
        al_flip_display();
    }

}

void Estado::encerrar(){
    al_destroy_font(font);
    al_destroy_display(disp);

    exit(0);
}
