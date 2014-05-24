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

    int punkteBerechnen(const std::vector<int> &augen);
    const std::string& getName() const;
    void setName(const std::string& name);
    void setPunktzahl(int punktzahl);
    int getPunktzahl() const;

private:
    std::string name;
    int punktzahl = 0;
    bool gesetzt;
};


#endif /* CHANCE_H_ */
