/*
 * Zufallszahl.h
 *
 *  Created on: 20.05.2014
 *      Author: Irina Fress
 */

#ifndef ZUFALLSZAHL_H_
#define ZUFALLSZAHL_H_

#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

class Zufallszahl
{
// Private Variable für den neuen Zeitstop
private:
	Zufallszahl()
	{
		srand(static_cast<int>(time(NULL)));
	}
public:
	// Erzeugt eine "zufällige" Zahl zwischen unten- und obergrenze
	static int rnd(int untergrenze, int obergrenze)
	{
		// Neue Zufallszahl initialisieren
		static Zufallszahl dummy;
		assert(obergrenze - untergrenze < RAND_MAX);
		return untergrenze + rand() % (obergrenze - untergrenze + 1);
	}
};

#endif /* ZUFALLSZAHL_H_ */
