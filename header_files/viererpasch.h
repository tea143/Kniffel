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
    Viererpasch();
    ~Viererpasch();
    int punkteBerechnen(const std::vector<int>&);

private:
    //std::vector<int> wuerfelAugen;
    bool wuerfelGleich(int, int, int, int, const std::vector<int>&);
};

#endif	/* VIERERPASCH_H */

