#include "fullHouse.h"

using namespace std;

Fullhouse::Fullhouse() : name {
    "Fullhouse"
}
{

}

int Fullhouse::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    std::vector<int> temp = augen;
    sort(temp.begin(), temp.end(), greater<int>());
    if ((temp[0] == temp[1] && temp[1] == temp[2] && temp[3] == temp[4]) ||
            (temp[0] == temp[1] && temp[2] == temp[3] && temp[3] == temp[4])) {
        std::cout << "Full House: ";
        return punktzahl = 25;
    } else {
        std::cout << "Kein Full House (Zweierpasch + Dreierpasch)" << std::endl;
    }

    return 0;
}

const string& Fullhouse::getName() const {
    return name;
}

void Fullhouse::setName(const string& name) {
    this->name = name;
}

void Fullhouse::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Fullhouse::getPunktzahl() const {
    return punktzahl;
}
