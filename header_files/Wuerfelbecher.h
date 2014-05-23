/*
 * Wuerfelbecher.h
 *
 *  Created on: 20.05.2014
 *      Author: Irina Fress
 */

#ifndef WUERFELBECHER_H_
#define WUERFELBECHER_H_

#include <vector>

#include "Zufallszahl.h"
using namespace std;

class Wuerfelbecher
{
// Definieren
public:
	Wuerfelbecher();
	~Wuerfelbecher();
	// Variablen
	vector<int> ergebnis;
	vector<int> wuerfelbecher;
	// Methoden
	int schuetteln(int);
	void wuerfeln();
	void ausgabe(vector<int>);
	int zahlPruefen(string);
};

#endif /* WUERFELBECHER_H_ */
