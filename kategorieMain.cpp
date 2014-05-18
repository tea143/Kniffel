
#include <iostream>
#include <cstddef>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "header_files/kategorie.h"

using namespace std;

int main() {

	Kategorie kategorie;
	vector<int> wuerfel;
	srand(unsigned(time(0)));
	int wert = 0;

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

		cout << kategorie.punkteBerechnen(wuerfel) << endl;

		//Wuerfel entleeren:
		wuerfel.clear();
	}

}

