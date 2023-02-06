#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include <vector>
#include <string>
#include <iostream>

#include "Jogo.hpp"
#include "Estado.hpp"
#include "ControleJogo.hpp"
#include "Tela.hpp"

short int Estado::atual = Estado::INICIALIZAR;

void Estado::inicializar(){

    Estado::atual = Estado::JOGO;
}

void Estado::jogo(){
    bool done = false;

    Allegro::ControleJogo *al = Allegro::ControleJogo::getInstancia();
    Allegro::Tela *tela = Allegro::Tela::getInstancia();
    
    Jogo *j{Jogo::getInstancia()};
    bool redesenhar = false;
    

    al->esvaziarFila();
    for (;;){
        al->esperarEvento();

        if (al->getEvento() == al->TEMPO_QUADRO){
            al->visualizarTeclas();
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

        if (done) break;

        if (redesenhar){
            tela->desenharTela();
            redesenhar = false;
        }
        
    }

}

void Estado::encerrar(){
    Allegro::ControleJogo *al = Allegro::ControleJogo::getInstancia();
    delete al; // TODO ver se faz sentido
    

    exit(0);
}
