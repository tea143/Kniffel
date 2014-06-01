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
    int punkteBerechnen(const std::vector<int>&);

private:
    bool wuerfelGleich(int, int, int, const std::vector<int>&);
};


#endif	/* DREIERPASCH_H */

