#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/events.h>
#include <stdlib.h>

#include "ControleJogo.hpp"
#include "AllegroInitException.hpp"


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
    this->testInit((this->queue != NULL), static_cast<std::string>("fila de eventos"));

    // inicializa teclado
    this->testInit(al_install_keyboard(), static_cast<std::string>("teclado"));

    // Inicializa fonte e display
    this->font = al_create_builtin_font();
    this->testInit((this->font != NULL), "Fonte");
    
    this->display = al_create_display(640, 480);
    this->testInit((this->display != NULL), "Display");

    // inicializa timer de 1/FRAMERATE segundos
    this->timer = al_create_timer(this->FRAMERATE);
    this->testInit((this->timer != NULL), static_cast<std::string>("temporizador"));

    // inicializa variáveis de controle
    al_start_timer(this->timer);

    // registra teclado, display e timer como fontes de eventos da fila queue
    al_register_event_source(this->queue, al_get_keyboard_event_source());
    al_register_event_source(this->queue, al_get_display_event_source(this->display));
    al_register_event_source(this->queue, al_get_timer_event_source(this->timer));

    this->key.resize(ALLEGRO_KEY_MAX, 0);

    this->instancia = nullptr;
}

ControleJogo *ControleJogo::getInstancia(){
    if (ControleJogo::instancia == nullptr)
        ControleJogo::instancia = new ControleJogo();
    return ControleJogo::instancia;
}

void ControleJogo::testInit(bool test, const std::string message)
// Testa retorno de função de inicialização do ControleJogo
{
    if (test) return;
    throw AllegroInitException();
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

void ControleJogo::limparTelaCor(){ // n pode ser const
    al_clear_to_color(al_map_rgb(107, 63, 160));
}

void ControleJogo::desenharTexto(){ // n pode ser const
    al_draw_text(this->font, al_map_rgb(0, 255, 0), 10, 10, 0, "Hello, world!");
}

void ControleJogo::trocarDisplay(){ // n pode ser const
    al_flip_display();
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
    al_destroy_font(this->font);
    al_destroy_display(this->display);
    al_destroy_timer(this->timer);
    al_destroy_event_queue(this->queue);
}

ALLEGRO_BITMAP* ControleJogo::carregarSpritesheet(const std::string &nomeArquivo){
    ALLEGRO_BITMAP* spritesheet;

    spritesheet = al_load_bitmap(nomeArquivo.c_str());
    this->testInit((spritesheet != NULL), "spritesheet");

    return spritesheet;
}

ALLEGRO_BITMAP *ControleJogo::pegarSprite(ALLEGRO_BITMAP *sheet, int x, int y, int w, int h)
// carrega sprite de sheet e aborta em caso de erro
{
    ALLEGRO_BITMAP *sprite = al_create_sub_bitmap(sheet, x, y, w, h);
    this->testInit(sprite, "algum dos sprites");
    return sprite;
}


