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
    Spieler(const std::string&);
    ~Spieler();

    const std::string& getName() const;
    unsigned int getPunktzahl() const;
    bool punktzahlErmitteln(unsigned int, const std::vector<unsigned int>&);
    void bonusErmitteln();
    const std::vector<Kategorie*>& getKategorienListe() const;
    void printFreieKategorien() const;
    void setName(const std::string&);
    void kategorienFreisetzen();

private:
    std::string name;
    std::vector<Kategorie*> kategorienListe;
    //std::vector<bool> kategorieErledigt;
    unsigned int punktzahl = 0;
};


#endif /* SPIELER_H_ */
