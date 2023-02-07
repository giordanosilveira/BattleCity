#include "Jogo.hpp"
#include "Tela.hpp"
#include "EnumEstadoObjeto.hpp"
#include "EnumDirecao.hpp"
#include "Player.hpp"
#include <memory>
#include <iostream>

Jogo *Jogo::instancia{nullptr};

Jogo::Jogo(){
    this->carregarSprites();
    this->player = new Player{0, 0, 16, false, EnumEstadoObjeto::VIVO, 0, EnumDirecao::BAIXO, this->spritesTanque[0][0]};
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

    // pega 4 matrizes de sprites
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

    // tela->desenharSprite(spritesTanque[0][0], 0, 0);

}
