/*
 * vierPasch.h
 *
 *  Created on: 19.05.2014
 *      Author: Larisa
 */

#ifndef VIERPASCH_H_
#define VIERPASCH_H_

#include "kategorie.h"

class Vierpasch: public Kategorie {

	int punkteBerechnen(std::vector<int> augen) {
		int summeAllerAugen = 0;
			std::vector<int> temp = augen;
			std::sort(temp.begin(), temp.end());

			if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3]) {
				std::cout << "Viererpasch: ";
				for (size_t i = 0; i < temp.size(); i++) {
					summeAllerAugen = summeAllerAugen + temp[i];
				}
				return summeAllerAugen;
			}

			if (temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
				std::cout << "Viererpasch: ";
				for (size_t i = 0; i < temp.size(); i++) {
					summeAllerAugen = summeAllerAugen + temp[i];
				}
				return summeAllerAugen;
			}
			return 0;
	}
};


#endif /* VIERPASCH_H_ */
