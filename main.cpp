#include <iostream>
#include "header_files/Spielfeld.h"
#include "header_files/Spieler.h"
#include "header_files/EinAusgabe.h"

using namespace std;

int main() {
    cout << "Das Kniffel-Spiel f\x84 \bngt an:\n" << endl;
    cout << "Wie viele Spieler spielen mit? " << endl;
    EinAusgabe io;
    unsigned int spielerAnzahl = io.readNumberBetween(1, 5);
    SpielFeld spielFeld(spielerAnzahl);
    spielFeld.spielerKreieren();
    spielFeld.spielen();
    spielFeld.ergebnisErmitteln();
}
