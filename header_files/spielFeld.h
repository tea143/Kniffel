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
#include <memory>

#include "spieler.h"
#include "einAusgabe.h"
#include "wuerfelbecher.h"

class SpielFeld {
public:
    SpielFeld();
    ~SpielFeld();
    void spielerKreieren();
    void spielen();
    void ergebnisErmitteln();

private:
    EinAusgabe io;
    std::vector<std::unique_ptr<Spieler>> spielerListe;
};

#endif /* SPIELFELD_H_ */
