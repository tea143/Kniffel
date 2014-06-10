/*
 *  @file: wuerfelbecher.h
 *
 *  @date: 20.05.2014
 *  @author: IFI
 */

#ifndef WUERFELBECHER_H_
#define WUERFELBECHER_H_

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

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
    const std::vector<int>& getErgebnis() const;

private:
    std::vector<int> ergebnis;
    std::vector<int> wuerfelbecher;
    std::vector<int> schuetteln(int);
    EinAusgabe io;
    void wuerfelAuswaehlen();
};

#endif /* WUERFELBECHER_H_ */
