/*
 * kategorieListe.h
 *
 *  Created on: 19.05.2014
 *      Author: Larisa
 */

#ifndef KATEGORIELISTE_H_
#define KATEGORIELISTE_H_

#include <vector>
#include "kategorie.h"

class KategorieListe {

public:
	KategorieListe(const std::vector<Kategorie*> k, const std::vector<int> augen_)
	:kategorie{k},
	 augen{augen_}{

	}

	int nutzenPunkteBerechnen() {
		int summe = 0;
		for (auto k : kategorie) {
			summe += k->punkteBerechnen(augen);
			if (summe != 0) {
				return summe;
			}
		}
		return summe;
	}

private:
	std::vector<Kategorie*> kategorie;
	std::vector<int> augen;
};


#endif /* KATEGORIELISTE_H_ */
