/*
 * Wuerfelbecher.h
 *
 *  Created on: 20.05.2014
 *      Author: Irina Fress
 */

#ifndef WUERFELBECHER_H_
#define WUERFELBECHER_H_

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

#include "EinAusgabe.h"
#include "Zufallszahl.h"
using namespace std;

class Wuerfelbecher {
    // Definieren
public:
    Wuerfelbecher();
    ~Wuerfelbecher();
    void wuerfeln();
    const std::vector<int>& getErgebnis() const;
private:
    vector<int> ergebnis;
    vector<int> schuetteln(int);
    void ausgabe(vector<int>);
    int zahlPruefen(string);
};

#endif /* WUERFELBECHER_H_ */
