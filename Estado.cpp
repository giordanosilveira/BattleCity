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
    Allegro::inicializar();

    Estado::atual = Estado::JOGO;
}

void Estado::jogo(){
    bool done = false;

    Allegro::esvaziarFila();
    for (;;){
        Allegro::esperarEvento();

        if (Allegro::getEvento() == Allegro::TEMPO_QUADRO)
            Allegro::visualizarTeclas();
        
        else if (Allegro::getEvento() == Allegro::TECLA_PRESSIONADA)
            Allegro::pressionarTecla();
        
        else if (Allegro::getEvento() == Allegro::TECLA_SOLTA)
            Allegro::soltarTecla();
        
        if (Allegro::sairJogo()){ // Jogador apertou esc
            done = true;
            Estado::atual = Estado::ENCERRAR;
        }

        if (done) break;

        Tela::desenharTela();
        
    }

}

void Estado::encerrar(){
    Allegro::finalizar();

    exit(0);
}
