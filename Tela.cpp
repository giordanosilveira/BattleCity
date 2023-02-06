#include "Tela.hpp"
#include "ControleJogo.hpp"
#include "Sprite.hpp"

#include "Util.hpp"
#include <allegro5/display.h>

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

    al_set_target_bitmap(this->buffer);

    ControleJogo *al = ControleJogo::getInstancia();
    al->registrarTela(this->display);

}

Tela::~Tela(){
    al_destroy_font(this->font);
    al_destroy_display(this->display);
}

Tela *Tela::getInstancia(){
    if (Tela::instancia == nullptr)
        Tela::instancia = new Tela();
    return Tela::instancia;
}

void Tela::limparTelaCor(){ // n pode ser const
    al_clear_to_color(al_map_rgb(20, 20, 20));
}

void Tela::desenharTexto(const std::string &texto){ // n pode ser const
    al_draw_text(this->font, al_map_rgb(0, 255, 255), 10, 10, 0, texto.c_str());
}   

void Tela::desenharSprite(Allegro::Sprite *spr, float x, float y) const{
    al_draw_bitmap(spr->getBitmap(), x, y, 0);
}

void Tela::desenharTela() {

    al_set_target_backbuffer(this->display);
    al_draw_scaled_bitmap(this->buffer,
                          0, 0, Tela::BUFFER_WIDTH, Tela::BUFFER_HEIGHT, 
                          0, 0, Tela::DISPLAY_WIDTH, Tela::DISPLAY_HEIGHT, 0);

    al_flip_display();
    al_set_target_bitmap(this->buffer);

}
