#include "fullhouse.h"

Fullhouse::Fullhouse()
	: Kategorie("Fullhouse") {
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

Fullhouse::~Fullhouse(){
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

unsigned int Fullhouse::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
    std::vector<unsigned int> temp = augen;
    std::sort(temp.begin(), temp.end());
    if ((temp[0] == temp[1] && temp[1] == temp[2] && temp[3] == temp[4]) ||
            (temp[0] == temp[1] && temp[2] == temp[3] && temp[3] == temp[4])) {
        std::cout << "Full House: ";
        return punktzahl = 25;
    } else {
        std::cout << "Kein Full House (Zweierpasch + Dreierpasch)" << std::endl;
    }
    return punktzahl;
}
