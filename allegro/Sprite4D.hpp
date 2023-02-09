#ifndef SPRITE_4D_HPP
#define SPRITE_4D_HPP

#include "Sprite.hpp"

namespace Allegro {
    class Sprite4D: public Allegro::Sprite {
        public:

            Sprite4D();
            Sprite4D(ALLEGRO_BITMAP* bitmapEsquerda, ALLEGRO_BITMAP* bitmapDireita, ALLEGRO_BITMAP* bitmapCima, ALLEGRO_BITMAP* bitmapBaixo);
            virtual ~Sprite4D();


            const ALLEGRO_BITMAP* getBitmapEsquerda() const;
            void setBitmapEsquerda(ALLEGRO_BITMAP* bitmapEsquerda);

            const ALLEGRO_BITMAP* getBitmapDireita() const;
            void setBitmapDireita(ALLEGRO_BITMAP* bitmapDireita);

            const ALLEGRO_BITMAP* getBitmapCima() const;
            void setBitmapCima(ALLEGRO_BITMAP* bitmapCima);

            const ALLEGRO_BITMAP* getBitmapBaixo() const;
            void setBitmapBaixo(ALLEGRO_BITMAP* bitmapBaixo);


        private:
            ALLEGRO_BITMAP *bitmapEsquerda;
            ALLEGRO_BITMAP *bitmapDireita;
            ALLEGRO_BITMAP *bitmapCima;
            ALLEGRO_BITMAP *bitmapBaixo;
        
    };
}


#endif