#include "kleineStrasse.h"

KleineStrasse::KleineStrasse()
	:name {"KleineStrasse"} {
	//std::cout << "KleineStrasse-Objekt wurde erzeugt.\n";
}

KleineStrasse::~KleineStrasse() {
	//std::cout << "KleineStrasse-Objekt wurde beendet.\n";
}

int KleineStrasse::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    std::vector<int> temp = augen;

    //doppelte Werte loeschen
    std::vector<int>::iterator it;
    it = std::unique(temp.begin(), temp.end());
    temp.resize(std::distance(temp.begin(), it));
    sort(temp.begin(), temp.end());
    if (temp.size() >= 4) {
        size_t zaehler = 0;
        for (size_t i = 0; i < 3; i++) {
            if ((temp.at(i) + 1) != (temp.at(i + 1))) {
                if (zaehler == 0) {
                    zaehler++;
                } else {
                    std::cout << "Keine Kleine Strasse (1-2-3-4 / 2-3-4-5 / 3-4-5-6)" << std::endl;
                    return 0;
                }
            }
        }
        std::cout << "Kleine Strasse: ";
        return punktzahl = 30;
    } else {
        std::cout << "Keine Kleine Strasse (1-2-3-4 / 2-3-4-5 / 3-4-5-6)" << std::endl;
        return 0;
    }
}

const std::string& KleineStrasse::getName() const {
    return name;
}

void KleineStrasse::setName(const std::string& name) {
    this->name = name;
}

void KleineStrasse::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int KleineStrasse::getPunktzahl() const {
    return punktzahl;
}
