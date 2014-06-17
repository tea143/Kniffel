/*
 * Wuerfelbecher.h
 *
 *  Created on: 20.05.2014
 *      Author: IFI
 */

#ifndef WUERFELBECHER_H_
#define WUERFELBECHER_H_

#include <stdio.h>
#include <algorithm>

#include "einAusgabe.h"
#include "zufallszahl.h"

class Wuerfelbecher {
public:
    Wuerfelbecher();
    ~Wuerfelbecher();

    void wuerfeln();
    const std::vector<unsigned int>& getErgebnis() const;

private:
    EinAusgabe io;
    std::vector<unsigned int> ergebnis;
    std::vector<unsigned int> wuerfelbecher;
    std::vector<unsigned int> schuetteln(unsigned int);
    void wuerfelAuswaehlen();
};

#endif /* WUERFELBECHER_H_ */
