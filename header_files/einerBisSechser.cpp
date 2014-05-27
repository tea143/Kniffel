#include "einerBisSechser.h"

EinerBisSechser::EinerBisSechser(int gesetzteZahl_, std::string name_)
: Kategorie(name_), gesetzteZahl{gesetzteZahl_ }
{
    //std::cout << "EinerBisSechser-Objekt wurde erzeugt.\n";

}

EinerBisSechser::~EinerBisSechser() {
    //std::cout << "EinerBisSechser-Objekt wurde beendet.\n";
}

int EinerBisSechser::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    gesetzt = true;
    wuerfelAugen = augen;
    int gesuchteZahl = gesetzteZahl;
    std::sort(wuerfelAugen.begin(), wuerfelAugen.end());

    for (size_t i = 0; i < wuerfelAugen.size(); i++) {
        if (gesuchteZahl == wuerfelAugen[i]) {
            punktzahl = punktzahl + wuerfelAugen[i];
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



