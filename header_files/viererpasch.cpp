#include "viererpasch.h"

Viererpasch::Viererpasch() :
		Kategorie("Viererpasch") {
	//std::cout << getName() << "-Objekt wurde erzeugt.\n";
}

Viererpasch::~Viererpasch() {
	//std::cout << getName() << "-Objekt wurde beendet.\n";
}

/**
 *	Diese Methode, welche von der abstrakten Kategorie-Klasse erhalten wird,
 *	wird ueberschrieben, um die Punktezahl fuer Viererpasch-Kategorie zu berechnen.
 * \param augen - Vektor mit Augen zu berechnen
 * \return punktzahl - berechnete Punktezahl wird zurueckgegeben
 */
unsigned int Viererpasch::punkteBerechnen(const std::vector<unsigned int> &augen) {
	gesetzt = true;
	std::vector<unsigned int> temp = augen;
	std::sort(temp.begin(), temp.end());

	if (wuerfelGleich(temp, 0, 1, 2, 3) || wuerfelGleich(temp, 1, 2, 3, 4)) {
		for (size_t i = 0; i < temp.size(); i++) {
			punktzahl = punktzahl + temp[i];
		}
		return punktzahl;
	}
	return punktzahl;
}

/**
 * Diese Methode ist eine Hilfsmethode, welche innerhalb der punkteBerechnen() Methode aufgerufen wird.
 * Diese Methode dient dazu, um zu ueberpruefen, ob index1, index2, index3 und index4 gleich sind.
 * Falls "ja" wird "true" zurueckgegeben.
 * Falls "nein" wird "false" zurueckgegeben.
 *
 * \param wuerfelAugen - Vektor mit wuerfelAugen zu vergleichen
 * \param index1 - Indexnummer im Vektor mit wuerfelAugen
 * \param index2 - Indexnummer im Vektor mit wuerfelAugen
 * \param index3 - Indexnummer im Vektor mit wuerfelAugen
 * \param index4 - Indexnummer im Vektor mit wuerfelAugen
 * \return "true" oder "false"
 */
bool Viererpasch::wuerfelGleich(std::vector<unsigned int> wuerfelAugen,
		unsigned int index1, unsigned int index2, unsigned int index3,
		unsigned int index4) {
	return wuerfelAugen[index1] == wuerfelAugen[index2]
			&& wuerfelAugen[index2] == wuerfelAugen[index3]
			&& wuerfelAugen[index3] == wuerfelAugen[index4];
}

