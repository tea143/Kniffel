#include <iostream>
#include "gtest/gtest.h"
#include "header_files/Spielfeld.h"
#include "header_files/Spieler.h"
#include "header_files/EinAusgabe.h"

using namespace std;

int main(int argc, char *argv[]) {
	/**
	 * GoogleTest (Google C++ Testing Framework)
	 */
	//::testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();

	/**
	 * Kniffel-Spiel
	 */
    cout << "Das Kniffel-Spiel f\x84 \bngt an:\n" << endl;
    cout << "Wie viele Spieler spielen mit? " << endl;
    EinAusgabe io;
    unsigned int spielerAnzahl = io.readNumberBetween(1, 5);
    SpielFeld spielFeld(spielerAnzahl);
    spielFeld.spielerKreieren();
    spielFeld.spielen();
    spielFeld.ergebnisErmitteln();
}

