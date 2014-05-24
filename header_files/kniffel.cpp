#include "kniffel.h"

Kniffel::Kniffel()
	:name {"Kniffel"} {
	std::cout << "Kniffel-Objekt wurde erzeugt.\n";
}

Kniffel::~Kniffel() {
	std::cout << "Kniffel-Objekt wurde beendet.\n";
}

int Kniffel::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    std::vector<int> temp = augen;

    if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
        std::cout << "Kniffel: ";
        return punktzahl = 50;
    } else {
        std::cout << "Kein Kniffel (Fuenferpasch)" << std::endl;
    }

    return 0;
}

const std::string& Kniffel::getName() const {
    return name;
}

void Kniffel::setName(const std::string& name) {
    this->name = name;
}

void Kniffel::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Kniffel::getPunktzahl() const {
    return punktzahl;
}
