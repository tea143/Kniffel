/*
 * kniffel.h
 *
 *  Created on: 20.05.2014
 *      Author: Frieda
 */

#ifndef KNIFFEL_H_
#define KNIFFEL_H_

#include "kategorie.h"

class Kniffel : public Kategorie {
public:
    Kniffel();
    ~Kniffel();
    int punkteBerechnen(const std::vector<int>&);

};



#endif /* KNIFFEL_H_ */
