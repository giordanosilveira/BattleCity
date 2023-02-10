#include "Tiro.hpp"
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

    // transformar em  funcao
    this->mapa = new Mapa{"./data/mapa.txt"};

    std::vector<std::string> matriz = this->mapa->getMatriz();
    unsigned int n_linhas = matriz.size();
    unsigned int n_colunas = matriz[0].size();

    for (unsigned int i = 0; i < n_linhas; ++i){
        for (unsigned int j = 0; j < n_colunas; ++j){
            switch (matriz[i][j])
            {
            case '#':
                this->paredes.push_back(new Parede{j*Jogo::PAREDE_SIZE + Jogo::OFFSET, i*Jogo::PAREDE_SIZE + Jogo::OFFSET, Jogo::PAREDE_SIZE, 0, EnumEstadoObjeto::VIVO, 0, 1, EnumDirecao::PARADO, this->parede});
                break;
            case '@':
                this->paredeInvencivel.push_back(new Parede{j*Jogo::PAREDE_SIZE + Jogo::OFFSET, i*Jogo::PAREDE_SIZE + Jogo::OFFSET, Jogo::PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1, EnumDirecao::PARADO, this->paredeInvencivelSprite});
                break;
            default:
                break;
            }

        }
    }

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

    std::vector<const Parede *>::const_iterator it2{this->paredeInvencivel.begin()};
    for (; it2 < this->paredeInvencivel.end(); ++it2)
        tela->desenharSprite((*it2)->sprite, (*it2)->getSuperiorEsquerda()->getX(), (*it2)->getSuperiorEsquerda()->getY());
}

void Jogo::atualizarTiros(){
    std::list<Tiro*>::const_iterator it{this->player->tiros.begin()};
    for (; it != this->player->tiros.end(); ++it)
        (*it)->mover();
}

void Jogo::desenharTiros() const{
    Allegro::Tela *tela{Allegro::Tela::getInstancia()};

    std::list<Tiro*>::const_iterator it{this->player->tiros.begin()};
    for (; it != this->player->tiros.end(); ++it){
        tela->desenharSprite((*it)->sprites, (*it)->getSuperiorEsquerda()->getX(), (*it)->getSuperiorEsquerda()->getY());
    }
}

// void Jogo::desenharTanque(const Tanque* tanque) const{
//     Allegro::Tela *tela{Allegro::Tela::getInstancia()};

//     tela->desenharSprite(tanque->getSprite(), tanque->getSuperiorEsquerda()->getX(), tanque->getSuperiorEsquerda()->getY());
// }

void Jogo::criarParedesBorda(){
    Allegro::Tela *tela{Allegro::Tela::getInstancia()};
    for (unsigned int x = 0; x < tela->BUFFER_WIDTH - 32; x += 8){
        this->paredeInvencivel.push_back(new Parede{x, 0, this->PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1, EnumDirecao::PARADO, this->paredeInvencivelSprite});
        this->paredeInvencivel.push_back(new Parede{x, tela->BUFFER_HEIGHT-8, this->PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1,EnumDirecao::PARADO, this->paredeInvencivelSprite});
    }
    for (unsigned int y = 0; y < tela->BUFFER_HEIGHT - 8; y += 8){
        this->paredeInvencivel.push_back(new Parede{0, y, this->PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1, EnumDirecao::PARADO, this->paredeInvencivelSprite});
        this->paredeInvencivel.push_back(new Parede{tela->BUFFER_WIDTH-40, y, this->PAREDE_SIZE, 1, EnumEstadoObjeto::VIVO, 0, 1, EnumDirecao::PARADO, this->paredeInvencivelSprite});
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

    this->player->mover(this->paredes, this->paredeInvencivel);
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

    Allegro::Sprite4D *spritesTiro = new Allegro::Sprite4D();
    spritesTiro->inicializarSprite(this->spritesheet, 323, 102, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE, spritesTiro->CIM);
    spritesTiro->inicializarSprite(this->spritesheet, 330, 102, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE, spritesTiro->ESQ);
    spritesTiro->inicializarSprite(this->spritesheet, 339, 102, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE, spritesTiro->BAI);
    spritesTiro->inicializarSprite(this->spritesheet, 346, 102, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE, spritesTiro->DIR);
    this->tiroSprite = spritesTiro;

    Allegro::Sprite *parede{new Allegro::Sprite{this->spritesheet, 256, 64, Jogo::PAREDE_SIZE, Jogo::PAREDE_SIZE}};
    this->parede = parede;

    Allegro::Sprite *paredeInvencivelSprite{new Allegro::Sprite{this->spritesheet, 256, 72, Jogo::PAREDE_SIZE, Jogo::PAREDE_SIZE}};
    this->paredeInvencivelSprite = paredeInvencivelSprite;

    this->insignias.push_back(new Allegro::Sprite(this->spritesheet, 304, 31, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE));
    this->insignias.push_back(new Allegro::Sprite(this->spritesheet, 320, 31, Jogo::BLOCO_SIZE, Jogo::BLOCO_SIZE));


}
