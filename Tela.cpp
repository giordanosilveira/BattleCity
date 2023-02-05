#include "Tela.hpp"
#include "Allegro.hpp"

void Tela::desenharTela() {
    Allegro *al = Allegro::getInstancia();
    al->limparTelaCor();
    al->desenharTexto();
    al->trocarDisplay();
}
