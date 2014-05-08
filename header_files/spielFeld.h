/*
 * spielFeld.h
 *
 *  Created on: 08.05.2014
 *      Author: Larisa
 */

#ifndef SPIELFELD_H_
#define SPIELFELD_H_

#include <vector>
#include "spieler.h"

class SpielFeld {
public:

	SpielFeld(unsigned int anzahl)
		: spielerAnzahl {anzahl} {}

	unsigned int getSpielerAnzahl() const {
		return spielerAnzahl;
	}

	std::vector <Spieler> spielerKreieren();
	//spielStarten();
	//ergebnisErmitteln();
	void spielerAnzeigen(std::vector<Spieler>);

private:
	unsigned int spielerAnzahl;

};

#endif /* SPIELFELD_H_ */
