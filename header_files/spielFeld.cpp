#include <iostream>
#include <vector>
#include <cstddef>
#include <string>
#include "spielfeld.h"
#include "spieler.h"

std::vector <Spieler> SpielFeld::spielerKreieren() {
	std::vector<Spieler> spielerListe;
	unsigned int spielerAnzahl = getSpielerAnzahl();
	std::string name;
	do {
		std::cout << "Geben Sie den Namen des Spielers ein: " << std::endl;
		std::cin >> name;
		Spieler spieler(name);
		spielerListe.push_back(spieler);
		spielerAnzahl --;
	} while (spielerAnzahl != 0);
	return spielerListe;
}

void SpielFeld::spielerAnzeigen(std::vector<Spieler> spielerListe) {
	for (size_t i = 0; i < spielerListe.size(); ++i) {
		std::cout << "Spieler: " << spielerListe[i].getName() << std::endl;
	}
}
