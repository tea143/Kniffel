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
 * Nimmt bestimmte Anzahl der W�rfel entgegen und pr�sentiert eine zuf�llige Mischung
 * @param anzahlWuerfel - int: Anzahl W�rfel, die gew�rfel wurden
 * @return wuerfelbecher - vector<int>, Vector mit gerade gew�rfelten W�rfel
 */
vector<int> Wuerfelbecher::schuetteln(int anzahlWuerfel) {
    wuerfelbecher.clear();
    for (size_t i = 0; i < static_cast<unsigned> (anzahlWuerfel); i++) {
        wuerfelbecher.push_back(Zufallszahl::rnd(1, 6));
    }
    return wuerfelbecher;
}

/**
 * Fragt der Benutzer nach, mit wie viele W�rfeln er weiter spielen m�chte.
 * Die ausgew�hlte Stellen, werden im Ergebnis �berschrieben
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
 * @return ergebnis - vector<int>, der Vector mit Endergebnissen
 */
const vector<int>& Wuerfelbecher::getErgebnis() const {
    return ergebnis;
}

/**
 * Der Spieler hat 3 Versuche um seine W�rfelkombination zu w�hlen.
 * Im ersten Versuch werden alle 5 W�rfel benutzt. Sp�ter wird der Benutzer gefragt,
 * ob er weiterhin w�rfel will oder der Ergebnis aufschreiben will.
 * Am Ende jedes Durchgangs werden die W�rfel angezeigt, der Spieler gerade gew�rfelt hat (unsortiert) und der Ergebnis dieser Runde (sortiert)
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
                if (anzahl < 5) {
                	wuerfelAuswaehlen();
				}
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
