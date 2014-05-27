#include "grosseStrasse.h"

GrosseStrasse::GrosseStrasse()
	:name {"Gro\xE1 \be_Stra\xE1 \be"}{
	//std::cout << "GrosseStrasse-Objekt wurde erzeugt.\n";
		gesetzt = false;
}

GrosseStrasse::~GrosseStrasse() {
	//std::cout << "GrosseStrasse-Objekt wurde beendet.\n";
}

int GrosseStrasse::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    std::vector<int> temp = augen;
    sort(temp.begin(), temp.end());
    for (size_t i = 0; i < 4; i++) {
        if ((temp.at(i) + 1) != (temp.at(i + 1))) {
            std::cout << "Keine Gro\xE1 \be Stra\xE1 \be (1-2-3-4-5 / 2-3-4-5-6)" << std::endl;
            return 0;
        }
    }
    std::cout << "Gro\xE1 \be Stra\xE1 \be: ";
    return punktzahl = 40;
}

const std::string& GrosseStrasse::getName() const {
    return name;
}

void GrosseStrasse::setName(const std::string& name) {
    this->name = name;
}

void GrosseStrasse::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int GrosseStrasse::getPunktzahl() const {
    return punktzahl;
}
