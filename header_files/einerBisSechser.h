/*
 * einerBisSechser.h
 *
 *  Created on: 19.05.2014
 *      Author: Larisa
 */

#ifndef EINERBISSECHSER_H_
#define EINERBISSECHSER_H_

#include "kategorie.h"

class EinerBisSechser: public Kategorie {

	int punkteBerechnen(std::vector<int> augen) {
		int summeAllerGleichenZahlen = 0;
			std::vector<int> temp = augen;
			std::string bezeichner;
			if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
				if (temp[0] == 1) {
					bezeichner = "Einer";
				} else if (temp[0] == 2) {
					bezeichner = "Zweier";
				} else if (temp[0] == 3) {
					bezeichner = "Dreier";
				} else if (temp[0] == 4) {
					bezeichner = "Vierer";
				} else if (temp[0] == 5) {
					bezeichner = "Fünfer";
				} else if (temp[0] == 6) {
					bezeichner = "Sechser";
				}
				std::cout << bezeichner << std::endl;
				for (size_t i = 0; i < temp.size(); ++i) {
					summeAllerGleichenZahlen = summeAllerGleichenZahlen + temp[0];
				}
				return summeAllerGleichenZahlen;
			}
			return 0;
	}
};


#endif /* EINERBISSECHSER_H_ */
