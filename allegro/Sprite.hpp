#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <allegro5/allegro5.h>
#include <string>

namespace Allegro{
class Sprite {
    public:
        Sprite();
        Sprite(const std::string &fileName);
        Sprite(const Sprite *sprite, const unsigned int inicioX, const unsigned int inicioY, const unsigned int larg, const unsigned int alt);
        ~Sprite();

        
        ALLEGRO_BITMAP *getBitmap() const; // TODO mudar pra const (acho que não da por conta das funções do allegro)


    protected:
        void setBitmap(ALLEGRO_BITMAP* const bitmap);
        ALLEGRO_BITMAP *bitmap; 
};
}
#endif
