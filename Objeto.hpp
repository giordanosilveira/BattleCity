#ifndef OBJETO_HPP
#define OBJETO_HPP

#include <iostream>
#include <vector>
#include <list>

#include "Coordenada.hpp"
#include "enums/EnumDirecao.hpp"
#include "allegro/Sprite.hpp"
#include "enums/EnumEstadoObjeto.hpp"


class Objeto {
    public:
        /**
         * @brief Construtor padrão.
         */
        Objeto();

        /**
         * @param x (unsigned int) : ponto x.
         * @param y (unsigned int) : ponto y.
         * @param tamanhoSprite x (unsigned short int) : tamanho da sprite.
         */
        Objeto(const unsigned int x, const unsigned int y, const unsigned short int tamanhoSprite, const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, const unsigned short velocidade, EnumDirecao direcao);

        /**
         * @brief Destrutor
         */
        virtual ~Objeto();

        /**
         * @brief Retorna o ponteiro da coordenada.
         * @return (const Coordenada*) : Ponteiro da coordenada 
         */
        const Coordenada* getSuperiorEsquerda() const;

        /**
         * @brief atualiza o ponto x e y da coordenada superior esquerda.
         * @param x (short int) : Coordenada x.
         * @param y (short int) : Coordenada y.
         */
        void setSuperiorEsquerda (const unsigned short int x, unsigned short int y);


        /**
         * @brief atualiza o ponto x e y da coordenada inferior direita.
         * @param x (short int) : Coordenada x.
         * @param y (short int) : Coordenada y.
         */
        void setInferiorDireita (const unsigned short int x, unsigned short int y);


        /**
         * @brief Get the Velocidade object
         * 
         * @return const unsigned short int 
         */
        const unsigned short int getVelocidade() const;

        /**
         * @brief Set the Velocidade object
         * 
         * @param int 
         */
        void setVelocidade(const unsigned short int);

        /**
         * @brief Get the Direcao object
         * 
         * @return const unsigned short int 
         */
        const EnumDirecao getDirecao() const;

        /**
         * @brief Set the Direcao object
         * 
         * @param direcao 
         */
        void setDirecao(EnumDirecao direcao);


        /**
         * @brief Retorna o tamanho da sprite
         * @return (unsigned short int) : tamanho da sprite.
         */
        const unsigned short int getTamanhoSprite() const;

        /**
         * @brief Define o tamanho da sprite
         * @param (unsigned short int) : tamanho da sprite. 
         */
        void setTamanhoSprite(unsigned short int);


        virtual void mover();
        
        
        virtual const bool colisao(const Coordenada& coordSuperiorEsquerda, const Coordenada& coordInferiorDireira) const; 
    
        // virtual void setDirecao() = 0;

        // MUITO FEIO, DEIXAR PRIVADO DEPOIS
        Allegro::Sprite *sprite;
        std::vector<const Allegro::Sprite*> sprites;
        
    protected:
        Coordenada *superiorEsquerda;
        Coordenada *inferiorDireita;
        unsigned char tamanhoSprite;
        unsigned char imortal;
        unsigned char estado;
        unsigned char vida;
        unsigned char velocidade;
        EnumDirecao direcao;

};

#endif