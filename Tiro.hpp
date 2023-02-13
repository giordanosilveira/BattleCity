#ifndef TIRO_HPP
#define TIRO_HPP

#include "Objeto.hpp"
//#include "Parede.hpp"
#include "allegro/Sprite4D.hpp"
// #include "Tanque.hpp"

class Tanque;
class Parede;

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

        void mover(std::list<Objeto*> objetos);


        Allegro::Sprite4D *sprites;
    private:
        Tanque *tanque;
        // Objeto* algumaColisao(const std::list<Objeto *> &objetos);

        
};

#endif