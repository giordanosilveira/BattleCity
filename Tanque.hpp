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

        virtual void atirar();

        virtual void mover();

        virtual void setDirecao();

    private:
        std::list<Tiro*>tiros;
        unsigned char velocidade;
        unsigned char direcao;
};

Tanque::Tanque(){}

Tanque::Tanque(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, const unsigned short imortal, const unsigned short estado, const unsigned short velocidade, const unsigned short direcao){}

Tanque::~Tanque()
{
}



#endif