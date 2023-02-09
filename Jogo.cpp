#include "allegro/Sprite4D.hpp"
#include "allegro/Tela.hpp"
#include "allegro/ControleJogo.hpp"
#include "enums/EnumEstadoObjeto.hpp"
#include "enums/EnumDirecao.hpp"

#include "Jogo.hpp"
#include "Player.hpp"
#include "Parede.hpp"
#include "Tanque.hpp"

#include <memory>
#include <iostream>

Jogo *Jogo::instancia{nullptr};


Jogo::Jogo(){
    this->carregarSprites();

    this->player = new Player{8, 8, 16, false, EnumEstadoObjeto::VIVO, 10, 2, EnumDirecao::BAIXO, this->spritesTanquePlayer[0]};
    

    this->criarParedesBorda();
}

Jogo *Jogo::getInstancia(){
    if (Jogo::instancia == nullptr)
        Jogo::instancia = new Jogo();
    return Jogo::instancia;
}


void Jogo::desenharParedes() const{
    Allegro::Tela *tela{Allegro::Tela::getInstancia()};
    std::vector<const Parede *>::const_iterator it{this->paredes.begin()};
    for (; it < this->paredes.end(); ++it)
        tela->desenharSprite((*it)->sprite, (*it)->getSuperiorEsquerda()->getX(), (*it)->getSuperiorEsquerda()->getY());
}

// void Jogo::desenharTanque(const Tanque* tanque) const{
//     Allegro::Tela *tela{Allegro::Tela::getInstancia()};

//     tela->desenharSprite(tanque->getSprite(), tanque->getSuperiorEsquerda()->getX(), tanque->getSuperiorEsquerda()->getY());
// }

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
    
    for (unsigned int i{0}; i <= 16; i += 16) {
        Allegro::Sprite4D *sp4d = new Allegro::Sprite4D();

        sp4d->inicializarSprite(this->spritesheet, i, 0, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE, sp4d->CIM);
        sp4d->inicializarSprite(this->spritesheet, i+32, 0, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE, sp4d->ESQ);
        sp4d->inicializarSprite(this->spritesheet, i+32*2, 0, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE, sp4d->BAI);
        sp4d->inicializarSprite(this->spritesheet, i+32*3, 0, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE, sp4d->DIR);
        this->spritesTanquePlayer.push_back(sp4d);
    }

    // for (unsigned int i{0}; i <= 16; i += 16) {
    //     Allegro::Sprite sp1{this->spritesheet, i, 0, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE};
    //     Allegro::Sprite sp2{this->spritesheet, i+32, 0, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE};
    //     Allegro::Sprite sp3{this->spritesheet, i+32*2, 0, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE};
    //     Allegro::Sprite sp4{this->spritesheet, i+32*3, 0, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE};
    //     this->spritesTanquePlayer.push_back(new Allegro::Sprite4D{sp1.getBitmap(), sp2.getBitmap(), sp3.getBitmap(), sp4.getBitmap()});
    // }

    // pega 2 matrizes de sprites
    // unsigned int offsetlin = Jogo::TANK_HEI * Jogo::TANK_MAT_HEI;
    // unsigned int offsetcol = Jogo::TANK_WID * Jogo::TANK_MAT_WID;
    // for (unsigned int num_cor{0}; num_cor < 2; ++num_cor)
    //     for (unsigned int lin{0}; lin < Jogo::TANK_MAT_HEI; ++lin)
    //         for (unsigned int col{0}; col < Jogo::TANK_MAT_WID; ++col)
    //             spritesTanque[num_cor].push_back(
    //                 new Allegro::Sprite(this->spritesheet, 
    //                     offsetcol*num_cor + col*Jogo::TANK_WID, 
    //                     offsetlin*num_cor + lin*Jogo::TANK_HEI,
    //                     Jogo::TANK_WID, Jogo::TANK_HEI));
    
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
