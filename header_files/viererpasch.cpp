#include "viererpasch.h"
using namespace std;

Viererpasch::Viererpasch()
	: Kategorie("Viererpasch") {
}

Viererpasch::~Viererpasch() {
	//std::cout << "Viererpasch-Objekt wurde beendet.\n";
}

int Viererpasch::punkteBerechnen(const vector<int> &augen) {
    punktzahl = 0;
	gesetzt = true;

    //sort(wuerfelAugen.begin(), wuerfelAugen.end(), greater<int>());
    sort(augen.begin(), augen.end());

    if (wuerfelGleich(0,1,2,3,augen) || wuerfelGleich(1,2,3,4,augen)) {
        for (size_t i = 0; i < augen.size(); i++) {
            punktzahl = punktzahl + augen[i];
        }
    }
    return punktzahl;
}


bool Viererpasch::wuerfelGleich(int index1, int index2, int index3, int index4, const vector<int> &augen) {
    return augen[index1] == augen[index2] && augen[index2] == augen[index3] && augen[index3] == augen[index4];
}

