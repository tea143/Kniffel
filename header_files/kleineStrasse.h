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
    KleineStrasse();
    ~KleineStrasse();
    int punkteBerechnen(const std::vector<int>&);

};



#endif /* KLEINESTRASSE_H_ */
