#include "AllegroInitException.hpp"

AllegroInitException::AllegroInitException()
    :std::runtime_error{"Erro de inicialização de estrutura interna da biblioteca Allegro!"}{
}