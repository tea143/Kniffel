/*
 * spieler.h
 *
 *  Created on: 08.05.2014
 *      Author: IFI
 */

#ifndef SPIELER_H_
#define SPIELER_H_

#include "kategorie.h"
#include "einerBisSechser.h"
#include "dreierpasch.h"
#include "viererpasch.h"
#include "fullhouse.h"
#include "grosseStrasse.h"
#include "kleineStrasse.h"
#include "kniffel.h"
#include "chance.h"

class Spieler {

public:
	//Konstruktor:
	Spieler(const std::string& n);
	//Destruktor:
	~Spieler();

	const std::string& getName() const;
        const int getPunktzahl() const;
        void punktzahlErmitteln(int kategorie, const std::vector<int> wuerfel);
        void bonusErmitteln();
        const std::vector<Kategorie*>& getKategorienListe() const;
        void printFreieKategorien() const;
	void setName(const std::string& name);

private:
	std::string name;
        std::vector<Kategorie*> kategorienListe;
        int punktzahl = 0;
};


#endif /* SPIELER_H_ */
