#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "Estado.hpp"

short int Estado::atual = Estado::INICIALIZAR;

ALLEGRO_DISPLAY* disp;
ALLEGRO_FONT* font;

void Estado::inicializar(){
    // Inicializa Allegro
    al_init();
    
    // Inicializa fonte e display
    disp = al_create_display(640, 480);
    font = al_create_builtin_font();

    Estado::atual = Estado::JOGO;
}

void Estado::jogo(){

    al_clear_to_color(al_map_rgb(107, 63, 160));
    al_draw_text(font, al_map_rgb(0, 255, 0), 10, 10, 0, "Hello, world!");
    al_flip_display();

}

void Estado::encerrar(){

    al_destroy_font(font);
    al_destroy_display(disp);

}
