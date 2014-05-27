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

    virtual ~Kategorie() = default;
    Kategorie(const std::string&);
    virtual int punkteBerechnen(const std::vector<int>&) = 0;
    const std::string& getName() const;
    void setName(const std::string&);
    void setPunktzahl(int);
    int getPunktzahl() const;
    bool isGesetzt() const;
protected:
    int punktzahl = 0;
    bool gesetzt = false;
private:
    std::string name;
};


#endif /* KATEGORIE_H_ */

