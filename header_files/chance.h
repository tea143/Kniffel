/*
 * chance.h
 *
 *  Created on: 19.05.2014
 *      Author: Larisa
 */

#ifndef ALLGEMEIN_H_
#define ALLGEMEIN_H_

#include <string>
#include <iostream>
#include <vector>
#include "kategorie.h"

class Chance : public Kategorie {
public:
    Chance();
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


#endif /* ALLGEMEIN_H_ */
