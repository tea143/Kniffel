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
    SpielFeld(size_t);
    //Destruktor:
    ~SpielFeld();

    const size_t getSpielerAnzahl() const;
    const std::vector<Spieler>& getSpielerListe() const;
    std::vector<Spieler>& spielerKreieren();
    void spielerAnzeigen();
    void spielen();
    void ergebnisErmitteln();
    void spielfeldAufraemen(std::vector<Spieler> spielerListe);

private:
    size_t spielerAnzahl;
    EinAusgabe io;
    std::vector<Spieler> spielerListe;
};

#endif /* SPIELFELD_H_ */
