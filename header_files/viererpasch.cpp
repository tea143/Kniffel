#include "viererpasch.h"

Viererpasch::Viererpasch()
	: Kategorie("Viererpasch") {
}

Viererpasch::~Viererpasch() {
	//std::cout << "Viererpasch-Objekt wurde beendet.\n";
}

int Viererpasch::punkteBerechnen(const std::vector<int> &augen) {
    gesetzt = true;
    wuerfelAugen = augen;
    //sort(wuerfelAugen.begin(), wuerfelAugen.end(), greater<int>());
    std::sort(wuerfelAugen.begin(), wuerfelAugen.end());

    if (wuerfelGleich(0,1,2,3) || wuerfelGleich(1,2,3,4)) {
        for (size_t i = 0; i < wuerfelAugen.size(); i++) {
            punktzahl = punktzahl + wuerfelAugen[i];
        }
        return punktzahl;
    }
    return punktzahl;
}


bool Viererpasch::wuerfelGleich(int index1, int index2, int index3, int index4) {
    return wuerfelAugen[index1] == wuerfelAugen[index2] && wuerfelAugen[index2] == wuerfelAugen[index3] && wuerfelAugen[index3] == wuerfelAugen[index4];
}

