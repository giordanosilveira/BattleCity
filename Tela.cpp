#include "Tela.hpp"
#include "Allegro.hpp"

void Tela::desenharTela() {
    Allegro::limparTelaCor();
    Allegro::desenharTexto();
    Allegro::trocarDisplay();
}
