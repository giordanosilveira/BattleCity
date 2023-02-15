#include "AllegroInitException.hpp"
#include <string>

using namespace allegro;

AllegroInitException::AllegroInitException(const std::string &name)
    :std::runtime_error{"Erro de inicialização de '" + name + "' da biblioteca allegro!"}{
}