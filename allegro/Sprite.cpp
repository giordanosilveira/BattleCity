#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>
#include <iostream>

#include <string>

#include "AllegroInitException.hpp"
#include "Sprite.hpp"
#include "Util.hpp"

using namespace Allegro;


Sprite::Sprite()
        :bitmap{nullptr}{
}

Sprite::Sprite(const std::string &fileName){
    this->bitmap = al_load_bitmap(fileName.c_str());
    Util::testInit((this->bitmap != NULL), "spritesheet");
}

Sprite::Sprite(const Sprite *sprite, const unsigned int inicioX, const unsigned int inicioY, const unsigned int larg, const unsigned int alt)
        :bitmap{al_create_sub_bitmap(sprite->bitmap, inicioX, inicioY, larg, alt)}{
    Util::testInit((this->bitmap != NULL), "sprite");
}

Sprite::~Sprite(){
    al_destroy_bitmap(this->bitmap);
}

void Sprite::setBitmap(ALLEGRO_BITMAP * const bitmap){
    this->bitmap = bitmap;
}

ALLEGRO_BITMAP *Sprite::getBitmap() const{
    return this->bitmap;
}
