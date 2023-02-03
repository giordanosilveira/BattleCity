#ifndef PAREDE_HPP
#define PAREDE_HPP

#include "Objeto.hpp"

class Parede : public Objeto {
    public:
        
        Parede();
        Parede(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, const unsigned short imortal, const unsigned short estado, const unsigned short velocidade, const unsigned short direcao, unsigned short int vida);

        const unsigned short int getVida() const;
        void setVida (const unsigned short int vida);

        virtual ~Parede();
    private:
        unsigned char vida;
};

#endif