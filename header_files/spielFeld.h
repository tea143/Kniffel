/*
 * spielFeld.h
 *
 *  Created on: 08.05.2014
 *      Author: Larisa
 */

#ifndef SPIELFELD_H_
#define SPIELFELD_H_
#define SPIELRUNDEN 13
#include <vector>
#include "spieler.h"

class SpielFeld {
public:

	SpielFeld(unsigned int anzahl);
	const unsigned int getSpielerAnzahl() const;
	std::vector <Spieler> spielerKreieren();
	void spielen();
	void ergebnisErmitteln();
	void spielerAnzeigen();
        const std::vector<Spieler>& getSpielerListe() const;

private:
	unsigned int spielerAnzahl;
        std::vector<Spieler> spielerListe;
        std::vector<int> wuerfel;
};

#endif /* SPIELFELD_H_ */
