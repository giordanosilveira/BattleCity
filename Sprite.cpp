#include <allegro5/allegro_image.h>
#include <iostream>

#include <string>

#include "AllegroInitException.hpp"
#include "Sprite.hpp"

using namespace Allegro;


// TODO: MUITO FEIO, FAZER CLASSE SEPARADA PARA O TESTINIT
void testInit(bool test, const std::string &message)
// Testa retorno de função de inicialização do Allegro
{
    if (test) return;
    throw AllegroInitException(message);
}

Sprite::Sprite()
        :bitmap{nullptr}{
}

Sprite::Sprite(const std::string &fileName){
    this->bitmap = al_load_bitmap(fileName.c_str());
    testInit((this->bitmap != NULL), "spritesheet");
}

Sprite::Sprite(const Sprite *sprite, int inicioX, int inicioY, int larg, int alt)
        :bitmap{al_create_sub_bitmap(sprite->bitmap, inicioX, inicioY, larg, alt)}{
    testInit((this->bitmap != NULL), "sprite");
}

Sprite::~Sprite(){
    al_destroy_bitmap(this->bitmap);
}

ALLEGRO_BITMAP *Sprite::getBitmap() const{
    return this->bitmap;
}
