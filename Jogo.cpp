#include "Jogo.hpp"
#include "Tela.hpp"
#include <iostream>

Jogo *Jogo::instancia{nullptr};

Jogo::Jogo(){
    this->carregarSprites();
}

Jogo *Jogo::getInstancia(){
    if (Jogo::instancia == nullptr)
        Jogo::instancia = new Jogo();
    return Jogo::instancia;
}

void Jogo::carregarSprites(){
    // Carrega spritesheet, usar move attribution(?)
    this->spritesheet = new Allegro::Sprite("./data/spritesheet.png");

    this->spritesTanque.resize(4);

    Allegro::Tela *tela = Allegro::Tela::getInstancia();

    // Temporário
    tela->desenharTexto("Habemus sprites");

    for (unsigned int i = 0; i < Jogo::TANK_MAT_HEI; ++i){
        for (unsigned int j = 0; j < Jogo::TANK_MAT_WID; ++j){
            spritesTanque[0].push_back(
                new Allegro::Sprite(this->spritesheet, j*Jogo::TANK_WID, i*Jogo::TANK_HEI,
                Jogo::TANK_WID, Jogo::TANK_HEI));

            // Temporário
            tela->desenharSprite(this->spritesTanque[0][i*Jogo::TANK_MAT_WID + j], 10 + j * (Jogo::TANK_WID + 5), 30 + i * (Jogo::TANK_HEI + 5)); 
        }
    }


}
