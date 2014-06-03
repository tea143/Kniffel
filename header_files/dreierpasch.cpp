#include "dreierpasch.h"

Dreierpasch::Dreierpasch()
	: Kategorie("Dreierpasch"){
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}
        
Dreierpasch::~Dreierpasch() {
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

int Dreierpasch::punkteBerechnen(const std::vector<int> &augen) {
    gesetzt = true;
    std::vector<int> temp = augen;
    std::sort(temp.begin(), temp.end());
    if (wuerfelGleich(temp, 0, 1, 2) || wuerfelGleich(temp, 1, 2, 3) || wuerfelGleich(temp, 2, 3, 4)) {
        for (size_t i = 0; i < temp.size(); i++) {
            punktzahl = punktzahl + temp[i];
        }
        return punktzahl;
    }
    return 0;
}


bool Dreierpasch::wuerfelGleich(std::vector<int> wuerfelAugen, int index1, int index2, int index3) {
    return wuerfelAugen[index1] == wuerfelAugen[index2] && wuerfelAugen[index2] == wuerfelAugen[index3];
}
