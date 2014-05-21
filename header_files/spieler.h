/*
 * spieler.h
 *
 *  Created on: 08.05.2014
 *      Author: Larisa
 */

#ifndef SPIELER_H_
#define SPIELER_H_
#include <string>
#include <vector>
#include "kategorie.h"
#include "einerBisSechser.h"
#include "dreierpasch.h"
#include "viererpasch.h"
#include "fullHouse.h"
#include "grosseStrasse.h"
#include "kleineStrasse.h"
#include "kniffel.h"
#include "chance.h"

class Spieler {
public:

	Spieler(const std::string& n);

	const std::string& getName() const;
        const int getPunktzahl() const;
        void punktzahlErmitteln(int kategorie, const std::vector<int> wuerfel);
        const std::vector<Kategorie*>& getKategorienListe() const;
        void printFreieKategorien() const;
	void setName(const std::string& name);

private:
	std::string name;
        std::vector<Kategorie*> kategorienListe;
        int punktzahl;
};


#endif /* SPIELER_H_ */
