/* 
 * File:   dreierpasch.h
 * Author: ASUS
 *
 * Created on 20. Mai 2014, 14:08
 */

#ifndef DREIERPASCH_H
#define	DREIERPASCH_H

#include<algorithm>
#include <iostream>
#include "kategorie.h"

class Dreierpasch : public Kategorie {
public:

    Dreierpasch();
    int punkteBerechnen(const std::vector<int> &augen);
    const std::string& getName() const;
    void setName(const std::string& name);
    void setPunktzahl(int punktzahl);
    int getPunktzahl() const;

private:
    std::string name;
    int punktzahl;
    std::vector<int> wuerfelAugen;
    bool gesetzt;
    bool wuerfelGleich(int index1, int index2, int index3);
};


#endif	/* DREIERPASCH_H */

