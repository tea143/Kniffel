#include "kniffel.h"

using namespace std;

Kniffel::Kniffel() : name {
    "Kniffel"
}
{

}

int Kniffel::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    vector<int> temp = augen;

    if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
        cout << "Kniffel: ";
        return punktzahl = 50;
    } else {
        cout << "Kein Kniffel (Fuenferpasch)" << endl;
    }

    return 0;
}

const string& Kniffel::getName() const {
    return name;
}

void Kniffel::setName(const string& name) {
    this->name = name;
}

void Kniffel::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Kniffel::getPunktzahl() const {
    return punktzahl;
}
