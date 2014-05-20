/*
 * fullHouse.h
 *
 *  Created on: 20.05.2014
 *      Author: Frieda
 */

#ifndef FULLHOUSE_H_
#define FULLHOUSE_H_

#include "kategorie.h"

class Fullhouse: public Kategorie {

	int punkteBerechnen(std::vector<int> augen) {
		int punkte = 0;
		std::vector<int> temp = augen;

		if ((temp[0] == temp[1] && temp[1] == temp[2] && temp[3] == temp[4]) ||
				(temp[0] == temp[1] && temp[2] == temp[3] && temp[3] == temp[4])) {
			std::cout << "Full House: ";
			return punkte = 25;
		} else {
			std::cout << "Kein Full House (Zweierpasch + Dreierpasch)" << std::endl;
		}

		return 0;
	}
};



#endif /* FULLHOUSE_H_ */
