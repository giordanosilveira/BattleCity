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

        virtual void setDirecao();

        virtual const bool colisao(std::list<Objeto*>&objeto) const override;

    protected:
        std::list<Tiro*>tiros;

};

Tanque::Tanque(){}

Tanque::Tanque(const unsigned int x, const unsigned int y, unsigned short int tamanhoSprite, const unsigned short imortal, const unsigned short estado, const unsigned short velocidade, const unsigned short direcao){}

Tanque::~Tanque()
{
}

const bool Tanque::colisao(std::list<Objeto*>&objeto) const {

    unsigned short x_tanque = this->coordenada->getX();
    unsigned short y_tanque = this->coordenada->getY();
    unsigned short tam_tanque = (unsigned short)this->getTamanhoSprite();
    
    std::list<Objeto*>::const_iterator it;
    it = objeto.begin();
    for (it; it != objeto.end(); ++it) {
        
        unsigned short int x_obj = this->coordenada->getX();
        unsigned short int y_obj = this->coordenada->getY();
        unsigned short int tam_obj = (unsigned short) (*it)->getTamanhoSprite();

        switch (this->direcao)
        {
            case (unsigned char)EnumDirecao::DIREITA:
                if ((y_tanque >= y_obj && y_tanque <= y_obj + tam_obj) || (y_tanque + tam_tanque >= y_obj && y_tanque + tam_tanque <= y_obj + tam_obj)) {
                    if (x_tanque + tam_tanque >= x_obj)
                        return true;
                }
                break;
            case (unsigned char)EnumDirecao::ESQUERDA:
                if ((y_tanque >= y_obj && y_tanque <= y_obj + tam_obj) || (y_tanque + tam_tanque >= y_obj && y_tanque + tam_tanque <= y_obj + tam_obj)) {
                    if (x_tanque >= x_obj + tam_obj)
                        return true;
                }
                break;
            case (unsigned char)EnumDirecao::CIMA:
                if ((x_tanque >= x_obj && x_tanque <= x_obj + tam_obj) || (x_tanque + tam_tanque >= x_obj && x_tanque + tam_tanque <= x_obj + tam_obj)) {
                    if (y_tanque >= y_obj + tam_obj)
                        return true;
                }
                break;
            case (unsigned char)EnumDirecao::BAIXO:
                if ((x_tanque >= x_obj && x_tanque <= x_obj + tam_obj) || (x_tanque + tam_tanque >= x_obj && x_tanque + tam_tanque <= x_obj + tam_obj)) {
                    if (y_tanque + tam_tanque >= x_obj)
                        return true;
                }
                break;
        }
    }

    return false;

};


#endif