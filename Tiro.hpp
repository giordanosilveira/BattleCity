#ifndef TIRO_HPP
#define TIRO_HPP

#include "Objeto.hpp"
#include "Tanque.hpp"

class Tanque;

class Tiro : public Objeto{
    public:
        Tiro();
        Tiro(const unsigned int x, const unsigned int y, const unsigned short int tamanhoSprite, const unsigned short imortal, const unsigned short estado, const unsigned short int velocidade, const unsigned short int direcao);
        virtual ~Tiro();

        void setTanque(Tanque *tanque);

        // virtual const bool colisao(std::list<Objeto*>& objeto) const override; 

        // virtual void setDirecao() override; 

    private:
        Tanque *tanque;

        
};

#endif