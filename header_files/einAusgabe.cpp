/* 
 * File:   einAusgabe.cpp
 * Author: IFI
 * 
 * Created on 22. Mai 2014, 19:38
 */

#include "einAusgabe.h"

using namespace std;

EinAusgabe::EinAusgabe() {
    //std::cout << "EinAusgabe-Objekt wurde erzeugt.\n";
}

EinAusgabe::~EinAusgabe() {
    //std::cout << "EinAusgabe-Objekt wurde beendet.\n";
}

unsigned int EinAusgabe::readNumberBetween(int anfang, int ende) const {
    unsigned int anzahl = 0;
    while (!(cin >> anzahl) || anzahl > static_cast<unsigned> (ende)) {
        cout << "Gib eine Zahl zwischen " << anfang << " und " << ende << " und ein!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return anzahl;
}

void EinAusgabe::wuerfelAusgeben(vector<unsigned int> zahlen) const{
    // ASCII Code fuer obere Reihe - Wuerfelbegrenzung
    for (size_t a = 0; a < static_cast<unsigned>(zahlen.size()); a++) {
        printf("%c%c%c\t", 218, 196, 191);
    }
    printf("\n");
    // Mittlere Reihe - Wuerfelseiten + Zahl
    for (size_t a = 0; a < static_cast<unsigned>(zahlen.size()); a++) {
        printf("%c%d%c\t", 179, zahlen[a], 179);
    }
    printf("\n");
    // ASCII Code fuer untere Reihe - Wuerfelbegrenzung
    for (size_t a = 0; a < static_cast<unsigned>(zahlen.size()); a++) {
        printf("%c%c%c\t", 192, 196, 217);
    }
    printf("\n");
    printf("Nummern\n");
    for (size_t a = 0; a < static_cast<unsigned>(zahlen.size()); a++) {
        printf(" %d \t", a + 1);
    }
    printf("\n\n");
}

