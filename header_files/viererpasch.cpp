#include "viererpasch.h"

Viererpasch::Viererpasch()
	:name {"Viererpasch"}{
		//std::cout << "Viererpasch-Objekt wurde erzeugt.\n";
}

Viererpasch::~Viererpasch() {
	//std::cout << "Viererpasch-Objekt wurde beendet.\n";
}

int Viererpasch::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    gesetzt = true;
    wuerfelAugen = augen;
    //sort(wuerfelAugen.begin(), wuerfelAugen.end(), greater<int>());
    sort(wuerfelAugen.begin(), wuerfelAugen.end());

    if (wuerfelGleich(0,1,2,3) || wuerfelGleich(1,2,3,4)) {
        for (size_t i = 0; i < wuerfelAugen.size(); i++) {
            punktzahl = punktzahl + wuerfelAugen[i];
        }
        return punktzahl;
    }
    return punktzahl;
}

const std::string& Viererpasch::getName() const {
    return name;
}

void Viererpasch::setName(const std::string& name) {
    this->name = name;
}

void Viererpasch::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Viererpasch::getPunktzahl() const {
    return punktzahl;
}

bool Viererpasch::wuerfelGleich(int index1, int index2, int index3, int index4) {
    return wuerfelAugen[index1] == wuerfelAugen[index2] && wuerfelAugen[index2] == wuerfelAugen[index3] && wuerfelAugen[index3] == wuerfelAugen[index4];
}

