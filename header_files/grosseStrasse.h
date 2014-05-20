/*
 * grosseStrasse.h
 *
 *  Created on: 20.05.2014
 *      Author: Frieda
 */

#ifndef GROSSESTRASSE_H_
#define GROSSESTRASSE_H_

#include "kategorie.h"

class GrosseStrasse: public Kategorie {

	int punkteBerechnen(std::vector<int> augen) {
		int punkte = 0;
		std::vector<int> temp = augen;

		for(size_t i = 0; i < 4; i++) {
			if((temp[i] + 1) != (temp[i+1])) {
				std::cout << "Keine Große Straße (1-2-3-4-5 / 2-3-4-5-6)" << std::endl;
				return 0;
			}
		}
		std::cout << "Große Straße: ";
		return punkte = 40;
	}
};



#endif /* GROSSESTRASSE_H_ */
