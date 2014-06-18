#include "einerBisSechser.h"

EinerBisSechser::EinerBisSechser(unsigned int gesetzteZahl_, std::string name_)
: Kategorie(name_),
  gesetzteZahl{gesetzteZahl_ }
{
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";

}

EinerBisSechser::~EinerBisSechser() {
    //std::cout << getName() << "-Objekt wurde beendet.\n";
}

/**
 * Diese Methode, welche von der abstrakten Kategorie-Klasse erhalten wird,
 * wird ueberschrieben, um die Punktezahl fuer EinerBisSechser-Kategorie zu berechnen.
 * \param augen - Vektor um Augen zu berechnen
 * \return punktzahl - berechnete Punktezahl wird zurueckgegeben
 */
unsigned int EinerBisSechser::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
    std::vector<unsigned int> temp = augen;
    unsigned int gesuchteZahl = gesetzteZahl;
    std::sort(temp.begin(), temp.end());

    for (size_t i = 0; i < temp.size(); i++) {
        if (gesuchteZahl == temp[i]) {
            punktzahl = punktzahl + temp[i];
        }
    }
    return punktzahl;
}

/**
 * Getter-Methode, um zu wissen, welche Kategorie bzw. 1...6 gesetzt wurde.
 * \return gesetzteZahl - wird zurueckgegeben
 */
unsigned int EinerBisSechser::getGesetzteZahl() const {
    return gesetzteZahl;
}

/**
 * Setter-Methode, um Kategorie bzw. 1...6 zu setzen.
 * \param gesetzteZahl - wird gesetzt
 */
void EinerBisSechser::setGesetzteZahl(unsigned int gesetzteZahl) {
    this->gesetzteZahl = gesetzteZahl;
}



