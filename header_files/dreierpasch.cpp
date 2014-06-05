#include "dreierpasch.h"

Dreierpasch::Dreierpasch()
	: Kategorie("Dreierpasch"){
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}
        
Dreierpasch::~Dreierpasch() {
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

unsigned int Dreierpasch::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
    std::vector<unsigned int> temp = augen;
    std::sort(temp.begin(), temp.end());
    if (wuerfelGleich(temp, 0, 1, 2) || wuerfelGleich(temp, 1, 2, 3) || wuerfelGleich(temp, 2, 3, 4)) {
        for (size_t i = 0; i < temp.size(); i++) {
            punktzahl = punktzahl + temp[i];
        }
        return punktzahl;
    }
    return punktzahl;
}


bool Dreierpasch::wuerfelGleich(std::vector<unsigned int> wuerfelAugen, unsigned int index1, unsigned int index2, unsigned int index3) {
    return wuerfelAugen[index1] == wuerfelAugen[index2] && wuerfelAugen[index2] == wuerfelAugen[index3];
}
