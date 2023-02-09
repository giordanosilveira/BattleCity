#include "Jogo.hpp"
#include "allegro/Tela.hpp"
#include "allegro/ControleJogo.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "enums/EnumDirecao.hpp"
#include "Player.hpp"
#include "Parede.hpp"
#include <memory>
#include <iostream>

Jogo *Jogo::instancia{nullptr};

void Jogo::desenharParedes(){
    Allegro::Tela *tela{Allegro::Tela::getInstancia()};
    std::vector<const Parede *>::iterator it{this->paredes.begin()};
    for (; it < this->paredes.end(); ++it)
        tela->desenharSprite((*it)->sprite, (*it)->getSuperiorEsquerda()->getX(), (*it)->getSuperiorEsquerda()->getY());
}

void Jogo::criarParedesBorda(){
    Allegro::Tela *tela{Allegro::Tela::getInstancia()};
    for (unsigned int x = 0; x < tela->BUFFER_WIDTH - 32; x += 8){
        this->paredes.push_back(new Parede{x, 0, this->PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1, EnumDirecao::PARADO, this->parede});
        this->paredes.push_back(new Parede{x, tela->BUFFER_HEIGHT-8, this->PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1,EnumDirecao::PARADO, this->parede});
    }
    for (unsigned int y = 0; y < tela->BUFFER_HEIGHT - 8; y += 8){
        this->paredes.push_back(new Parede{0, y, this->PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1, EnumDirecao::PARADO, this->parede});
        this->paredes.push_back(new Parede{tela->BUFFER_WIDTH-40, y, this->PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1, EnumDirecao::PARADO, this->parede});
    }
}

Jogo::Jogo(){
    this->carregarSprites();
    this->player = new Player{8, 8, 16, false, EnumEstadoObjeto::VIVO, 10, 2, EnumDirecao::BAIXO, this->spritesTanque[0][0], this->spritesTanque[0]};
    this->criarParedesBorda();
}

Jogo *Jogo::getInstancia(){
    if (Jogo::instancia == nullptr)
        Jogo::instancia = new Jogo();
    return Jogo::instancia;
}

void Jogo::moverPlayer(){
    Allegro::ControleJogo *al = Allegro::ControleJogo::getInstancia();
    if (al->teclaPressionada(al->SETA_CIMA))
        this->player->setDirecao(EnumDirecao::CIMA);

    else if (al->teclaPressionada(al->SETA_BAIXO)) 
        this->player->setDirecao(EnumDirecao::BAIXO);
    
    else if (al->teclaPressionada(al->SETA_ESQUERDA)) 
        this->player->setDirecao(EnumDirecao::ESQUERDA);

    else if (al->teclaPressionada(al->SETA_DIREITA)) 
        this->player->setDirecao(EnumDirecao::DIREITA);

    else 
        this->player->setDirecao(EnumDirecao::PARADO);

    this->player->mover(this->paredes);
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


}
