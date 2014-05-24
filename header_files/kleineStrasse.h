/*
 * kleineStrasse.h
 *
 *  Created on: 20.05.2014
 *      Author: Frieda
 */

#ifndef KLEINESTRASSE_H_
#define KLEINESTRASSE_H_

#include "kategorie.h"

class KleineStrasse : public Kategorie {

public:
	//Konstruktor:
    KleineStrasse();
    //Destruktor:
    ~KleineStrasse();

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



#endif /* KLEINESTRASSE_H_ */
