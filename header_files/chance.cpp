#include "chance.h"

Chance::Chance()
	:name {"Chance"} {
	//std::cout << "Chance-Objekt wurde erzeugt.\n";
}

Chance::~Chance() {
	//std::cout << "Chance-Objekt wurde beendet.\n";
}

int Chance::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    std::vector<int> temp = augen;

    std::cout << name;
    for (size_t i = 0; i < temp.size(); i++) {
        punktzahl = punktzahl + temp[i];
    }
    return punktzahl;
}

const std::string& Chance::getName() const {
    return name;
}

void Chance::setName(const std::string& name) {
    this->name = name;
}

void Chance::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Chance::getPunktzahl() const {
    return punktzahl;
}
