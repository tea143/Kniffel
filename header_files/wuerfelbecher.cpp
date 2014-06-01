/**
 * 	@file: wuerfelbecher.cpp
 *
 *  @date: 21.05.2014
 *  @author: IFI
 */

#include "wuerfelbecher.h"
using namespace std;

Wuerfelbecher::Wuerfelbecher() {

}

Wuerfelbecher::~Wuerfelbecher() {

}

/**
 * Nimmt bestimmte Anzahl der Würfel entgegen und präsentiert eine zufällige Mischung
 * @param anzahlWuerfel - int: Anzahl Würfel, die gewürfel wurden
 * @return wuerfelbecher - vector<int>: Vector mit gerade gewürfelten Würfel
 */
vector<int> Wuerfelbecher::schuetteln(int anzahlWuerfel) {
    wuerfelbecher.clear();
    for (size_t i = 0; i < static_cast<unsigned> (anzahlWuerfel); i++) {
        wuerfelbecher.push_back(Zufallszahl::rnd(1, 6));
    }
    return wuerfelbecher;
}

/**
 * Fragt der Benutzer nach, mit wie viele Würfeln er weiter spielen möchte.
 * Die ausgewählte Stellen, werden im Ergebnis überschrieben
 */
void Wuerfelbecher::wuerfelAuswaehlen() {
    int nummer;
    for (size_t i = 0; i < wuerfelbecher.size(); i++) {
        cout << "Gib eine W\x81 \brfelnummer ein:" << endl;
        nummer = io.readNumberBetween(1, 5);
        ergebnis.insert(ergebnis.begin() + (nummer - 1), wuerfelbecher.at(i));
        ergebnis.erase(ergebnis.begin() + nummer);
    }
}

/**
 * Ausgabe des Ergebnisses
 * @return ergebnis - vector<int>: der Vector mit Endergebnissen
 */
const vector<int>& Wuerfelbecher::getErgebnis() const {
    return ergebnis;
}

/**
 * Der Spieler hat 3 Versuche um seine Würfelkombination zu wählen.
 * Im ersten Versuch werden alle 5 Würfel benutzt. Später wird der Benutzer gefragt,
 * ob er weiterhin würfel will oder der Ergebnis aufschreiben will.
 * Am Ende jedes Durchgangs werden die Würfel angezeigt, der Spieler gerade gewürfelt hat (unsortiert) und der Ergebnis dieser Runde (sortiert)
 */
void Wuerfelbecher::wuerfeln() {
    int anzahl;
    char antwort;
    for (size_t versuch = 1; versuch < 4; versuch++) {
        if (versuch == 1) {
            anzahl = 5;
            schuetteln(anzahl);
            ergebnis = wuerfelbecher;
        } else {
            do {
                cout << "M\x94 \bchtest du weiter w\x81 \brfeln? j/n:" << std::endl;
                cin >> antwort;
            } while (antwort == 'j' && antwort == 'n');
            if (antwort == 'j') {
                cout << endl << "Mit wie vielen W\x81 \brfel m\x94 \bchtest du w\x81 \brfeln?" << endl;
                anzahl = io.readNumberBetween(1, 5);
                schuetteln(anzahl);
                wuerfelAuswaehlen();
            } else {
                versuch = 4;
            }
        }
        sort(ergebnis.begin(), ergebnis.end());
        if (versuch != 4) {
            cout << "Wurfnummer: " << versuch << endl;
            cout << "Gew\x81 \brfelt:" << endl;
            io.wuerfelAusgeben(wuerfelbecher);
            cout << "Ergebnis:" << endl;
            io.wuerfelAusgeben(ergebnis);
        }
    }
}
