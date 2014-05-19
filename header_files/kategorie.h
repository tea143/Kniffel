/*
 * kategorie.h
 *
 *  Created on: 17.05.2014
 *      Author: Larisa
 */

#ifndef KATEGORIE_H_
#define KATEGORIE_H_

#include <vector>

class Kategorie {

public:

	virtual ~Kategorie() = default;

	virtual int punkteBerechnen(std::vector<int> augen) = 0;

};


#endif /* KATEGORIE_H_ */
