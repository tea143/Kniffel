#include <iostream>
#include "Spielfeld.h"
#include "Spieler.h"

using namespace std;

int main() {
    unsigned int spielerAnzahl;

    cout << "Das Kniffel-Spiel faengt an:\n" << endl;
    cout << "Wie viele Spieler spielen mit? " << endl;
    cin >> spielerAnzahl;

    SpielFeld spielFeld(spielerAnzahl);
    spielFeld.spielerKreieren();
    spielFeld.spielerAnzeigen();
    spielFeld.spielen();
    //spielFeld.ergebnisErmitteln();
}
