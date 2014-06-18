#include "kleineStrasse.h"

KleineStrasse::KleineStrasse()
: Kategorie("Kleine Stra\xE1 \be") {
    //std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

KleineStrasse::~KleineStrasse() {
    //std::cout << getName() << "-Objekt wurde beendet.\n";
}

/**
 * Diese Methode, welche von der abstrakten Kategorie-Klasse erhalten wird,
 * wird ueberschrieben, um die Punktezahl fuer KleineStrasse-Kategorie zu berechnen.
 * \param augen - Vektor um Augen zu berechnen
 * \return punktzahl - berechnete Punktezahl wird zurueckgegeben
 */
unsigned int KleineStrasse::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
    std::vector<unsigned int> temp = augen;
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
        return punktzahl = 30;
    } else {
        return punktzahl;
    }
}
