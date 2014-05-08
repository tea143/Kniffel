/*
 * spieler.h
 *
 *  Created on: 08.05.2014
 *      Author: Larisa
 */

#ifndef SPIELER_H_
#define SPIELER_H_
#include <string>

class Spieler {
public:

	Spieler(const std::string& name_)
		:name{name_} {}

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

private:
	std::string name;

};


#endif /* SPIELER_H_ */
