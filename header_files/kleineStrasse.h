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

    virtual unsigned int punkteBerechnen(const std::vector<unsigned int>&) override;

};



#endif /* KLEINESTRASSE_H_ */
