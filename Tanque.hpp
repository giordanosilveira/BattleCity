#ifndef TANQUE_HPP
#define TANQUE_HPP

#include "Objeto.hpp"
#include "Tiro.hpp"
#include <iostream>
#include <list>


class Tanque : public Objeto{

    friend void Tiro::setTanque(Tanque*tanque);

    public:
        Tanque();
        Tanque(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, const unsigned short imortal, const unsigned short estado, const unsigned short velocidade, const unsigned short direcao);
        virtual ~Tanque();

        void atirar();

    private:
        std::list<Tiro*>tiros;
        unsigned char velocidade;
        unsigned char direcao;
};

Tanque::Tanque(/* args */)
{
}

Tanque::~Tanque()
{
}



#endif