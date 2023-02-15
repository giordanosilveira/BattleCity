#ifndef PAREDE_HPP
#define PAREDE_HPP

#include "Objeto.hpp"

class Parede : public Objeto {
    public:
        
        Parede();
        Parede(const unsigned int x, const unsigned int y, const unsigned short int tamanhoSprite, const unsigned short int imortal, EnumEstadoObjeto estado, const unsigned short int velocidade, const unsigned short int vida, EnumDirecao direcao,  const allegro::Sprite *sprite);

        virtual ~Parede();
};

#endif