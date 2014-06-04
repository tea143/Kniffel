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
    Chance();
    ~Chance();
    virtual unsigned int punkteBerechnen(const std::vector<unsigned int>&) override;
};


#endif /* CHANCE_H_ */
