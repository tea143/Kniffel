#include "viererpasch.h"

Viererpasch::Viererpasch()
	: Kategorie("Viererpasch") {
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

Viererpasch::~Viererpasch() {
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

int Viererpasch::punkteBerechnen(const std::vector<int> &augen) {
    gesetzt = true;
    std::vector<int> temp = augen;
    std::sort(temp.begin(), temp.end());

    if (wuerfelGleich(temp, 0,1,2,3) || wuerfelGleich(temp, 1,2,3,4)) {
        for (size_t i = 0; i < temp.size(); i++) {
            punktzahl = punktzahl + temp[i];
        }
        return punktzahl;
    }
    return punktzahl;
}


bool Viererpasch::wuerfelGleich(std::vector<int> wuerfelAugen, int index1, int index2, int index3, int index4) {
    return wuerfelAugen[index1] == wuerfelAugen[index2] && wuerfelAugen[index2] == wuerfelAugen[index3] && wuerfelAugen[index3] == wuerfelAugen[index4];
}

