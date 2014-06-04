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
	//Konstruktor:
    Kniffel();
    //Destruktor:
    ~Kniffel();

    virtual unsigned int punkteBerechnen(const std::vector<unsigned int>&) override;

};



#endif /* KNIFFEL_H_ */
