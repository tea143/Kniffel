#include <iostream>
#include <vector>
#include <cstddef>
#include <string>
#include "spielfeld.h"
#include "spieler.h"

using namespace std;

SpielFeld::SpielFeld(unsigned int anzahl)
: spielerAnzahl {
    anzahl
}
{
}

const unsigned int SpielFeld::getSpielerAnzahl() const {
    return spielerAnzahl;
}

vector <Spieler> SpielFeld::spielerKreieren() {
    unsigned int spielerAnzahl = getSpielerAnzahl();
    string name;
    do {
        cout << "Geben Sie den Namen des Spielers ein: " << endl;
        cin >> name;
        Spieler spieler(name);
        spielerListe.push_back(spieler);
        spielerAnzahl--;
    } while (spielerAnzahl != 0);
    return spielerListe;
}

void SpielFeld::spielerAnzeigen() {
    for (auto& spieler : spielerListe) {
        cout << "Spieler: " << spieler.getName() << endl;
    }
}

const vector<Spieler>& SpielFeld::getSpielerListe() const {
    return spielerListe;
}

void SpielFeld::spielen() {
    for (size_t i = 0; i < SPIELRUNDEN; i++) {
        cout << endl << "Runde " << i << ":" << endl;
        for (auto& spieler : spielerListe) {
            spieler.printFreieKategorien();
            wuerfel = {3, 5, 5, 5, 5};
            //cout << "Gebe Nummer der Würfel aus, die du wieder in der Würfelbecher werfen willst!" << endl;
            cout << "Waehle eine freie Kategorie (Zahl): " << endl;
            int kategorie;
            cin >> kategorie;
            spieler.punktzahlErmitteln(kategorie, wuerfel);
        }
    }
}

/*void wuerfeln() {

}*/

void SpielFeld::ergebnisErmitteln() {

}