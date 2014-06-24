/*
 * kategorie.h
 *
 *  Created on: 17.05.2014
 *      Author: IFI
 */

#ifndef KATEGORIE_H_
#define KATEGORIE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Kategorie {

public:
    Kategorie(const std::string&);
    virtual ~Kategorie() = default;
    virtual unsigned int punkteBerechnen(const std::vector<unsigned int>&) = 0;
    const std::string& getName() const;
    void setName(const std::string&);
    unsigned int getPunktzahl() const;
    void setPunktzahl(unsigned int);
    bool isGesetzt() const;

protected:
    unsigned int punktzahl = 0;
    bool gesetzt = false;

private:
    std::string name;
};

std::ostream& operator<<(std::ostream&, const Kategorie&);

#endif /* KATEGORIE_H_ */

