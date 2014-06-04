#include "einerBisSechser.h"

EinerBisSechser::EinerBisSechser(unsigned int gesetzteZahl_, std::string name_)
: Kategorie(name_),
  gesetzteZahl{gesetzteZahl_ }
{
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";

}

EinerBisSechser::~EinerBisSechser() {
    //std::cout << getName() << "-Objekt wurde beendet.\n";
}

unsigned int EinerBisSechser::punkteBerechnen(const std::vector<unsigned int> &augen) {
    punktzahl = 0;
    gesetzt = true;
    std::vector<unsigned int> temp = augen;
    unsigned int gesuchteZahl = gesetzteZahl;
    std::sort(temp.begin(), temp.end());

    for (size_t i = 0; i < temp.size(); i++) {
        if (gesuchteZahl == temp[i]) {
            punktzahl = punktzahl + temp[i];
        }
    }
    return punktzahl;
}

unsigned int EinerBisSechser::getGesetzteZahl() const {
    return gesetzteZahl;
}

void EinerBisSechser::setGesetzteZahl(unsigned int gesetzteZahl) {
    this->gesetzteZahl = gesetzteZahl;
}



