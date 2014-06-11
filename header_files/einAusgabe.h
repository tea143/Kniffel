/* 
 * File:   einAusgabe.h
 * Author: IFI
 *
 * Created on 22. Mai 2014, 19:38
 */

#ifndef EINAUSGABE_H
#define	EINAUSGABE_H

#include <iostream>
#include <limits>
#include <vector>

class EinAusgabe {

public:
    EinAusgabe();
    virtual ~EinAusgabe();

    unsigned int readNumberBetween(int, int) const;
    void wuerfelAusgeben(std::vector<unsigned int>) const;

};

#endif	/* EINAUSGABE_H */

