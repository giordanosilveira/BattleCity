#ifndef TIRO_HPP
#define TIRO_HPP

#include "Objeto.hpp"
#include "Tanque.hpp"

class Tanque;

class Tiro : public Objeto{
    public:
        Tiro();
        Tiro(const unsigned int x, const unsigned int y, const unsigned short tamanhoSprite, const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short velocidade, EnumDirecao direcao);
        
        virtual ~Tiro();

        void setTanque(Tanque *tanque);


    private:
        Tanque *tanque;

        
};

#endif