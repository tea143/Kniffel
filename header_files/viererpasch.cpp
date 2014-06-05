#include "viererpasch.h"

Viererpasch::Viererpasch()
	: Kategorie("Viererpasch") {
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

Viererpasch::~Viererpasch() {
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

unsigned int Viererpasch::punkteBerechnen(const std::vector<unsigned int> &augen) {
    std::vector<unsigned int> temp = augen;
    std::sort(temp.begin(), temp.end());

    if (wuerfelGleich(temp, 0,1,2,3) || wuerfelGleich(temp, 1,2,3,4)) {
        for (size_t i = 0; i < temp.size(); i++) {
            punktzahl = punktzahl + temp[i];
        }
        gesetzt = true;
        return punktzahl;
    }
    return punktzahl;
}


bool Viererpasch::wuerfelGleich(std::vector<unsigned int> wuerfelAugen, unsigned int index1, unsigned int index2, unsigned int index3, unsigned int index4) {
    return wuerfelAugen[index1] == wuerfelAugen[index2] && wuerfelAugen[index2] == wuerfelAugen[index3] && wuerfelAugen[index3] == wuerfelAugen[index4];
}

