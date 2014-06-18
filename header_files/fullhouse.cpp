#include "fullhouse.h"

Fullhouse::Fullhouse()
	: Kategorie("Fullhouse") {
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

Fullhouse::~Fullhouse(){
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

/**
 * Diese Methode, welche von der abstrakten Kategorie-Klasse erhalten wird,
 * wird ueberschrieben, um die Punktezahl fuer Fullhouse-Kategorie zu berechnen.
 * \param augen - Vektor um Augen zu berechnen
 * \return punktzahl - berechnete Punktezahl wird zurueckgegeben
 */
unsigned int Fullhouse::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
    std::vector<unsigned int> temp = augen;
    std::sort(temp.begin(), temp.end());
    if ((temp[0] == temp[1] && temp[1] == temp[2] && temp[3] == temp[4]) ||
            (temp[0] == temp[1] && temp[2] == temp[3] && temp[3] == temp[4])) {
        std::cout << "Full House: ";
        return punktzahl = 25;
    }
    return punktzahl;
}
