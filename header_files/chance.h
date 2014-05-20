/*
 * chance.h
 *
 *  Created on: 19.05.2014
 *      Author: Larisa
 */

#ifndef ALLGEMEIN_H_
#define ALLGEMEIN_H_

#include "kategorie.h"

class Chance: public Kategorie {

	int punkteBerechnen(std::vector<int> augen) {
		int summeAllerAugen = 0;
		std::vector<int> temp = augen;

		std::cout << "Chance: ";
		for (size_t i = 0; i < temp.size(); i++) {
			summeAllerAugen = summeAllerAugen + temp[i];
		}
		return summeAllerAugen;
	}
};


#endif /* ALLGEMEIN_H_ */
