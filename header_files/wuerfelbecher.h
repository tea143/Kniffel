/*
 *  @file: wuerfelbecher.h
 *
 *  @date: 20.05.2014
 *  @author: IFI
 */

#ifndef WUERFELBECHER_H_
#define WUERFELBECHER_H_

#include <stdio.h>
#include <algorithm>

#include "einAusgabe.h"
#include "zufallszahl.h"

/**
 * Die Klasse ist der Konstruktor für cpp.
 */
class Wuerfelbecher {
public:
    Wuerfelbecher();
    ~Wuerfelbecher();

    void wuerfeln();
    const std::vector<unsigned int>& getErgebnis() const;

private:
    std::vector<unsigned int> ergebnis;
    std::vector<unsigned int> wuerfelbecher;
    std::vector<unsigned int> schuetteln(unsigned int);
    EinAusgabe io;
    void wuerfelAuswaehlen();
};

#endif /* WUERFELBECHER_H_ */
