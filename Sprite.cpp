#include <string>

#include "AllegroInitException.hpp"
#include "Sprite.hpp"

using namespace Allegro;

// TODO: MUITO FEIO, FAZER CLASSE SEPARADA PARA O TESTINIT
void testInit(bool test, const std::string message)
// Testa retorno de função de inicialização do Allegro
{
    if (test) return;
    throw AllegroInitException();
}

Sprite::Sprite(const std::string &fileName){
    this->bitmap = al_load_bitmap("resources/sprites/tileset.png");
    testInit((this->bitmap != NULL), static_cast<std::string>("spritesheet"));
}

Sprite::Sprite(const Sprite &sprite, int inicioX, int inicioY, int larg, int alt){
    this->bitmap = al_create_sub_bitmap(sprite.bitmap, inicioX, inicioY, larg, alt);
    testInit(this->bitmap, "algum dos sprites");
}

Sprite::~Sprite(){
    al_destroy_bitmap(this->bitmap);
}