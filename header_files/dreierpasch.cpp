#include "dreierpasch.h"
using namespace std;

Dreierpasch::Dreierpasch()
	: Kategorie("Dreierpasch"){
}
        
Dreierpasch::~Dreierpasch() {
}

int Dreierpasch::punkteBerechnen(const vector<int> &augen) {
    punktzahl=0;
	gesetzt = true;
    std::sort(augen.begin(), augen.end());
    if (wuerfelGleich(0, 1, 2, augen) || wuerfelGleich(1, 2, 3, augen) || wuerfelGleich(2, 3, 4, augen)) {
        for (size_t i = 0; i < augen.size(); i++) {
            punktzahl = punktzahl + augen[i];
        }
    }
    return punktzahl;
}


bool Dreierpasch::wuerfelGleich(int index1, int index2, int index3, const vector<int> &augen) {
    return augen[index1] == augen[index2] && augen[index2] == augen[index3];
}
