#include "kniffel.h"

Kniffel::Kniffel()
	: Kategorie("Kniffel"){
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

Kniffel::~Kniffel() {
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

/**
 *	Diese Methode, welche von der abstrakten Kategorie-Klasse erhalten wird,
 *	wird ueberschrieben, um die Punktezahl fuer Kniffel-Kategorie zu berechnen.
 * \param augen - Vektor mit Augen zu berechnen
 * \return punktzahl - berechnete Punktezahl wird zurueckgegeben
 */
unsigned int Kniffel::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
    std::vector<unsigned int> temp = augen;
    if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
        return punktzahl = 50;
    }
    return punktzahl;
}
