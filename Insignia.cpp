#include "Insignia.hpp"

Insignia::Insignia(const unsigned int x, const unsigned int y, const unsigned short int tamanhoSprite, 
        const unsigned short imortal, EnumEstadoObjeto estado, const unsigned short vida, 
        const unsigned short velocidade, EnumDirecao direcao, allegro::Sprite *spriteVivo, 
        allegro::Sprite *spriteMorto)
        :Objeto{x, y, tamanhoSprite, imortal, estado, vida, velocidade, direcao}, spriteVivo{spriteVivo}, spriteMorto{spriteMorto}{
    this->sprite = this->spriteVivo;
}

void Insignia::atualizarSprite(){
    if (this->vida == 0)
        this->sprite = spriteMorto;
    else
        this->sprite = spriteVivo;
}
