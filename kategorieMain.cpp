
#include <iostream>
#include <cstddef>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "header_files/einerBisSechser.h"
#include "header_files/kniffel.h"
#include "header_files/fullHouse.h"
#include "header_files/dreierPasch.h"
#include "header_files/vierPasch.h"
#include "header_files/kleineStrasse.h"
#include "header_files/grosseStrasse.h"
#include "header_files/chance.h"

#include "header_files/kategorieListe.h"

using namespace std;

int main() {

	vector<Kategorie*> kategorie;
	vector<int> wuerfel;
	srand(unsigned(time(0)));
	int wert = 0;

	kategorie.push_back(new Kniffel);
	kategorie.push_back(new Fullhouse);
	kategorie.push_back(new Vierpasch);
	kategorie.push_back(new Dreierpasch);
	kategorie.push_back(new GrosseStrasse);
	kategorie.push_back(new KleineStrasse);
	kategorie.push_back(new EinerBisSechser);
	kategorie.push_back(new Chance);

	//Augenwert generieren lassen:
	for(size_t runde = 0; runde < 13; ++runde) {
		size_t n = 1 + runde;
		cout << "*********************************************************************" << endl;
		cout << n << ". Runde:\n";

		for (size_t i = 0; i < 5; ++i) {
			wert = 1 + (rand() % 4 )+ 1;
			wuerfel.push_back(wert);
		}


		// using built-in random generator:
		random_shuffle(wuerfel.begin(), wuerfel.end());

		//Wuerfel sortieren und ausgeben:
		sort(wuerfel.begin(), wuerfel.end());

		for (size_t i = 0; i < wuerfel.size(); ++i) {
			cout << "[" << wuerfel[i] << "] ";
		}
		cout << endl;

		KategorieListe kategorieListe(kategorie, wuerfel);

		cout << kategorieListe.nutzenPunkteBerechnen() << endl;

		//Wuerfel entleeren:
		wuerfel.clear();
	}

}

