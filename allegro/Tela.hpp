#ifndef TELA_HPP
#define TELA_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

#include <vector>

#include "Sprite.hpp"
#include "../Objeto.hpp"

namespace Allegro{

class Tela{
    public:
        ~Tela();
        Tela(Tela &outro) = delete;
        void operator=(const Tela &outro) = delete;

        static Tela *getInstancia();

        void desenharTela() const;
        void desenharSprite(const Allegro::Sprite* const spr, const float x, const float y) const;
        void limparTelaCor(const unsigned short int r, const unsigned short int g, const unsigned short int b) const;
        void desenharTexto(const std::string &texto);
        void desenharRetanguloCheio(const unsigned int x1, const unsigned int y1, const unsigned int x2, const unsigned int y2,
        const unsigned short int r, const unsigned short int g, const unsigned short int b, const float a) const;

        // define largura e altura do buffer intermediário do jogo
        static const unsigned int BUFFER_WIDTH = 256;
        static const unsigned int BUFFER_HEIGHT = 256;

    private:
        Tela();

        static Tela *instancia;

        ALLEGRO_DISPLAY* display;
        ALLEGRO_FONT* font;
        ALLEGRO_BITMAP* buffer;

        // define escala da janela do jogo em relação ao buffer intermediário
        static const unsigned int SCALE = 3;
        static const unsigned int DISPLAY_WIDTH = BUFFER_WIDTH * SCALE;
        static const unsigned int DISPLAY_HEIGHT = BUFFER_HEIGHT * SCALE;
};

};

#endif