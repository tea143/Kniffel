#include "chance.h"


using namespace std;

Chance::Chance() : name {
    "Chance"
}
{

}

int Chance::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    vector<int> temp = augen;

    cout << "Chance: ";
    for (size_t i = 0; i < temp.size(); i++) {
        punktzahl = punktzahl + temp[i];
    }
    return punktzahl;
}

const string& Chance::getName() const {
    return name;
}

void Chance::setName(const string& name) {
    this->name = name;
}

void Chance::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Chance::getPunktzahl() const {
    return punktzahl;
}