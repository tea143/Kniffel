/*
 * fullhouse.h
 *
 *  Created on: 20.05.2014
 *      Author: IFI
 */

#ifndef FULLHOUSE_H_
#define FULLHOUSE_H_

#include "kategorie.h"

class Fullhouse: public Kategorie {

public:
	//Konstruktor:
    Fullhouse();
    //Destruktor:
    ~Fullhouse();

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



#endif /* FULLHOUSE_H_ */
