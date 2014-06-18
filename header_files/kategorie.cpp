#include "kategorie.h"

Kategorie::Kategorie(const std::string& n)
: name {
    n
}
{
    //std::cout << "Kategorie-Objekt wurde beendet.\n";
}

const std::string& Kategorie::getName() const {
    return name;
}

void Kategorie::setName(const std::string& n) {
    name = n;
}

unsigned int Kategorie::getPunktzahl() const {
    return punktzahl;
}

void Kategorie::setPunktzahl(unsigned int p) {
    punktzahl = p;
}

bool Kategorie::isGesetzt() const {
    return gesetzt;
}

/**
 * Globale Funktion zum Überschreiben des <<-Operators
 * \param ausgabe Ausgabekanal
 * \param k Kategorie
 * \return ausgabe Gibt den Ausgabekanal zurück
 */
std::ostream& operator<<(std::ostream& ausgabe, const Kategorie& k) {
    ausgabe << k.getName() << ":\t";
    if (k.isGesetzt()) {
        ausgabe << "Punktzahl: " << k.getPunktzahl();
    } else {
        ausgabe << "offen";
    }
    ausgabe << std::endl;
    return ausgabe;
}
