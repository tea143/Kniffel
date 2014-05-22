#include "Spielfeld.h"

using namespace std;

SpielFeld::SpielFeld(size_t anzahl)
: spielerAnzahl {
    anzahl
}
{
}

const size_t SpielFeld::getSpielerAnzahl() const {
    return spielerAnzahl;
}

vector <Spieler> SpielFeld::spielerKreieren() {
    string name;
    for (size_t i = 0; i < spielerAnzahl; i++) {
        cout << "Geben Sie den Namen des " << i + 1 << ". Spielers ein: " << endl;
        cin >> name;
        Spieler spieler(name);
        spielerListe.push_back(spieler);
    }
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
        cout << endl << "###### RUNDE " << i + 1 << " ######:" << endl;
        for (auto& spieler : spielerListe) {
            cout << endl << "Spieler " << spieler.getName() << " ist an der Reihe!" << endl;
            spieler.printFreieKategorien();
            wuerfel = {3, 3, 3, 3, 3};
            //cout << "Gebe Nummer der Würfel aus, die du wieder in der Würfelbecher werfen willst!" << endl;
            cout << "Waehle eine freie Kategorie (Zahl): " << endl;
            EinAusgabe io;
            size_t kategorie = io.readNumberBetween(0, SPIELRUNDEN - 1);
            spieler.punktzahlErmitteln(kategorie, wuerfel);
        }
    }
}

/*void wuerfeln() {

}*/

void SpielFeld::ergebnisErmitteln() {
    cout << endl << endl << "ERGEBNIS: " << endl;
    size_t gewinnerPunktzahl = 0;
    for (auto& spieler : spielerListe) {
        spieler.bonusErmitteln();
        cout << spieler.getName() << " hat " << spieler.getPunktzahl() << " Punkte erreicht." << endl;
        if (spieler.getPunktzahl() > gewinnerPunktzahl) {
            gewinnerPunktzahl = spieler.getPunktzahl();
        }
    }
    cout << endl << "GEWINNER: " << endl;
    for (auto& spieler : spielerListe) {
        if (gewinnerPunktzahl == spieler.getPunktzahl()) {
            cout << spieler.getName() << endl;
        }
    }
}