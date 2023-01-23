#ifndef OBJETO_HPP
#define OBJETO_HPP

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <list>

#include "Coordenada.hpp"
class Objeto {
    public:
        Objeto();
        Objeto(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite);

        virtual ~Objeto();

        const Coordenada* getCoordenada() const;
        void setCoordenada (const unsigned short int x, unsigned short int y);

        const std::list<ALLEGRO_BITMAP*>& getSprites() const;
        void adicionarSprite(const ALLEGRO_BITMAP* sprite);

        const unsigned int getTamanhoSprite() const;
        void setTamanhoSprite(unsigned short int);

    private:
        Coordenada *coordenada;
        std::list<ALLEGRO_BITMAP*>sprites;
        unsigned char tamanhoSprite;    

};

Objeto::Objeto(/* args */)
{
}

Objeto::~Objeto()
{
}


const Coordenada* Objeto::getCoordenada() const{}
void Objeto::setCoordenada (const unsigned short int x, unsigned short int y){}

const std::list<ALLEGRO_BITMAP*>& Objeto::getSprites() const{}
void Objeto::adicionarSprite(const ALLEGRO_BITMAP* sprite){}

const unsigned int Objeto::getTamanhoSprite() const{}
void Objeto::setTamanhoSprite(unsigned short int){}


#endif