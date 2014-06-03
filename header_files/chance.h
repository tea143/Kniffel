/*
 * chance.h
 *
 *  Created on: 19.05.2014
 *      Author: IFI
 */

#ifndef CHANCE_H_
#define CHANCE_H_

#include "kategorie.h"

class Chance : public Kategorie {
public:
	//Konstruktor:
    Chance();
    //Destruktor:
    ~Chance();

    virtual int punkteBerechnen(const std::vector<int>&) override;

private:
    //???
    //diese Variable ist bereits in der Kategorie-Klasse deklariert & initialisiert
    bool gesetzt;
};


#endif /* CHANCE_H_ */
