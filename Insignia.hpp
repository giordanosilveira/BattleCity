#ifndef INSIGNIA_HPP
#define INSIGNIA_HPP

#include "Objeto.hpp"
#include "allegro/Sprite.hpp"

class Insignia : public Objeto {

    public:
        Insignia(const unsigned int x, const unsigned int y, const unsigned short int tamanhoSprite, const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, EnumDirecao direcao, allegro::Sprite *spriteVivo, allegro::Sprite *spriteMorto);
        
        void atualizarSprite();

    private:
        allegro::Sprite *spriteVivo;
        allegro::Sprite *spriteMorto;

};


#endif