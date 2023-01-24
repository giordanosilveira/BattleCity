#ifndef OBJETO_HPP
#define OBJETO_HPP

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <vector>

#include "Coordenada.hpp"
class Objeto {
    public:
        /**
         * @brief Construtor padrão.
         */
        Objeto();

        /**
         * @param x (unsigned int) : ponto x.
         * @param y (unsigned int) : ponto y.
         * @param tamanhoSprite x (unsigned short int) : tamanho da sprite.
         */
        Objeto(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite);

        /**
         * @brief Destrutor
         */
        virtual ~Objeto();

        /**
         * @brief Retorna o ponteiro da coordenada.
         * @return (const Coordenada*) : Ponteiro da coordenada 
         */
        const Coordenada* getCoordenada() const;

        /**
         * @brief atualiza o ponto x e y da coordenada.
         * @param x (short int) : Coordenada x.
         * @param y (short int) : Coordenada y.
         */
        void setCoordenada (const unsigned short int x, unsigned short int y);

        /**
         * @brief Retorna a sprite do vetor na posição index.
         * É lançado um out_of_range caso de erro.
         * 
         * @param index (int) : Uma posição do vetor.
         * @return (const ALLEGRO_BITMAP*) : Uma sprite do vetor. 
         */
        const ALLEGRO_BITMAP* getSprite(const int index) const;

        /**
         * @brief Adiciona uma sprite na lista de sprites
         * 
         * @param sprite (ALLEGRO_BITMAP*) : Sprite a ser adicionada.
         * @param qtdSprites (int) : variável para ser usada para lançar um erro.
         */
        void adicionarSprite(ALLEGRO_BITMAP* sprite, const int qtdSprites);

        /**
         * @brief Retorna o tamanho da sprite
         * @return (unsigned short int) : tamanho da sprite.
         */
        const unsigned short int getTamanhoSprite() const;

        /**
         * @brief Define o tamanho da sprite
         * @param (unsigned short int) : tamanho da sprite. 
         */
        void setTamanhoSprite(unsigned short int);

    private:
        Coordenada *coordenada;
        std::vector<ALLEGRO_BITMAP*>sprites;
        unsigned char tamanhoSprite;    

};

#endif