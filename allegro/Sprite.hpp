#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <allegro5/allegro5.h>
#include <string>

namespace allegro{
class Sprite {
    public:
        Sprite();
        Sprite(const std::string &fileName);
        Sprite(const Sprite *sprite, const unsigned int inicioX, const unsigned int inicioY, const unsigned int larg, const unsigned int alt);
        ~Sprite();

        
        ALLEGRO_BITMAP *getBitmap() const;


    protected:
        void setBitmap(ALLEGRO_BITMAP* const bitmap);
        ALLEGRO_BITMAP *bitmap; 
};
}
#endif
