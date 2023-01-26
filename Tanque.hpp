#ifndef TANQUE_HPP
#define TANQUE_HPP

#include "Objeto.hpp"
#include "Tiro.hpp"
#include <iostream>
#include <list>

class Tanque : public Objeto{
    public:
        Tanque(/* args */);
        ~Tanque();
    
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