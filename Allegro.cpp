#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <stdlib.h>

#include "Allegro.hpp"
#include "AllegroInitException.hpp"


#include <iostream>
#include <vector>
#include <string>

// ALLEGRO_DISPLAY* Allegro::display{nullptr};
// ALLEGRO_FONT* Allegro::font{nullptr};
// ALLEGRO_TIMER* Allegro::timer{nullptr};
// ALLEGRO_EVENT Allegro::event;
// ALLEGRO_EVENT_QUEUE* Allegro::queue{nullptr};


Allegro* Allegro::instancia{nullptr};

Allegro::Allegro(){

    // Inicializa Allegro
    al_init();

    // inicializa fila de eventos
    this->queue = al_create_event_queue();
    this->testInit(this->queue, static_cast<std::string>("fila de eventos"));

    // inicializa teclado
    this->testInit(al_install_keyboard(), static_cast<std::string>("teclado"));

    // Inicializa fonte e display
    this->display = al_create_display(640, 480);

    // inicializa timer de 1/FRAMERATE segundos
    this->timer = al_create_timer(this->FRAMERATE);
    this->testInit(this->timer, static_cast<std::string>("temporizador"));

    // inicializa variáveis de controle
    al_start_timer(this->timer);

    this->font = al_create_builtin_font();

    // registra teclado, display e timer como fontes de eventos da fila queue
    al_register_event_source(this->queue, al_get_keyboard_event_source());
    al_register_event_source(this->queue, al_get_display_event_source(this->display));
    al_register_event_source(this->queue, al_get_timer_event_source(this->timer));

    this->key.resize(ALLEGRO_KEY_MAX, 0);

    this->instancia = nullptr;
}

Allegro *Allegro::getInstancia(){
    if (Allegro::instancia == nullptr)
        Allegro::instancia = new Allegro();
    return Allegro::instancia;
}

void Allegro::testInit(bool test, const std::string message)
// Testa retorno de função de inicialização do Allegro
{
    if (test) return;
    throw AllegroInitException();
}

void Allegro::esvaziarFila(){
    al_flush_event_queue(this->queue);
}

void Allegro::esperarEvento(){
    al_wait_for_event(this->queue, &this->event);
}

void Allegro::visualizarTeclas(){
    // seta todas as teclas como vistas
    for(int i = 0; i < ALLEGRO_KEY_MAX; ++i)
        this->key[i] &= this->KEY_SEEN;
}

void Allegro::pressionarTecla(){
    this->key[this->event.keyboard.keycode] = this->KEY_SEEN | this->KEY_RELEASED;
}

void Allegro::soltarTecla(){
    this->key[this->event.keyboard.keycode] &= KEY_RELEASED;
}

bool Allegro::sairJogo(){
    return this->key[ALLEGRO_KEY_ESCAPE];
}

void Allegro::limparTelaCor(){ // n pode ser const
    al_clear_to_color(al_map_rgb(107, 63, 160));
}

void Allegro::desenharTexto(){ // n pode ser const
    al_draw_text(this->font, al_map_rgb(0, 255, 0), 10, 10, 0, "Hello, world!");
}

void Allegro::trocarDisplay(){ // n pode ser const
    al_flip_display();
}

unsigned short int Allegro::getEvento(){
    if (this->event.type == ALLEGRO_EVENT_TIMER) 
        return TEMPO_QUADRO;
    if (this->event.type == ALLEGRO_EVENT_KEY_DOWN) 
        return TECLA_PRESSIONADA;
    if (this->event.type == ALLEGRO_EVENT_KEY_UP) 
        return TECLA_SOLTA;
    return INDEFINIDO;
}

Allegro::~Allegro(){

    al_destroy_font(this->font);
    al_destroy_display(this->display);
    al_destroy_timer(this->timer);
    al_destroy_event_queue(this->queue);

}

ALLEGRO_BITMAP* Allegro::carregarSpritesheet(const std::string &nomeArquivo){
    bool test = true;
    ALLEGRO_BITMAP* spritesheet;

    spritesheet = al_load_bitmap(nomeArquivo.c_str());
    if (spritesheet == NULL) test = false;
    this->testInit(test, "spritesheet");

    return spritesheet;
}

ALLEGRO_BITMAP *Allegro::pegarSprite(ALLEGRO_BITMAP *sheet, int x, int y, int w, int h)
// carrega sprite de sheet e aborta em caso de erro
{
    ALLEGRO_BITMAP *sprite = al_create_sub_bitmap(sheet, x, y, w, h);
    this->testInit(sprite, "algum dos sprites");
    return sprite;
}


