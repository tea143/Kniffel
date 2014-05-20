/*
 * kategorie.h
 *
 *  Created on: 17.05.2014
 *      Author: Larisa
 */

#ifndef KATEGORIE_H_
#define KATEGORIE_H_

#include <vector>
#include <string>

class Kategorie {
public:

    virtual ~Kategorie() = default;
    Kategorie() = default;
    virtual int punkteBerechnen(const std::vector<int> &augen) = 0;
    virtual const std::string& getName() const = 0;
    virtual void setName(const std::string& name) = 0;
    virtual void setPunktzahl(int punktzahl) = 0;
    virtual int getPunktzahl() const = 0;

};


#endif /* KATEGORIE_H_ */

