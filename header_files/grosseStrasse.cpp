#include "grosseStrasse.h"

GrosseStrasse::GrosseStrasse()
	:name {"GrosseStrasse"}{
	//std::cout << "GrosseStrasse-Objekt wurde erzeugt.\n";
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
            std::cout << "Keine Grosse Strasse (1-2-3-4-5 / 2-3-4-5-6)" << std::endl;
            return 0;
        }
    }
    std::cout << "Grosse Strasse: ";
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
