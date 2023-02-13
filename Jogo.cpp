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

    this->player = new Player{8, 8, 16, false, EnumEstadoObjeto::VIVO, 10, 2, EnumDirecao::BAIXO, this->spritesTanquePlayer[0], this->tiroSprite};

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
    std::list<Parede *>::const_iterator it{this->paredes.begin()};
    for (; it != this->paredes.end(); ++it)
        tela->desenharSprite((*it)->sprite, (*it)->getSuperiorEsquerda()->getX(), (*it)->getSuperiorEsquerda()->getY());

    std::list<Parede *>::const_iterator it2{this->paredeInvencivel.begin()};
    for (; it2 != this->paredeInvencivel.end(); ++it2)
        tela->desenharSprite((*it2)->sprite, (*it2)->getSuperiorEsquerda()->getX(), (*it2)->getSuperiorEsquerda()->getY());
}


void Jogo::atualizarTirosPlayer() {
    
    std::list<Tiro*>::const_iterator it{this->tiros.begin()};
    for (; it != this->tiros.end();){
        
        std::list<Tanque*>::const_iterator it2{this->inimigos.begin()};
        for (; it2 != this->inimigos.end(); ++it2){

            (*it)->mover(this->paredes, this->paredeInvencivel, (*it2));

        }
        
        if ((*it)->getVida() == 0)
            it = this->tiros.erase(it);
        else 
            ++it;
    }
}

void Jogo::atualizarTirosInimigos() {
    
    std::list<Tiro*>::const_iterator it{this->tirosInimigos.begin()};
    for (; it != this->tirosInimigos.end();){
        (*it)->mover(this->paredes, this->paredeInvencivel, this->player);

        if ((*it)->getVida() == 0)
            it = this->tirosInimigos.erase(it);
        else 
            ++it;
    }
}


void Jogo::atualizarTiros(){

    this->atualizarTirosPlayer();
    this->atualizarTirosInimigos();
}


void Jogo::adicionarTirosInimigos(Tiro * const tiro) {
    if (this->tirosInimigos.size() < Jogo::LIMITE_TIROS_INIMIGOS) {
        this->tirosInimigos.push_back(tiro);
    }
}


void Jogo::moverTanque(Tanque *tanque) {

    EnumDirecao nova_direcao, antiga_direcao;
    
    if (tanque->getDirecao() == EnumDirecao::BAIXO) {
        if (! tanque->mover(this->paredes, this->paredeInvencivel) ){
            
            unsigned short int num = rand() % 100;
            if (num <= 35) 
                nova_direcao = EnumDirecao::BAIXO;
            else if (num > 35 && num <= 55)
                nova_direcao = EnumDirecao::DIREITA;
            else if (num > 55 && num <= 75)
                nova_direcao = EnumDirecao::ESQUERDA;
            else
                nova_direcao = EnumDirecao::CIMA;
            
            tanque->setDirecao(nova_direcao);
            tanque->mover(this->paredes, this->paredeInvencivel);
        }

    }
    else {
        if (!tanque->mover(this->paredes, this->paredeInvencivel)) {
             unsigned short int num = rand() % 100;
            if (num <= 35) 
                nova_direcao = EnumDirecao::BAIXO;
            else if (num > 35 && num <= 55)
                nova_direcao = EnumDirecao::DIREITA;
            else if (num > 55 && num <= 75)
                nova_direcao = EnumDirecao::ESQUERDA;
            else
                nova_direcao = EnumDirecao::CIMA;
            
            tanque->setDirecao(nova_direcao);
        }
    }

}


void Jogo::acaoInimigos() {

    std::list<Tanque*>::iterator it{this->inimigos.begin()};
    for (; it != this->inimigos.end(); ++it) {
        int num = (rand() % 50);
        if (num <= 40)
            this->moverTanque((*it));
        else {
            Tiro *t = (*it)->atirar(Jogo::TIRO_SIZE, 2);
            if (t != nullptr)
                this->adicionarTirosInimigos(t);
        }
    }    
}


void Jogo::decrementarTimerTirosInimigos() {

    std::list<Tanque *>::iterator it{this->inimigos.begin()};
    for (; it != this->inimigos.end(); ++it) {
        if (this->tirosInimigos.size() < Jogo::LIMITE_TIROS_INIMIGOS)
            (*it)->decrementarTimerTiro();
    }

}


