/* 
 * File:   Spieler.cpp
 * Author: IFI
 * 
 * Created on 8. Mai 2014, 18:23
 */

#include "spieler.h"

Spieler::Spieler(const std::string& n) : name {n}
{
    //std::cout << getName() << "-Spieler-Objekt wurde erzeugt.\n";
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new EinerBisSechser(1, "Einer")));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new EinerBisSechser(2, "Zweier")));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new EinerBisSechser(3, "Dreier")));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new EinerBisSechser(4, "Vierer")));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new EinerBisSechser(5, "F\x81 \bnfer")));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new EinerBisSechser(6, "Sechser")));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new Dreierpasch()));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new Viererpasch()));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new Fullhouse()));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new GrosseStrasse()));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new KleineStrasse()));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new Kniffel()));
    kategorienListe.push_back(std::unique_ptr<Kategorie>(new Chance()));
}

Spieler::~Spieler() {
    //std::cout << getName() << "-Spieler-Objekt wurde beendet.\n";
}

const std::string& Spieler::getName() const {
    return name;
}

void Spieler::setName(const std::string& name) {
    this->name = name;
}

unsigned int Spieler::getPunktzahl() const {
    return punktzahl;
}

/**
 * Die Methode ueberprueft, ob eine Kategorie noch frei ist und gibt - falls ja  - 
 * die Augenzahl an die gewaehlte Kategorie zum Berechnen der Punkte weiter.
 * \param kategorienNummer Position der Kategorie im Vector
 * \param wuerfel Augenzahl der einzelnen Wuerfel im Vector
 * \return bool Gibt true zurueck, wenn die Kategorie noch frei ist und false, wenn sie besetzt ist
 */
bool Spieler::punktzahlErmitteln(unsigned int kategorienNummer, const std::vector<unsigned int>& wuerfel) {
    if (kategorienListe.at(kategorienNummer - 1)->isGesetzt()) {
        std::cout << "Kategorie " << kategorienListe.at(kategorienNummer - 1)->getName() << " ist bereits gesetzt." << std::endl;
        std::cout << "Bitte w\x84 \bhle eine andere Kategorie!" << std::endl;
        return false;
    } else {
        kategorienListe.at(kategorienNummer - 1)->punkteBerechnen(wuerfel);
        std::cout << "Erreichte Punkte in Kategorie " << kategorienListe.at(kategorienNummer - 1)->getName() << " ";
        std::cout << kategorienListe.at(kategorienNummer - 1)->getPunktzahl() << std::endl;
        punktzahl += kategorienListe.at(kategorienNummer - 1)->getPunktzahl();
        return true;
    }
}

/**
 * Die Methode ermittel, ob der Spieler  fuer die Punktanzahl in den Kategorien Einer bis Sechser
 * einen Bonus erhaelt und addiert ihn gegebenenfalls auf die Gesamtpunktzahl.
 */
void Spieler::bonusErmitteln() {
    unsigned int punkteFuerBonus = 0;
    for (const auto& kategorie : kategorienListe) {
        if (typeid (*kategorie) == typeid (EinerBisSechser)) {
            punkteFuerBonus += kategorie->getPunktzahl();
            if (punkteFuerBonus >= 63) {
                punktzahl += 35;
                break;
            }
        }
    }
}

const std::vector<std::unique_ptr<Kategorie>>& Spieler::getKategorienListe() const {
    return kategorienListe;
}

/**
 * Die Methode gibt aus, welche Kategorien bereits besetzt und welche noch frei sind.
 *
 */
void Spieler::printFreieKategorien() const {
    std::cout << std::endl << "Kategorien: " << std::endl;
    for (size_t i = 0; i < kategorienListe.size(); i++) {
        std::cout << i + 1 << ". " << kategorienListe.at(i)->getName() << ":\t";
        if (kategorienListe.at(i)->isGesetzt()) {
            std::cout << "Punktzahl: " << kategorienListe.at(i)->getPunktzahl();
        } else {
            std::cout << "offen";
        }
        std::cout << std::endl;
    }
}

