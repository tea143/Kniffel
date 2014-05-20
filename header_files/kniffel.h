/*
 * kniffel.h
 *
 *  Created on: 20.05.2014
 *      Author: Frieda
 */

#ifndef KNIFFEL_H_
#define KNIFFEL_H_

#include "kategorie.h"

class Kniffel: public Kategorie {

	int punkteBerechnen(std::vector<int> augen) {
		int punkte = 0;
		std::vector<int> temp = augen;

		if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]){
			std::cout << "Kniffel: ";
			return punkte = 50;
		} else {
			std::cout << "Kein Kniffel (Fünferpasch)" << std::endl;
		}

		return 0;
	}
};



#endif /* KNIFFEL_H_ */
