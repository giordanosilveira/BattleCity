#include "Tela.hpp"
#include "ControleJogo.hpp"

void Tela::desenharTela() {
    Allegro::ControleJogo *al = Allegro::ControleJogo::getInstancia();
    al->limparTelaCor();
    al->desenharTexto();
    al->trocarDisplay();
}
