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
private:

    Zufallszahl() {
        srand(static_cast<int> (time(NULL)));
    }

public:

    /**
     * Erzeugt eine "zufaellige" Zahl zwischen unten- und obergrenze
     * @param untergrenze - int: unterste Grenze zur Zufallszahlerzeugung
     * @param obergrenze - int: oberste Grenze zur Zufallszahlerzeugung
     * @return zufallszahl - int zwischen 1 und 6.
     */
    static int rnd(int untergrenze, int obergrenze) {
        static Zufallszahl dummy;
        assert(obergrenze - untergrenze < RAND_MAX);
        return untergrenze + rand() % (obergrenze - untergrenze + 1);
    }
};

#endif /* ZUFALLSZAHL_H_ */
