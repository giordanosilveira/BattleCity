#include <stdio.h>

#include "Estado.hpp"

int main(int argc, char **argv){

    for (;;){ // É pra ser loop infinito
        switch (Estado::atual){
            case Estado::JOGO: 
                Estado::jogo();
                break;
            case Estado::INICIALIZAR: 
                Estado::inicializar();
                break;
            case Estado::ENCERRAR: 
                Estado::encerrar();
                break;
            default: 
                printf("Algo deu errado no estado\n");
        }
    }

    return 0;
}
