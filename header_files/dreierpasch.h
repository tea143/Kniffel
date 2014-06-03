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

    virtual int punkteBerechnen(const std::vector<int>&) override;

private:
    bool wuerfelGleich(std::vector<int> wuerfelAugen, int, int, int);
};


#endif	/* DREIERPASCH_H */

