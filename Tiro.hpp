#ifndef TIRO_HPP
#define TIRO_HPP

#include "Objeto.hpp"

class Tiro : public Objeto{
    public:
        Tiro();
        Tiro(const unsigned int x, const unsigned int y, const unsigned short int tamanhoSprite, const unsigned short imortal, const unsigned short estado, const unsigned short int velocidade, const unsigned short int direcao);
        virtual ~Tiro();

        const unsigned short int getVelocidade() const;
        void setVelocidade(const unsigned short int velocidade);

        const unsigned short int getDirecao() const;
        void setDirecao(const unsigned short int direcao);

    private:
        unsigned char velocidade;
        unsigned char direcao;

        
};

#endif