#ifndef TIRO_HPP
#define TIRO_HPP

#include "Objeto.hpp"
#include "allegro/Sprite4D.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"


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
            allegro::Sprite4D* const &sprites,
            const unsigned int direcao_tiro);
        
        virtual ~Tiro();

        void mover(std::list<Objeto*> objetos);


        allegro::Sprite4D *sprites;

        
};

#endif