#include <allegro5/allegro.h>
#include <allegro5/events.h>
#include <stdlib.h>

#include "ControleJogo.hpp"
#include "AllegroInitException.hpp"
#include "Util.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace Allegro;

ControleJogo* ControleJogo::instancia{nullptr};

ControleJogo::ControleJogo(){

    // Inicializa ControleJogo
    al_init();

    // inicializa fila de eventos
    this->queue = al_create_event_queue();
    Util::testInit((this->queue != NULL), static_cast<std::string>("fila de eventos"));

    // inicializa teclado
    Util::testInit(al_install_keyboard(), static_cast<std::string>("teclado"));

    // inicializa timer de 1/FRAMERATE segundos
    this->timer = al_create_timer(this->FRAMERATE);
    Util::testInit((this->timer != NULL), static_cast<std::string>("temporizador"));

    // inicializa variáveis de controle
    al_start_timer(this->timer);

    // registra teclado, display e timer como fontes de eventos da fila queue
    al_register_event_source(this->queue, al_get_keyboard_event_source());
    al_register_event_source(this->queue, al_get_timer_event_source(this->timer));

    this->key.resize(ALLEGRO_KEY_MAX, 0);

    this->instancia = nullptr;
}

void ControleJogo::registrarTela(ALLEGRO_DISPLAY *display){
    al_register_event_source(this->queue, al_get_display_event_source(display));
}


ControleJogo *ControleJogo::getInstancia(){
    if (ControleJogo::instancia == nullptr)
        ControleJogo::instancia = new ControleJogo();
    return ControleJogo::instancia;
}

void ControleJogo::esvaziarFila(){
    al_flush_event_queue(this->queue);
}

void ControleJogo::esperarEvento(){
    al_wait_for_event(this->queue, &this->event);
}

void ControleJogo::visualizarTeclas(){
    // seta todas as teclas como vistas
    for(int i = 0; i < ALLEGRO_KEY_MAX; ++i)
        this->key[i] &= this->KEY_SEEN;
}

void ControleJogo::pressionarTecla(){
    this->key[this->event.keyboard.keycode] = this->KEY_SEEN | this->KEY_RELEASED;
}

void ControleJogo::soltarTecla(){
    this->key[this->event.keyboard.keycode] &= KEY_RELEASED;
}

bool ControleJogo::sairJogo(){
    return this->key[ALLEGRO_KEY_ESCAPE] || (this->event.type == ALLEGRO_EVENT_DISPLAY_CLOSE);
}

unsigned short int ControleJogo::getEvento(){
    if (this->event.type == ALLEGRO_EVENT_TIMER) 
        return TEMPO_QUADRO;
    if (this->event.type == ALLEGRO_EVENT_KEY_DOWN) 
        return TECLA_PRESSIONADA;
    if (this->event.type == ALLEGRO_EVENT_KEY_UP) 
        return TECLA_SOLTA;
    return INDEFINIDO;
}

ControleJogo::~ControleJogo(){
    al_destroy_timer(this->timer);
    al_destroy_event_queue(this->queue);
}

ALLEGRO_BITMAP* ControleJogo::carregarSpritesheet(const std::string &nomeArquivo){
    ALLEGRO_BITMAP* spritesheet;

    spritesheet = al_load_bitmap(nomeArquivo.c_str());
    Util::testInit((spritesheet != NULL), "spritesheet");

    return spritesheet;
}

ALLEGRO_BITMAP *ControleJogo::pegarSprite(ALLEGRO_BITMAP *sheet, int x, int y, int w, int h)
// carrega sprite de sheet e aborta em caso de erro
{
    ALLEGRO_BITMAP *sprite = al_create_sub_bitmap(sheet, x, y, w, h);
    Util::testInit(sprite, "algum dos sprites");
    return sprite;
}

bool ControleJogo::teclaPressionada(const unsigned short int tecla){
    return this->key[tecla];
}
