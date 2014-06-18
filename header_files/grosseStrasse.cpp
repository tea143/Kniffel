#include "grosseStrasse.h"

GrosseStrasse::GrosseStrasse()
	: Kategorie("Gro\xE1 \be Stra\xE1 \be"){
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

GrosseStrasse::~GrosseStrasse() {
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

/**
 * Diese Methode, welche von der abstrakten Kategorie-Klasse erhalten wird,
 * wird ueberschrieben, um die Punktezahl fuer GrosseStrasse-Kategorie zu berechnen.
 * \param augen - Vektor um Augen zu berechnen
 * \return punktzahl - berechnete Punktezahl wird zurueckgegeben
 */
unsigned int GrosseStrasse::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
    std::vector<unsigned int> temp = augen;
    std::sort(temp.begin(), temp.end());
    for (size_t i = 0; i < 4; i++) {
        if ((temp.at(i) + 1) != (temp.at(i + 1))) {
            return punktzahl;
        }
    }
    return punktzahl = 40;
}

