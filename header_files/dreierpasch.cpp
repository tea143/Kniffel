#include "dreierpasch.h"

Dreierpasch::Dreierpasch()
	: Kategorie("Dreierpasch"){
}
        
Dreierpasch::~Dreierpasch() {
}

int Dreierpasch::punkteBerechnen(const std::vector<int> &augen) {
    gesetzt = true;
    wuerfelAugen = augen;
    std::sort(wuerfelAugen.begin(), wuerfelAugen.end());
    if (wuerfelGleich(0, 1, 2) || wuerfelGleich(1, 2, 3) || wuerfelGleich(2, 3, 4)) {
        for (size_t i = 0; i < wuerfelAugen.size(); i++) {
            punktzahl = punktzahl + wuerfelAugen[i];
        }
        return punktzahl;
    }
    return 0;
}


bool Dreierpasch::wuerfelGleich(int index1, int index2, int index3) {
    return wuerfelAugen[index1] == wuerfelAugen[index2] && wuerfelAugen[index2] == wuerfelAugen[index3];
}
