#include "einerBisSechser.h"
using namespace std;

EinerBisSechser::EinerBisSechser(int gesetzteZahl, string name)
: Kategorie(name), gesetzteZahl{gesetzteZahl }
{
    //std::cout << "EinerBisSechser-Objekt wurde erzeugt.\n";

}

EinerBisSechser::~EinerBisSechser() {
    //std::cout << "EinerBisSechser-Objekt wurde beendet.\n";
}

int EinerBisSechser::punkteBerechnen(const vector<int> &augen) {
    punktzahl = 0;
    gesetzt = true;

    int gesuchteZahl = gesetzteZahl;
    sort(augen.begin(), augen.end());

    for (size_t i = 0; i < augen.size(); i++) {
        if (gesuchteZahl == augen[i]) {
            punktzahl = punktzahl + augen[i];
        }
    }
    return punktzahl;
}

int EinerBisSechser::getGesetzteZahl() const {
    return gesetzteZahl;
}

void EinerBisSechser::setGesetzteZahl(int gesetzteZahl) {
    this->gesetzteZahl = gesetzteZahl;
}



