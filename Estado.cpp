#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include <vector>
#include <string>
#include <iostream>

#include "Jogo.hpp"
#include "Estado.hpp"
#include "allegro/ControleJogo.hpp"
#include "allegro/Tela.hpp"

short int Estado::atual = Estado::JOGO;

void Estado::jogo(){
    bool done = false;

    allegro::ControleJogo *al = allegro::ControleJogo::getInstancia();
    allegro::Tela *tela = allegro::Tela::getInstancia();
    
    Jogo *j{Jogo::getInstancia()};
    bool redesenhar = false;
    
    al->esvaziarFila();
    for (;;){
        al->esperarEvento();

        if (al->getEvento() == al->TEMPO_QUADRO){
            al->visualizarTeclas();

            if (al->atirou()){
                Tiro *t = j->player->atirar(j->TIRO_SIZE, j->TIRO_VELOCIDADE);
                if (t != nullptr)
                    j->adicionarTiro(t);
            }
            j->atualizarEntidades();

            redesenhar = true;
        }
        
        else if (al->getEvento() == al->TECLA_PRESSIONADA)
            al->pressionarTecla();
        
        else if (al->getEvento() == al->TECLA_SOLTA)
            al->soltarTecla();
        
        if (al->sairJogo()){ // Jogador apertou esc
            done = true;
            Estado::atual = Estado::ENCERRAR;
        }

        if (j->insignia->morto() || j->player->getVida() == 0){
            done = true;
            redesenhar = true;
            Estado::atual = Estado::JOGO_TERMINADO;
        }

        if (j->n_tanques == 0 && j->inimigos.size() == 0) {
            done = true;
            redesenhar = true;
            j->setVencido(true);
            Estado::atual = Estado::JOGO_TERMINADO;
        }


        if (redesenhar){
            tela->limparTelaCor(103, 103, 103, 255);
            tela->desenharRetanguloCheio(0, 0, tela->BUFFER_WIDTH - 32, tela->BUFFER_HEIGHT, 0, 0, 0, 1);
            tela->desenharSprite(j->player->sprites, j->player->getSuperiorEsquerda()->getX(), j->player->getSuperiorEsquerda()->getY());
            tela->desenharSprite(j->backgroudPontuacao, 271, 16);
            j->desenharPontos();
            j->desenharVida();
            j->desenharTanquesPontos();
            // tela->desenharSprite(j->insignia->sprite, j->insignia->getSuperiorEsquerda()->getX(), j->insignia->getSuperiorEsquerda()->getY());
            tela->desenharSprite(j->insignia->sprite, j->insignia->getSuperiorEsquerda()->getX(), j->insignia->getSuperiorEsquerda()->getY());

            j->desenharTiros();
            j->desenharParedes();
            j->desenharInimigos();
            // tela->desenharSprite(j->mato, 20, 20);
            // tela->desenharSprite(j->parede, 40, 40);
            // tela->desenharSprite(j->muro, 60, 60);
            // tela->desenharSprite(j->agua, 80, 80);
            tela->desenharTela();
            redesenhar = false;
        }
        
        if (done) break;
    }

}

void Estado::jogoTerminado(){

    allegro::ControleJogo *al{allegro::ControleJogo::getInstancia()};
    allegro::Tela *tela{allegro::Tela::getInstancia()};
    Jogo *j{Jogo::getInstancia()};

    bool sair = false;
    tela->limparTelaCor(0, 0, 0, 128);
    
    if (j->getVencido() == true)
        tela->desenharTexto("Venceste!", 100, 100);
    else
        tela->desenharTexto("Perdeste!", 100, 100);
    tela->desenharTexto("Aperte ESC para sair.", 50, 120);
    tela->desenharTela();

    for (;;) {
        al->esperarEvento();

        if (al->getEvento() == al->TECLA_PRESSIONADA)
            al->pressionarTecla();
        
        if (al->sairJogo())
                sair = true;

        if (sair)
            break;
    }

    Estado::atual = Estado::ENCERRAR;
}

void Estado::encerrar(){
    allegro::ControleJogo *al{allegro::ControleJogo::getInstancia()};
    allegro::Tela *tela{allegro::Tela::getInstancia()};
    Jogo *jogo{Jogo::getInstancia()};
    delete al; // TODO ver se faz sentido (ver se chama destrutor)
    delete tela;
    delete jogo;
    

    exit(0);
}
