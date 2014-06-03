#include "header_files/spielfeld.h"
#include "header_files/spieler.h"
#include "header_files/einAusgabe.h"

using namespace std;

int main() {
    cout << "Das Kniffel-Spiel f\x84 \bngt an:\n" << endl;
    cout << "Wie viele Spieler spielen mit? " << endl;
    EinAusgabe io;
    size_t spielerAnzahl = io.readNumberBetween(1,5);
    SpielFeld spielFeld(spielerAnzahl);
    vector<Spieler*> spielerListe = spielFeld.spielerKreieren();
    spielFeld.spielen();
    spielFeld.ergebnisErmitteln();
    spielFeld.spielfeldAufraemen(spielerListe);
    for (auto spieler : spielerListe) {
		delete spieler;
	}
}
