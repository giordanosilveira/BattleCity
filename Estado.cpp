#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include <vector>
#include <string>
#include <iostream>

#include "Estado.hpp"
#include "Allegro.hpp"
#include "Tela.hpp"

short int Estado::atual = Estado::INICIALIZAR;

void Estado::inicializar(){

    Estado::atual = Estado::JOGO;
}

void Estado::jogo(){
    bool done = false;
    Allegro *al = Allegro::getInstancia();

    al->esvaziarFila();
    for (;;){
        al->esperarEvento();

        if (al->getEvento() == al->TEMPO_QUADRO)
            al->visualizarTeclas();
        
        else if (al->getEvento() == al->TECLA_PRESSIONADA)
            al->pressionarTecla();
        
        else if (al->getEvento() == al->TECLA_SOLTA)
            al->soltarTecla();
        
        if (al->sairJogo()){ // Jogador apertou esc
            done = true;
            Estado::atual = Estado::ENCERRAR;
        }

        if (done) break;

        Tela::desenharTela();
        
    }

}

void Estado::encerrar(){
    Allegro *al = Allegro::getInstancia();
    delete al; // TODO ver se faz sentido

    exit(0);
}
