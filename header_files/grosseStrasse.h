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
    GrosseStrasse();
    ~GrosseStrasse();

    int punkteBerechnen(const std::vector<int>&);
};



#endif /* GROSSESTRASSE_H_ */
