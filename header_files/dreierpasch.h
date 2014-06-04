/* 
 * File:   dreierpasch.h
 * Author: IFI
 *
 * Created on 20. Mai 2014, 14:08
 */

#ifndef DREIERPASCH_H
#define	DREIERPASCH_H

#include "kategorie.h"

class Dreierpasch : public Kategorie {

public:
	//Konstruktor:
    Dreierpasch();
    //Destruktor:
    ~Dreierpasch();
    virtual unsigned int punkteBerechnen(const std::vector<unsigned int>&) override;

private:
    bool wuerfelGleich(std::vector<unsigned int> wuerfelAugen, unsigned int, unsigned int, unsigned int);
};


#endif	/* DREIERPASCH_H */

