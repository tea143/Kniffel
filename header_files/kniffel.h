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



#endif /* KNIFFEL_H_ */
