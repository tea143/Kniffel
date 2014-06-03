#include "chance.h"

Chance::Chance()
	: Kategorie("Chance"), gesetzt {false} {
}

Chance::~Chance() {
	std::cout << getName() << "-Objekt wurde beendet.\n";
}

int Chance::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    gesetzt = true;
    std::vector<int> temp = augen;
    for (size_t i = 0; i < temp.size(); i++) {
        punktzahl = punktzahl + temp[i];
    }
    return punktzahl;
}
