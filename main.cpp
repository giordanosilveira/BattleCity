#include <iostream>

#include "Estado.hpp"

int main(int argc, char **argv){

    srand(time(NULL));
    for (;;){ // É pra ser loop infinito
        switch (Estado::atual){
            case Estado::JOGO: 
                Estado::jogo();
                break;
            case Estado::JOGO_PERDIDO:
                Estado::jogoPerdido();
                break;
            case Estado::ENCERRAR: 
                Estado::encerrar();
                break;
            default:
                exit(1);
        }
    }

    return 0;
}
