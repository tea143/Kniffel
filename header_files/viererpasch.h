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

    virtual unsigned int punkteBerechnen(const std::vector<unsigned int>&) override;

private:
    bool wuerfelGleich(std::vector<unsigned int> wuerfelAugen, unsigned int, unsigned int, unsigned int, unsigned int);
};

#endif	/* VIERERPASCH_H */

