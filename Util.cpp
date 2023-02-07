#include "Util.hpp"
#include "AllegroInitException.hpp"

#include <string>

void Util::testInit(bool test, const std::string message)
// Testa retorno de função de inicialização do ControleJogo
{
    if (test) return;
    throw AllegroInitException(message);
}