#include "dreierpasch.h"

using namespace std;

Dreierpasch::Dreierpasch() : name {
    "Dreierpasch"
}
{

}

int Dreierpasch::punkteBerechnen(const vector<int> &augen) {
    punktzahl = 0;
    gesetzt = true;
    wuerfelAugen = augen;
    sort(wuerfelAugen.begin(), wuerfelAugen.end(), greater<int>());

    if (wuerfelGleich(0, 1, 2) || wuerfelGleich(1, 2, 3) || wuerfelGleich(2, 3, 4)) {
        for (size_t i = 0; i < wuerfelAugen.size(); i++) {
            punktzahl = punktzahl + wuerfelAugen[i];
        }
        return punktzahl;
    }
    return 0;
}

const string& Dreierpasch::getName() const {
    return name;
}

void Dreierpasch::setName(const string& name) {
    this->name = name;
}

void Dreierpasch::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Dreierpasch::getPunktzahl() const {
    return punktzahl;
}

bool Dreierpasch::wuerfelGleich(int index1, int index2, int index3) {
    return wuerfelAugen[index1] == wuerfelAugen[index2] && wuerfelAugen[index2] == wuerfelAugen[index3];
}