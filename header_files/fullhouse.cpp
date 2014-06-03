#include "fullhouse.h"

Fullhouse::Fullhouse()
	: Kategorie("Fullhouse") {
}

Fullhouse::~Fullhouse(){
	std::cout << getName() << "-Objekt wurde beendet.\n";
}

int Fullhouse::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    std::vector<int> temp = augen;
    std::sort(temp.begin(), temp.end());
    if ((temp[0] == temp[1] && temp[1] == temp[2] && temp[3] == temp[4]) ||
            (temp[0] == temp[1] && temp[2] == temp[3] && temp[3] == temp[4])) {
        std::cout << "Full House: ";
        return punktzahl = 25;
    } else {
        std::cout << "Kein Full House (Zweierpasch + Dreierpasch)" << std::endl;
    }

    return 0;
}
