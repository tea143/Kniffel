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
    //Destruktor
    ~GrosseStrasse();

    virtual unsigned int punkteBerechnen(const std::vector<unsigned int>&) override;
};



#endif /* GROSSESTRASSE_H_ */
