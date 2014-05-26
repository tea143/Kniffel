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

size_t EinAusgabe::readNumberBetween(int anfang, int ende) {
    size_t anzahl = 0;
    while (!(cin >> anzahl) || anzahl > static_cast<unsigned>(ende)) {
        cout << "Gibt eine Zahl zwischen " << anfang << " und " << ende << " und ein!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return anzahl;
}

