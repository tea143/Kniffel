/*
 * spielFeld.h
 *
 *  Created on: 08.05.2014
 *      Author: IFI
 */

#ifndef SPIELFELD_H_
#define SPIELFELD_H_

#define SPIELRUNDEN 13

#include <cstddef>

#include "spieler.h"
#include "einAusgabe.h"
#include "wuerfelbecher.h"

class SpielFeld {
public:
    //Konstruktor:
    SpielFeld(unsigned int);
    //Destruktor:
    ~SpielFeld();

    unsigned int getSpielerAnzahl() const;
    const std::vector<Spieler>& getSpielerListe() const;
    void spielerKreieren();
    void spielerAnzeigen() const;
    void spielen();
    void ergebnisErmitteln();
    void spielfeldAufraeumen();

private:
    unsigned int spielerAnzahl;
    EinAusgabe io;
    std::vector<Spieler> spielerListe;
};

#endif /* SPIELFELD_H_ */
