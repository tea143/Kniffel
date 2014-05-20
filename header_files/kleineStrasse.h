/*
 * kleineStrasse.h
 *
 *  Created on: 20.05.2014
 *      Author: Frieda
 */

#ifndef KLEINESTRASSE_H_
#define KLEINESTRASSE_H_

#include "kategorie.h"

class KleineStrasse: public Kategorie {

	int punkteBerechnen(std::vector<int> augen) {
		int punkte = 0;
		std::vector<int> temp = augen;

		//doppelte Werte löschen
		std::vector<int>::iterator it;
		it = std::unique(temp.begin(), temp.end());
		temp.resize(std::distance(temp.begin(),it));

		if(temp.size() >= 4) {
			size_t zaehler = 0;
			for(size_t i = 0; i < 3; i++) {
				if((temp[i] + 1) != (temp[i+1])) {
					if(zaehler == 0) {
						zaehler++;
					} else {
					std::cout << "Keine Kleine Straße (1-2-3-4 / 2-3-4-5 / 3-4-5-6)" << std::endl;
					return 0;
					}
				}
			}
			std::cout << "Kleine Straße: ";
			return punkte = 30;
		} else {
			std::cout << "Keine Kleine Straße (1-2-3-4 / 2-3-4-5 / 3-4-5-6)" << std::endl;
			return 0;
		}
	}
};



#endif /* KLEINESTRASSE_H_ */
