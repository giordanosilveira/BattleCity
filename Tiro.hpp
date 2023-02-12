#ifndef TIRO_HPP
#define TIRO_HPP

#include "Objeto.hpp"
#include "Parede.hpp"
#include "allegro/Sprite4D.hpp"
// #include "Tanque.hpp"

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
            Allegro::Sprite4D* const &sprites,
            const unsigned int direcao_tiro);
        
        virtual ~Tiro();

        void mover(std::list<Parede *> &paredes, std::list<Parede *> &paredes2, Tanque *tanque);
        virtual const bool colisao(const Tanque *tanque) const;


        Allegro::Sprite4D *sprites;
    private:
        Tanque *tanque;
        bool algumaColisao(const std::list<Parede *> &objetos);
        bool algumaColisao(Tanque * tanque);

        
};

#endif