/*
 * wuerfelbecher.cpp
 *
 *  Created on: 21.05.2014
 *      Author: IFI
 */

#include "wuerfelbecher.h"

using namespace std;

Wuerfelbecher::Wuerfelbecher() {
    //std::cout << "W\x81 \brfelbecher-Objekt wurde erzeugt.\n";
}

Wuerfelbecher::~Wuerfelbecher() {
    //std::cout << "W\x81 \brfelbecher-Objekt wurde beendet.\n";
}

vector<unsigned int> Wuerfelbecher::schuetteln(unsigned int anzahlWuerfel) {
    wuerfelbecher.clear();
    for (size_t i = 0; i < static_cast<unsigned> (anzahlWuerfel); i++) {
        wuerfelbecher.push_back(Zufallszahl::rnd(1, 6));
    }
    return wuerfelbecher;
}

void Wuerfelbecher::wuerfelAuswaehlen() {
    unsigned int nummer;
    for (size_t i = 0; i < wuerfelbecher.size(); i++) {
        cout << "Gib eine W\x81 \brfelnummer ein:" << endl;
        nummer = io.readNumberBetween(1, 5);
        ergebnis.insert(ergebnis.begin() + (nummer - 1), wuerfelbecher.at(i));
        ergebnis.erase(ergebnis.begin() + nummer);
    }
}

const vector<unsigned int>& Wuerfelbecher::getErgebnis() const {
    return ergebnis;
}

void Wuerfelbecher::wuerfeln() {
    unsigned int anzahl;
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
            } while (antwort != 'j' && antwort != 'n');
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
