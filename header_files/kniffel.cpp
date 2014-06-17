#include "kniffel.h"

Kniffel::Kniffel()
	: Kategorie("Kniffel"){
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

Kniffel::~Kniffel() {
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

unsigned int Kniffel::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
    std::vector<unsigned int> temp = augen;
    if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
        return punktzahl = 50;
    }
    return punktzahl;
}
