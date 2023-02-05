#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "Allegro.hpp"
#include <iostream>
#include <vector>
#include <string>

ALLEGRO_DISPLAY* Allegro::display{nullptr};
ALLEGRO_FONT* Allegro::font{nullptr};
ALLEGRO_TIMER* Allegro::timer{nullptr};
ALLEGRO_EVENT Allegro::event;
ALLEGRO_EVENT_QUEUE* Allegro::queue{nullptr};
std::vector<unsigned char> Allegro::key(ALLEGRO_KEY_MAX, 0);

void Allegro::testInit(bool test, const std::string message)
// Testa retorno de função de inicialização do Allegro
{
    if (test) return;
    std::cerr << "Erro ao inicializar " << message << " :(\n";
    exit(1);
}

void Allegro::inicializar(){
    // Inicializa Allegro
    al_init();

    // inicializa fila de eventos
    Allegro::queue = al_create_event_queue();
    Allegro::testInit(Allegro::queue, static_cast<std::string>("fila de eventos"));

    // inicializa teclado
    Allegro::testInit(al_install_keyboard(), static_cast<std::string>("teclado"));

    // Inicializa fonte e display
    Allegro::display = al_create_display(640, 480);

    // inicializa timer de 1/FRAMERATE segundos
    Allegro::timer = al_create_timer(Allegro::FRAMERATE);
    Allegro::testInit(Allegro::timer, static_cast<std::string>("temporizador"));

    // inicializa variáveis de controle
    al_start_timer(Allegro::timer);

    Allegro::font = al_create_builtin_font();

    // registra teclado, display e timer como fontes de eventos da fila queue
    al_register_event_source(Allegro::queue, al_get_keyboard_event_source());
    al_register_event_source(Allegro::queue, al_get_display_event_source(Allegro::display));
    al_register_event_source(Allegro::queue, al_get_timer_event_source(Allegro::timer));
}

void Allegro::esvaziarFila(){
    al_flush_event_queue(Allegro::queue);
}

void Allegro::esperarEvento(){
    al_wait_for_event(Allegro::queue, &Allegro::event);
}

void Allegro::visualizarTeclas(){
    // seta todas as teclas como vistas
    for(int i = 0; i < ALLEGRO_KEY_MAX; ++i)
        Allegro::key[i] &= Allegro::KEY_SEEN;
}

void Allegro::pressionarTecla(){
    Allegro::key[Allegro::event.keyboard.keycode] = Allegro::KEY_SEEN | Allegro::KEY_RELEASED;
}

void Allegro::soltarTecla(){
    Allegro::key[Allegro::event.keyboard.keycode] &= KEY_RELEASED;
}

bool Allegro::sairJogo(){
    return Allegro::key[ALLEGRO_KEY_ESCAPE];
}

void Allegro::limparTelaCor(){ // n pode ser const
    al_clear_to_color(al_map_rgb(107, 63, 160));
}

void Allegro::desenharTexto(){ // n pode ser const
    al_draw_text(Allegro::font, al_map_rgb(0, 255, 0), 10, 10, 0, "Hello, world!");
}

void Allegro::trocarDisplay(){ // n pode ser const
    al_flip_display();
}

unsigned short int Allegro::getEvento(){
    if (Allegro::event.type == ALLEGRO_EVENT_TIMER) 
        return TEMPO_QUADRO;
    if (Allegro::event.type == ALLEGRO_EVENT_KEY_DOWN) 
        return TECLA_PRESSIONADA;
    if (Allegro::event.type == ALLEGRO_EVENT_KEY_UP) 
        return TECLA_SOLTA;
    return INDEFINIDO;
}

void Allegro::finalizar(){

    al_destroy_font(Allegro::font);
    al_destroy_display(Allegro::display);
    al_destroy_timer(Allegro::timer);
    al_destroy_event_queue(Allegro::queue);

}


