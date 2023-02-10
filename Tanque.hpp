#ifndef TANQUE_HPP
#define TANQUE_HPP

#include "Objeto.hpp"
#include "allegro/Sprite.hpp"
#include "allegro/Sprite4D.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include <iostream>
#include <list>

#include "Tiro.hpp"

// class Tiro;

class Tanque : public Objeto{

    friend void Tiro::setTanque(Tanque*tanque);

    public:
        Tanque();
        Tanque(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, EnumDirecao direcao, Allegro::Sprite4D* const &sprites, Allegro::Sprite4D* const &tiroSprites);
        
        virtual ~Tanque();

        // virtual void mover();

        virtual Tiro* const atirar(unsigned short int tamanhoTiro);

        // virtual void setDirecao(EnumDirecao direcao);

        // virtual const bool colisao(std::list<Objeto*>&objeto) const;// override;

        const Allegro::Sprite* getSprite() const;
        void setSprite(Allegro::Sprite4D*  sprite);
        Allegro::Sprite4D * sprites;
        Allegro::Sprite4D * tiroSprites;

        std::list<Tiro*> tiros;
    protected:

};

// Tanque::Ta23


#endif