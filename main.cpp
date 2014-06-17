#include <iostream>
#include "Spielfeld.h"
#include "Spieler.h"
#include "EinAusgabe.h"

using namespace std;

int main() {
    SpielFeld spielFeld;
    spielFeld.spielerKreieren();
    spielFeld.spielen();
    spielFeld.ergebnisErmitteln();
}