void Jogo::matarInimigos() {
   
    std::list<Tanque*>::const_iterator it{this->inimigos.begin()};
    for (; it != this->inimigos.end();){
        if ((*it)->getVida() == 0)
            it = this->inimigos.erase(it);
        else 
            ++it;
    }

}


void Jogo::criarInimigos() {

    Tanque *tanque;
    if (this->inimigos.size() < Jogo::LIMITE_INIMIGOS) {
        switch (rand() % 5)
        {
            case 0:
                tanque = new Tanque{232, 8, 16, false, EnumEstadoObjeto::VIVO, 2, 1, EnumDirecao::BAIXO, this->spritesTanqueInimigos[0], this->tiroSprite};
                break;
            case 1:
                tanque = new Tanque{232, 104, 16, false, EnumEstadoObjeto::VIVO, 2, 1, EnumDirecao::ESQUERDA, this->spritesTanqueInimigos[0], this->tiroSprite};
                break;
            case 2:
                tanque = new Tanque{8, 104, 16, false, EnumEstadoObjeto::VIVO, 2, 1, EnumDirecao::DIREITA, this->spritesTanqueInimigos[0], this->tiroSprite};
                break;
                
            case 3:
                tanque = new Tanque{136, 96, 16, false, EnumEstadoObjeto::VIVO, 2, 1, EnumDirecao::BAIXO, this->spritesTanqueInimigos[0], this->tiroSprite};
                break;
                
            case 4:
                tanque = new Tanque{128, 136, 16, false, EnumEstadoObjeto::VIVO, 2, 1, EnumDirecao::CIMA, this->spritesTanqueInimigos[0], this->tiroSprite};
                break;
               
        }
        std::list<Tanque*>::iterator it{this->inimigos.begin()};
        for (; it != this->inimigos.end(); ++it) {
            if ((*it)->colisao(tanque)) {
                delete tanque;
                return;
            }
        }
        this->inimigos.push_back(tanque);
    }

}


void Jogo::atualizarInimigos(){
    
    this->decrementarTimerTirosInimigos();
    this->matarInimigos();
    this->criarInimigos();
    this->acaoInimigos();
    
}


void Jogo::atualizarParedes(){
    std::list<Parede*>::const_iterator it{this->paredes.begin()};
    for (; it != this->paredes.end();){
        if ((*it)->getVida() == 0)
            it = this->paredes.erase(it);
        else 
            ++it;
    }
}

void Jogo::atualizarPlayer(){
    moverPlayer();
    if (this->tiros.size() < this->LIMITE_TIROS_PLAYER)
    this->player->decrementarTimerTiro();
}

void Jogo::desenharTiros() const{
    Allegro::Tela *tela{Allegro::Tela::getInstancia()};
    std::list<Tiro*>::const_iterator it{this->tiros.begin()};
    for (; it != this->tiros.end(); ++it){
        tela->desenharSprite((*it)->sprites, (*it)->getSuperiorEsquerda()->getX(), (*it)->getSuperiorEsquerda()->getY());
    }
    std::list<Tiro*>::const_iterator it2{this->tirosInimigos.begin()};
    for (; it2 != this->tirosInimigos.end(); ++it2){
        tela->desenharSprite((*it2)->sprites, (*it2)->getSuperiorEsquerda()->getX(), (*it2)->getSuperiorEsquerda()->getY());
    }
}

void Jogo::desenharInimigos() const{
    Allegro::Tela *tela{Allegro::Tela::getInstancia()};

    std::list<Tanque*>::const_iterator it2{this->inimigos.begin()};
    for (; it2 != this->inimigos.end(); ++it2){
        tela->desenharSprite((*it2)->sprites, (*it2)->getSuperiorEsquerda()->getX(), (*it2)->getSuperiorEsquerda()->getY());
    }
}

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
    if (al->teclaPressionada(al->SETA_CIMA)) {
        this->player->setVelocidade(this->TANQUE_VELOCIDADE);
        this->player->setDirecao(EnumDirecao::CIMA);
    }
    else if (al->teclaPressionada(al->SETA_BAIXO)) {
        this->player->setVelocidade(this->TANQUE_VELOCIDADE);
        this->player->setDirecao(EnumDirecao::BAIXO);
    }
    else if (al->teclaPressionada(al->SETA_ESQUERDA)) {
        this->player->setVelocidade(this->TANQUE_VELOCIDADE);
        this->player->setDirecao(EnumDirecao::ESQUERDA);
    }
    else if (al->teclaPressionada(al->SETA_DIREITA)) {
        this->player->setVelocidade(this->TANQUE_VELOCIDADE);
        this->player->setDirecao(EnumDirecao::DIREITA);
    }
    else {
        this->player->setVelocidade(0); 
    }

    this->player->mover(this->paredes, this->paredeInvencivel);
}

