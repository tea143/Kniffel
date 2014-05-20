#include "viererpasch.h"

using namespace std;

Viererpasch::Viererpasch() : name {
    "Viererpasch"
}
{

}

int Viererpasch::punkteBerechnen(const vector<int> &augen) {
    punktzahl = 0;
    gesetzt = true;
    vector<int> temp = augen;
    sort(temp.begin(), temp.end(), greater<int>());

    if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3]) {
        for (size_t i = 0; i < temp.size(); i++) {
            punktzahl = punktzahl + temp[i];
        }
        return punktzahl;
    }

    if (temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
        for (size_t i = 0; i < temp.size(); i++) {
            punktzahl = punktzahl + temp[i];
        }
        return punktzahl;
    }
    return 0;
}

const string& Viererpasch::getName() const {
    return name;
}

void Viererpasch::setName(const string& name) {
    this->name = name;
}

void Viererpasch::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Viererpasch::getPunktzahl() const {
    return punktzahl;
}

