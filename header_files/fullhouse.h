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
    Fullhouse();
    ~Fullhouse();
    int punkteBerechnen(const std::vector<int>&);

};



#endif /* FULLHOUSE_H_ */