void Jogo::adicionarTiro(Tiro * const tiro){
    this->tiros.push_back(tiro);
}

void Jogo::carregarSprites(){
    // Carrega spritesheet, usar move attribution(?)
    this->spritesheet = new Allegro::Sprite("./data/spritesheet2.png");

    this->spritesTanque.resize(2);

    Allegro::Tela *tela = Allegro::Tela::getInstancia();
    
    for (unsigned int i{0}; i <= 16; i += 16) {
        Allegro::Sprite4D *spritesTanque = new Allegro::Sprite4D();

        spritesTanque->inicializarSprite(this->spritesheet, i, 0, this->BLOCO_SIZE, this->BLOCO_SIZE, spritesTanque->CIM);
        spritesTanque->inicializarSprite(this->spritesheet, i+32, 0, this->BLOCO_SIZE, this->BLOCO_SIZE, spritesTanque->ESQ);
        spritesTanque->inicializarSprite(this->spritesheet, i+32*2, 0, this->BLOCO_SIZE, this->BLOCO_SIZE, spritesTanque->BAI);
        spritesTanque->inicializarSprite(this->spritesheet, i+32*3, 0, this->BLOCO_SIZE, this->BLOCO_SIZE, spritesTanque->DIR);
        this->spritesTanquePlayer.push_back(spritesTanque);
    }
    
    for (unsigned int i{128}; i <= 144; i += 16) {
        Allegro::Sprite4D *spritesTanque = new Allegro::Sprite4D();

        spritesTanque->inicializarSprite(this->spritesheet, i, 128, this->BLOCO_SIZE, this->BLOCO_SIZE, spritesTanque->CIM);
        spritesTanque->inicializarSprite(this->spritesheet, i+32, 128, this->BLOCO_SIZE, this->BLOCO_SIZE, spritesTanque->ESQ);
        spritesTanque->inicializarSprite(this->spritesheet, i+32*2, 128, this->BLOCO_SIZE, this->BLOCO_SIZE, spritesTanque->BAI);
        spritesTanque->inicializarSprite(this->spritesheet, i+32*3, 128, this->BLOCO_SIZE, this->BLOCO_SIZE, spritesTanque->DIR);
        this->spritesTanqueInimigos.push_back(spritesTanque);
    }

    Allegro::Sprite4D *spritesTiro = new Allegro::Sprite4D();
    spritesTiro->inicializarSprite(this->spritesheet, 323, 102, this->TIRO_SIZE, this->TIRO_SIZE, spritesTiro->CIM);
    spritesTiro->inicializarSprite(this->spritesheet, 330, 102, this->TIRO_SIZE, this->TIRO_SIZE, spritesTiro->ESQ);
    spritesTiro->inicializarSprite(this->spritesheet, 339, 102, this->TIRO_SIZE, this->TIRO_SIZE, spritesTiro->BAI);
    spritesTiro->inicializarSprite(this->spritesheet, 346, 102, this->TIRO_SIZE, this->TIRO_SIZE, spritesTiro->DIR);
    this->tiroSprite = spritesTiro;

    Allegro::Sprite *parede{new Allegro::Sprite{this->spritesheet, 256, 64, this->PAREDE_SIZE, this->PAREDE_SIZE}};
    this->parede = parede;

    Allegro::Sprite *paredeInvencivelSprite{new Allegro::Sprite{this->spritesheet, 256, 72, this->PAREDE_SIZE, this->PAREDE_SIZE}};
    this->paredeInvencivelSprite = paredeInvencivelSprite;

    this->insignias.push_back(new Allegro::Sprite(this->spritesheet, 304, 31, this->BLOCO_SIZE, this->BLOCO_SIZE));
    this->insignias.push_back(new Allegro::Sprite(this->spritesheet, 320, 31, this->BLOCO_SIZE, this->BLOCO_SIZE));


}
