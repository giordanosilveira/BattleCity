#ifndef TANQUE_HPP
#define TANQUE_HPP

// #include "Tiro.hpp"
#include "Objeto.hpp"
#include "allegro/Sprite.hpp"
#include "allegro/Sprite4D.hpp"
#include "enums/EnumDirecao.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include <iostream>
#include <list>


class Tanque : public Objeto{

    // friend void Tiro::setTanque(Tanque*tanque);

    public:
        Tanque();
        Tanque(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, EnumDirecao direcao);
        
        virtual ~Tanque();

        // virtual void mover();

        // virtual void atirar();

        // virtual void setDirecao(EnumDirecao direcao);

        // virtual const bool colisao(std::list<Objeto*>&objeto) const;// override;

        const Allegro::Sprite* getSprite() const;
        void setSprites(Allegro::Sprite *spEsq, Allegro::Sprite *spBai, Allegro::Sprite *spDir, Allegro::Sprite *spCim);
        Allegro::Sprite4D * sprites;

    protected:
        // std::list<Tiro*>tiros;

};

// Tanque::Ta23


#endif