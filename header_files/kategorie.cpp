#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <algorithm>
#include <unordered_map>
#include "kategorie.h"

int Kategorie::punkteBerechnen(std::vector<int> augen) {
	int summeAllerAugen = 0;

	summeAllerAugen = berechneEinerBisFuenfer(augen);

	if (summeAllerAugen == 0) {
		summeAllerAugen = berechneViererPasch(augen);
	}

	if (summeAllerAugen == 0) {
		summeAllerAugen = berechneDreierPasch(augen);
	}

	if (summeAllerAugen == 0) {
		summeAllerAugen = berechneAlleAugen(augen);
	}
	return summeAllerAugen;
}

int Kategorie::berechneEinerBisFuenfer(std::vector<int> augen) {
	int summeAllerGleichenZahlen = 0;
	std::vector<int> temp = augen;
	std::string bezeichner;
	if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
		if (temp[0] == 1) {
			bezeichner = "Einer";
		} else if (temp[0] == 2) {
			bezeichner = "Zweier";
		} else if (temp[0] == 3) {
			bezeichner = "Dreier";
		} else if (temp[0] == 4) {
			bezeichner = "Vierer";
		} else if (temp[0] == 5) {
			bezeichner = "Fünfer";
		} else if (temp[0] == 6) {
			bezeichner = "Sechser";
		}
		std::cout << bezeichner << std::endl;
		for (size_t i = 0; i < temp.size(); ++i) {
			summeAllerGleichenZahlen = summeAllerGleichenZahlen + temp[0];
		}
		return summeAllerGleichenZahlen;
	}
	return 0;
}

int Kategorie::berechneDreierPasch(std::vector<int> augen) {
	int summeAllerAugen = 0;
	std::vector<int> temp = augen;
	std::sort(temp.begin(), temp.end());

	if (temp[0] == temp[1] && temp[1] == temp[2]) {
		std::cout << "Dreierpasch: ";
		for (size_t i = 0; i < temp.size(); i++) {
			summeAllerAugen = summeAllerAugen + temp[i];
		}
		return summeAllerAugen;
	}
	if (temp[1] == temp[2] && temp[2] == temp[3]) {
		std::cout << "Dreierpasch: ";
		for (size_t i = 0; i < temp.size(); i++) {
			summeAllerAugen = summeAllerAugen + temp[i];
		}
		return summeAllerAugen;
	}
	if (temp[2] == temp[3] && temp[3] == temp[4]) {
		std::cout << "Dreierpasch: ";
		for (size_t i = 0; i < temp.size(); i++) {
			summeAllerAugen = summeAllerAugen + temp[i];
		}
		return summeAllerAugen;
	}
	return 0;
}

int Kategorie::berechneViererPasch(std::vector<int> augen) {
	int summeAllerAugen = 0;
	std::vector<int> temp = augen;
	std::sort(temp.begin(), temp.end());

	if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3]) {
		std::cout << "Viererpasch: ";
		for (size_t i = 0; i < temp.size(); i++) {
			summeAllerAugen = summeAllerAugen + temp[i];
		}
		return summeAllerAugen;
	}

	if (temp[1] == temp[2] && temp[2] == temp[3] && temp[3] == temp[4]) {
		std::cout << "Viererpasch: ";
		for (size_t i = 0; i < temp.size(); i++) {
			summeAllerAugen = summeAllerAugen + temp[i];
		}
		return summeAllerAugen;
	}
	return 0;
}

int Kategorie::berechneAlleAugen(std::vector<int> augen) {
	int summeAllerAugen = 0;
	std::vector<int> temp = augen;

	std::cout << "Augensumme: ";
	for (size_t i = 0; i < temp.size(); i++) {
		summeAllerAugen = summeAllerAugen + temp[i];
	}
	return summeAllerAugen;

}
