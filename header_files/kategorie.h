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
    virtual int punkteBerechnen(const std::vector<int>&) = 0;
    const std::string& getName() const;
    void setName(const std::string&);
    int getPunktzahl() const;
    void setPunktzahl(int);
    bool isGesetzt() const;

protected:
    int punktzahl = 0;
    bool gesetzt = false;

private:
    std::string name;
};


#endif /* KATEGORIE_H_ */

