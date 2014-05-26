/*
 * zufallszahl.h
 *
 *  Created on: 20.05.2014
 *      Author: IFI
 */

#ifndef ZUFALLSZAHL_H_
#define ZUFALLSZAHL_H_

#include <ctime>
#include <cassert>

class Zufallszahl {

// Private Variable fuer den neuen Zeitstop
private:
	//Konstruktor:
	Zufallszahl(){
		srand(static_cast<int>(time(NULL)));
	}

public:
	// Erzeugt eine "zufaellige" Zahl zwischen unten- und obergrenze
	static int rnd(int untergrenze, int obergrenze) {
		// Neue Zufallszahl initialisieren
		static Zufallszahl dummy;
		assert(obergrenze - untergrenze < RAND_MAX);
		return untergrenze + rand() % (obergrenze - untergrenze + 1);
	}
};

#endif /* ZUFALLSZAHL_H_ */
