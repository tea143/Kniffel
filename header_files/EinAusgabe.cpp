/* 
 * File:   EinAusgabe.cpp
 * Author: ASUS
 * 
 * Created on 22. Mai 2014, 19:38
 */

#include "EinAusgabe.h"

using namespace std;

EinAusgabe::EinAusgabe() {
}

EinAusgabe::~EinAusgabe() {
}

size_t EinAusgabe::readNumberBetween(int anfang, int ende) {
    size_t anzahl = 0;
    while (!(cin >> anzahl) || anzahl > ende) {
        cout << "Gibt eine Zahl zwischen " << anfang << " und " << ende << " und ein!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return anzahl;
}

