#ifndef SPRITE_4D_HPP
#define SPRITE_4D_HPP

#include "Sprite.hpp"

namespace Allegro {
    class Sprite4D: public Allegro::Sprite {
        public:

            Sprite4D();
            // Sprite4D(Sprite* bitmapEsquerda, Sprite* bitmapBaixo, Sprite* bitmapDireita, Sprite* bitmapCima);
            virtual ~Sprite4D();

            enum direcao{
                CIM = 0,
                ESQ,
                BAI,
                DIR
            };

            void inicializarSprite(const Sprite* const sprite, const unsigned int inicioX, const unsigned int inicioY, const unsigned int larg, const unsigned int alt, const int direcao);

            ALLEGRO_BITMAP* getBitmapPrincipal() const;
            void setSpritePrincipal(const int direcao);

            // const ALLEGRO_BITMAP* getBitmapEsquerda() const;
            // void setBitmapEsquerda(ALLEGRO_BITMAP* bitmapEsquerda);

            // const ALLEGRO_BITMAP* getBitmapBaixo() const;
            // void setBitmapBaixo(ALLEGRO_BITMAP* bitmapBaixo);

            // const ALLEGRO_BITMAP* getBitmapDireita() const;
            // void setBitmapDireita(ALLEGRO_BITMAP* bitmapDireita);

            // const ALLEGRO_BITMAP* getBitmapCima() const;
            // void setBitmapCima(ALLEGRO_BITMAP* bitmapCima);

        private:
            ALLEGRO_BITMAP *bitmapEsquerda;
            ALLEGRO_BITMAP *bitmapBaixo;
            ALLEGRO_BITMAP *bitmapDireita;
            ALLEGRO_BITMAP *bitmapCima;
        
    };
}


#endif