#include "kategorie.h"

Kategorie::Kategorie(const std::string& n) :
name {
    n
}
{
}

const std::string& Kategorie::getName() const {
    return name;
}

void Kategorie::setName(const std::string& n) {
    name = n;
}

void Kategorie::setPunktzahl(int p) {
    punktzahl = p;
}

int Kategorie::getPunktzahl() const {
    return punktzahl;
}

bool Kategorie::isGesetzt() const {
    return gesetzt;
}