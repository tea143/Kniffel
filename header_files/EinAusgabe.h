/* 
 * File:   EinAusgabe.h
 * Author: ASUS
 *
 * Created on 22. Mai 2014, 19:38
 */

#ifndef EINAUSGABE_H
#define	EINAUSGABE_H
#include <iostream>
#include <limits>

class EinAusgabe {
public:
    EinAusgabe();
    virtual ~EinAusgabe();
    size_t readNumberBetween(int, int);
private:

};

#endif	/* EINAUSGABE_H */

