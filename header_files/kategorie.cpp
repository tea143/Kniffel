#include "kategorie.h"

Kategorie::Kategorie(const std::string& n)
:name {n}{
	//std::cout << "Kategorie-Objekt wurde beendet.\n";
}

const std::string& Kategorie::getName() const {
    return name;
}

void Kategorie::setName(const std::string& n) {
    name = n;
}

int Kategorie::getPunktzahl() const {
    return punktzahl;
}

void Kategorie::setPunktzahl(int p) {
    punktzahl = p;
}

bool Kategorie::isGesetzt() const {
    return gesetzt;
}
