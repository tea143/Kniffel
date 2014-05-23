/*
 * spielFeld.h
 *
 *  Created on: 08.05.2014
 *      Author: Larisa
 */

#ifndef SPIELFELD_H_
#define SPIELFELD_H_

#define SPIELRUNDEN 13
#include <iostream>

#include <stdio.h>
#include <algorithm>

#include <vector>
#include <cstddef>
#include <string>
#include "spielfeld.h"
#include "spieler.h"
#include "EinAusgabe.h"
#include "spieler.h"

class SpielFeld {
public:

	SpielFeld(size_t anzahl);
	const size_t getSpielerAnzahl() const;
	std::vector <Spieler> spielerKreieren();
	void spielen();
	void ergebnisErmitteln();
	void spielerAnzeigen();
        const std::vector<Spieler>& getSpielerListe() const;

private:
	size_t spielerAnzahl;
        std::vector<Spieler> spielerListe;
        std::vector<int> wuerfel;
};

#endif /* SPIELFELD_H_ */
