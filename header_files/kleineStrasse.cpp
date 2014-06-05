#include "kleineStrasse.h"

KleineStrasse::KleineStrasse()
: Kategorie("Kleine Stra\xE1 \be") {
    //std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

KleineStrasse::~KleineStrasse() {
    //std::cout << getName() << "-Objekt wurde beendet.\n";
}

unsigned int KleineStrasse::punkteBerechnen(const std::vector<unsigned int> &augen) {
    std::vector<unsigned int> temp = augen;
    //doppelte Werte loeschen
    std::vector<unsigned int>::iterator it;
    it = std::unique(temp.begin(), temp.end());
    temp.resize(std::distance(temp.begin(), it));
    std::sort(temp.begin(), temp.end());
    if (temp.size() >= 4) {
        unsigned int zaehler = 0;
        for (size_t i = 0; i < 3; i++) {
            if ((temp.at(i) + 1) != (temp.at(i + 1))) {
                if (zaehler == 0) {
                    zaehler++;
                } else {
                    return 0;
                }
            }
        }
        gesetzt = true;
        std::cout << "Kleine Stra\xE1 \be: ";
        return punktzahl = 30;
    } else {
        std::cout << "Keine Kleine Stra\xE1 \be (1-2-3-4 / 2-3-4-5 / 3-4-5-6)" << std::endl;
        return punktzahl;
    }
}
