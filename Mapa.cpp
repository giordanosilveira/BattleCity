#include "Mapa.hpp"
#include <iostream>
#include <fstream>

Mapa::Mapa(const std::string &filename) {

    std::string linha;
    char c;

    std::ifstream input_file(filename);

    while (input_file >> linha) {
        this->matriz.push_back(linha);
    }

}

const std::vector<std::string> Mapa::getMatriz() const{
    return this->matriz;
}