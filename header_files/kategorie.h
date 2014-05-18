/*
 * kategorie.h
 *
 *  Created on: 17.05.2014
 *      Author: Larisa
 */

#ifndef KATEGORIE_H_
#define KATEGORIE_H_

#include <string>
#include <vector>
#include <unordered_map>
#include "kategorie.h"

class Kategorie {

public:
	Kategorie() {}

	~Kategorie() {}

	int punkteBerechnen(std::vector<int> augen);

	int berechneEinerBisFuenfer(std::vector<int> augen);

	int berechneDreierPasch(std::vector<int> augen);

	int berechneViererPasch(std::vector<int> augen);

	int berechneAlleAugen(std::vector<int> augen);

};


#endif /* KATEGORIE_H_ */
