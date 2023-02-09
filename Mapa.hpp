#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
#include <vector>

class Mapa {

    public:
        Mapa(const std::string &filename);

        //virtual ~Mapa();

        const std::vector<std::string> getMatriz() const;


    private:
        std::vector<std::string> matriz; 

}; 

#endif