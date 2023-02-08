#ifndef TELA_HPP
#define TELA_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

#include "Sprite.hpp"

namespace Allegro{

class Tela{
    public:
        ~Tela();
        Tela(Tela &outro) = delete;
        void operator=(const Tela &outro) = delete;

        static Tela *getInstancia();

        void desenharTela();
        void desenharSprite(Allegro::Sprite *spr, float x, float y) const;
        void limparTelaCor();
        void desenharTexto(const std::string &texto);

    private:
        Tela();

        static Tela *instancia;

        ALLEGRO_DISPLAY* display;
        ALLEGRO_FONT* font;
        ALLEGRO_BITMAP* buffer;

        // define largura e altura do buffer intermediário do jogo
        static const unsigned int BUFFER_WIDTH = 480;
        static const unsigned int BUFFER_HEIGHT = 288;

        // define escala da janela do jogo em relação ao buffer intermediário
        static const unsigned int SCALE = 3;
        static const unsigned int DISPLAY_WIDTH = BUFFER_WIDTH * SCALE;
        static const unsigned int DISPLAY_HEIGHT = BUFFER_HEIGHT * SCALE;
};

};

#endif