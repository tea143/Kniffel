/*
 * spielFeld.h
 *
 *  Created on: 08.05.2014
 *      Author: IFI
 */

#ifndef SPIELFELD_H_
#define SPIELFELD_H_

#define SPIELRUNDEN 13

#include <stdio.h>
#include <cstddef>

#include "spieler.h"
#include "einAusgabe.h"
#include "wuerfelbecher.h"

class SpielFeld {
public:
    //Konstruktor:
    SpielFeld(size_t);
    //Destruktor:
    ~SpielFeld();

    const size_t getSpielerAnzahl() const;
    std::vector<Spieler>& spielerKreieren();
    void spielen();
    void ergebnisErmitteln();
    void spielerAnzeigen();
    const std::vector<Spieler>& getSpielerListe() const;

private:
    size_t spielerAnzahl;
    std::vector<Spieler> spielerListe;
};

#endif /* SPIELFELD_H_ */
