/*
 * Wuerfelbecher.h
 *
 *  Created on: 20.05.2014
 *      Author: IFI
 */

#ifndef WUERFELBECHER_H_
#define WUERFELBECHER_H_

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

#include "einAusgabe.h"
#include "zufallszahl.h"


class Wuerfelbecher {
    // Definieren
public:
	//Konstruktor:
    Wuerfelbecher();
    //Destruktor:
    ~Wuerfelbecher();

    void wuerfeln();
    const std::vector<int>& getErgebnis() const;

private:
    std::vector<int> ergebnis;
    std::vector<int> schuetteln(int);
    void ausgabe(std::vector<int>);
};

#endif /* WUERFELBECHER_H_ */
