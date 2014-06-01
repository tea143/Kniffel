/**
 *  @file: zufallszahl.h
 *
 *  @date: 20.05.2014
 *  @author: IFI
 */

#ifndef ZUFALLSZAHL_H_
#define ZUFALLSZAHL_H_

#include <ctime>
#include <cassert>

class Zufallszahl {

private:
    /*! Seed von Funktion rand() wird durch timestamp gesetzt */

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
        static Zufallszahl dummy; // Neue Zufallszahl initialisieren
        assert(obergrenze - untergrenze < RAND_MAX); // Prüfen, ob die Zufallszahl sich in grenzen befindet
        return untergrenze + rand() % (obergrenze - untergrenze + 1); // Zufallszahl erzeugen und ausgeben
    }
};

#endif /* ZUFALLSZAHL_H_ */
