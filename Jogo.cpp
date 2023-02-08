#include "Jogo.hpp"
#include "allegro/Tela.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "enums/EnumDirecao.hpp"
#include "Player.hpp"
#include <memory>
#include <iostream>

Jogo *Jogo::instancia{nullptr};

Jogo::Jogo(){
    this->carregarSprites();
    this->player = new Player{0, 0, 16, false, EnumEstadoObjeto::VIVO, 10, 0, EnumDirecao::BAIXO, this->spritesTanque[0][0]};
}

Jogo *Jogo::getInstancia(){
    if (Jogo::instancia == nullptr)
        Jogo::instancia = new Jogo();
    return Jogo::instancia;
}

void Jogo::carregarSprites(){
    // Carrega spritesheet, usar move attribution(?)
    this->spritesheet = new Allegro::Sprite("./data/spritesheet.png");

    this->spritesTanque.resize(2);

    Allegro::Tela *tela = Allegro::Tela::getInstancia();

    // pega 2 matrizes de sprites
    unsigned int offsetlin = Jogo::TANK_HEI * Jogo::TANK_MAT_HEI;
    unsigned int offsetcol = Jogo::TANK_WID * Jogo::TANK_MAT_WID;
    for (unsigned int num_cor = 0; num_cor < 2; ++num_cor)
        for (unsigned int lin = 0; lin < Jogo::TANK_MAT_HEI; ++lin)
            for (unsigned int col = 0; col < Jogo::TANK_MAT_WID; ++col)
                spritesTanque[num_cor].push_back(
                    new Allegro::Sprite(this->spritesheet, 
                        offsetcol*num_cor + col*Jogo::TANK_WID, 
                        offsetlin*num_cor + lin*Jogo::TANK_HEI,
                        Jogo::TANK_WID, Jogo::TANK_HEI));
    
    Allegro::Sprite *parede{new Allegro::Sprite{this->spritesheet, 256, 64, Jogo::PAREDE_SIZE, Jogo::PAREDE_SIZE}};
    this->parede = parede;

    Allegro::Sprite *muro{new Allegro::Sprite{this->spritesheet, 256, 16, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE}};
    this->muro = muro;

    Allegro::Sprite *agua{new Allegro::Sprite{this->spritesheet, 256, 48, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE}};
    this->agua = agua;

    Allegro::Sprite *mato{new Allegro::Sprite{this->spritesheet, 272, 31, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE}};
    this->mato = mato;

    this->insignias.push_back(new Allegro::Sprite(this->spritesheet, 304, 31, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE));
    this->insignias.push_back(new Allegro::Sprite(this->spritesheet, 320, 31, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE));


    // tela->desenharSprite(spritesTanque[0][0], 0, 0);

}
