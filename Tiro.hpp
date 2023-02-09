#ifndef TIRO_HPP
#define TIRO_HPP

#include "Objeto.hpp"
#include "Tanque.hpp"

class Tanque;

class Tiro : public Objeto{
    public:
        Tiro();
        Tiro(
            const unsigned int x, 
            const unsigned int y, 
            const unsigned short int tamanhoSprite, 
            const unsigned short imortal, 
            EnumEstadoObjeto estado, 
            const unsigned short vida,
            const unsigned short velocidade, 
            EnumDirecao direcao,
            Allegro::Sprite4D* const &sprites);
        
        virtual ~Tiro();

        void setTanque(Tanque *tanque);


    private:
        Tanque *tanque;
        Allegro::Sprite4D *sprites;

        
};

#endif