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

    virtual int punkteBerechnen(const std::vector<int>&) override;

private:
    bool wuerfelGleich(std::vector<int> wuerfelAugen, int, int, int, int);
};

#endif	/* VIERERPASCH_H */

