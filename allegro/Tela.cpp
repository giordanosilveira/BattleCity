#include "Tela.hpp"
#include "ControleJogo.hpp"
#include "Sprite.hpp"
#include "../Objeto.hpp"
#include "Util.hpp"

#include <allegro5/display.h>
#include <allegro5/allegro_primitives.h>

using namespace Allegro;

Tela *Tela::instancia{nullptr};

Tela::Tela(){
    // Inicializa fonte e display
    this->font = al_create_builtin_font();
    Util::testInit((this->font != NULL), "Fonte");
    
    this->display = al_create_display(Tela::DISPLAY_WIDTH, Tela::DISPLAY_HEIGHT);
    Util::testInit((this->display != NULL), "Display");

    this->buffer = al_create_bitmap(Tela::BUFFER_WIDTH, Tela::BUFFER_HEIGHT);
    Util::testInit(this->buffer, "buffer intermediario");

    Util::testInit(al_init_image_addon(), "addon de imagem");
    Util::testInit(al_init_primitives_addon(), "addon de primitivos");

    al_set_target_bitmap(this->buffer);

    ControleJogo *al = ControleJogo::getInstancia();
    al->registrarTela(this->display);

}

Tela::~Tela(){
    al_destroy_font(this->font);
    al_destroy_display(this->display);
    al_shutdown_primitives_addon();
}

Tela *Tela::getInstancia(){
    if (Tela::instancia == nullptr)
        Tela::instancia = new Tela();
    return Tela::instancia;
}

void Tela::limparTelaCor(const unsigned short int r, const unsigned short int g, const unsigned short int b) const{ 
    al_clear_to_color(al_map_rgb(r, g, b));
}

void Tela::desenharTexto(const std::string &texto){ 
    al_draw_text(this->font, al_map_rgb(0, 255, 255), 10, 10, 0, texto.c_str());
}   

void Tela::desenharSprite(const Allegro::Sprite* const spr, const float x, const float y) const{
    al_draw_bitmap(spr->getBitmap(), x, y, 0);
}

void Tela::desenharRetanguloCheio(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2,
        const unsigned short int r, const unsigned short int g, const unsigned short int b, const float a) const{
    al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgba_f(r, g, b, a));
}

void Tela::desenharTela() const {

    al_set_target_backbuffer(this->display);
    al_draw_scaled_bitmap(this->buffer,
                          0, 0, Tela::BUFFER_WIDTH, Tela::BUFFER_HEIGHT, 
                          0, 0, Tela::DISPLAY_WIDTH, Tela::DISPLAY_HEIGHT, 0);

    al_flip_display();
    al_set_target_bitmap(this->buffer);

}
