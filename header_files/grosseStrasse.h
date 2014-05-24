/*
 * grosseStrasse.h
 *
 *  Created on: 20.05.2014
 *      Author: IFI
 */

#ifndef GROSSESTRASSE_H_
#define GROSSESTRASSE_H_

#include "kategorie.h"

class GrosseStrasse : public Kategorie {

public:
	//Konstruktor:
    GrosseStrasse();
    //Destruktor:
    ~GrosseStrasse();

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



#endif /* GROSSESTRASSE_H_ */
