/* 
 * File:   viererpasch.h
 * Author: IFI
 *
 * Created on 20. Mai 2014, 14:10
 */

#ifndef VIERERPASCH_H
#define	VIERERPASCH_H

#include "kategorie.h"

class Viererpasch : public Kategorie {

public:
	//Konstruktor:
    Viererpasch();
    //Destruktor:
    ~Viererpasch();

    int punkteBerechnen(const std::vector<int> &augen);
    const std::string& getName() const;
    void setName(const std::string& name);
    void setPunktzahl(int punktzahl);
    int getPunktzahl() const;

private:
    std::string name;
    int punktzahl = 0;
    bool gesetzt;
    std::vector<int> wuerfelAugen;
    bool wuerfelGleich(int index1, int index2, int index3, int index4);
};

#endif	/* VIERERPASCH_H */

