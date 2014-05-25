/*
 * wuerfelbecher.cpp
 *
 *  Created on: 21.05.2014
 *      Author: IFI
 */

#include "wuerfelbecher.h"
using namespace std;

Wuerfelbecher::Wuerfelbecher() {
	cout << "W\x81 \brfelbecher-Objekt wurde erzeugt.\n";
}

Wuerfelbecher::~Wuerfelbecher() {
	cout << "W\x81 \brfelbecher-Objekt wurde beendet.\n";
}

// Erzeugt einen Array definierte Goesse mit Zahlen

vector<int> Wuerfelbecher::schuetteln(int anzahlWuerfel) {
    // Becher leeren
    vector<int> wuerfelbecher(0);
    for (size_t i = 0; i < static_cast<unsigned>(anzahlWuerfel); i++) {
        wuerfelbecher.push_back(Zufallszahl::rnd(1, 6));
    }
    return wuerfelbecher;
}

const vector<int>& Wuerfelbecher::getErgebnis() const {
    return ergebnis;
}


// Gibt der Array aus

void Wuerfelbecher::ausgabe(vector<int> name) {
    //Ergebnis sortieren
    sort(Wuerfelbecher::ergebnis.begin(), Wuerfelbecher::ergebnis.end());
    // ASCII Code fuer obere Reihe - Wuerfelbegrenzung
    for (int a = 0; a < (int) name.size(); a++) {
        printf("%c", 218);
        printf("%c", 196);
        printf("%c\t", 191);
    }
    printf("\n");
    // Mittlere Reihe - Wuerfelseiten + Zahl
    for (int a = 0; a < (int) name.size(); a++) {
        printf("%c", 179);
        printf("%d", name[a]);
        printf("%c\t", 179);
    }
    printf("\n");
    // ASCII Code fuer untere Reihe - Wuerfelbegrenzung
    for (int a = 0; a < (int) name.size(); a++) {
        printf("%c", 192);
        printf("%c", 196);
        printf("%c\t", 217);
    }
    printf("\n");
    // Wuerfelnummern
    printf("Nummern\n");
    for (int a = 0; a < (int) name.size(); a++) {
        printf(" %d \t", a + 1);
    }
}

void Wuerfelbecher::wuerfeln() {
    EinAusgabe io;
    int anzahl;
    int nummer;
    char antwort;
    vector<int> wuerfelbecher;
    for (size_t versuch = 1; versuch < 4; versuch++) {
        if (versuch == 1) {
            anzahl = 5;
            wuerfelbecher = schuetteln(anzahl);
            ergebnis = wuerfelbecher;
        } else {
            cout << "M\x94 \bchtest du weiter w\x81 \brfeln? j/n:" << endl;
            cin >> antwort;
            fflush(stdin);
            printf("\n");
            if (antwort == 'j') {
                cout << "Mit wie vielen W\x81 \brfel m\x94 \bchtest du w\x81 \brfeln?" << endl;
                anzahl = io.readNumberBetween(1, 5);
                wuerfelbecher = schuetteln(anzahl);
                for (size_t i = 0; i < wuerfelbecher.size(); i++) {
                    cout << "Gib eine W\x81 \brfelnummer ein:" << endl;
                    nummer = io.readNumberBetween(1, 5);
                    ergebnis.insert(ergebnis.begin() + (nummer - 1), wuerfelbecher.at(i));
                    ergebnis.erase(ergebnis.begin() + nummer);
                }
            } else {
                versuch = 4;
            }
        }
        if (versuch != 4) {
            printf("Wurfnummer: %d\n", versuch);
            printf("Gew\x81 \brfelt:\n");
            ausgabe(wuerfelbecher);
            printf("\n\n");
            // Was im Ergebnis steht - sortiert
            printf("Ergebnis:\n");
            ausgabe(ergebnis);
            printf("\n\n");
        }
    }
}
