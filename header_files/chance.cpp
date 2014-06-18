#include "chance.h"

Chance::Chance()
: Kategorie("Chance") {
    //std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

Chance::~Chance() {
    //std::cout << getName() << "-Objekt wurde beendet.\n";
}

/**
 * Diese Methode, welche von der abstrakten Kategorie-Klasse erhalten wird,
 * wird ueberschrieben, um die Punktezahl fuer Chance-Kategorie zu berechnen.
 * \param augen - Vektor um Augen zu berechnen
 * \return punktzahl - berechnete Punktezahl wird zurueckgegeben
 */
unsigned int Chance::punkteBerechnen(const std::vector<unsigned int> &augen) {
    gesetzt = true;
    std::vector<unsigned int> temp = augen;
    for (size_t i = 0; i < temp.size(); i++) {
        punktzahl = punktzahl + temp[i];
    }
    return punktzahl;
}
