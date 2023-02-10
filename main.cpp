#include <iostream>

#include "Estado.hpp"

int main(int argc, char **argv){

    for (;;){ // É pra ser loop infinito
        switch (Estado::atual){
            case Estado::JOGO: 
                Estado::jogo();
                break;
            case Estado::ENCERRAR: 
                Estado::encerrar();
                break;
                exit(1);
        }
    }

    return 0;
}
