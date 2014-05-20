/* 
 * File:   viererpasch.h
 * Author: ASUS
 *
 * Created on 20. Mai 2014, 14:10
 */

#ifndef VIERERPASCH_H
#define	VIERERPASCH_H

#include <string>
#include <iostream>
#include <algorithm>
#include "kategorie.h"

class Viererpasch : public Kategorie {
public:

    Viererpasch();
    int punkteBerechnen(const std::vector<int> &augen);
    const std::string& getName() const;
    void setName(const std::string& name);
    void setPunktzahl(int punktzahl);
    int getPunktzahl() const;

private:
    std::string name;
    int punktzahl;
    bool gesetzt;
};

#endif	/* VIERERPASCH_H */

