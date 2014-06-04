/* 
 * File:   Spieler.cpp
 * Author: IFI
 * 
 * Created on 8. Mai 2014, 18:23
 */

#include "spieler.h"

Spieler::Spieler(const std::string& n)
: name {
    n
}
{
    //std::cout << getName() << "-Spieler-Objekt wurde erzeugt.\n";
    kategorienListe.push_back(new EinerBisSechser(1, "Einer"));
    kategorienListe.push_back(new EinerBisSechser(2, "Zweier"));
    kategorienListe.push_back(new EinerBisSechser(3, "Dreier"));
    kategorienListe.push_back(new EinerBisSechser(4, "Vierer"));
    kategorienListe.push_back(new EinerBisSechser(5, "F\x81 \bnfer"));
    kategorienListe.push_back(new EinerBisSechser(6, "Sechser"));
    kategorienListe.push_back(new Dreierpasch());
    kategorienListe.push_back(new Viererpasch());
    kategorienListe.push_back(new Fullhouse());
    kategorienListe.push_back(new GrosseStrasse());
    kategorienListe.push_back(new KleineStrasse());
    kategorienListe.push_back(new Kniffel());    
    kategorienListe.push_back(new Chance());

    for (size_t i = 0; i < kategorienListe.size(); i++) {
        kategorieErledigt.push_back(false);
    }
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

const int Spieler::getPunktzahl() const {
    return punktzahl;
}

bool Spieler::punktzahlErmitteln(const int kategorienNummer, const std::vector<int>& wuerfel) {
    if (kategorienListe.at(kategorienNummer - 1)->isGesetzt()) {
        std::cout << "Kategorie " << kategorienListe.at(kategorienNummer - 1)->getName() << " ist bereits gesetzt." << std::endl;
        std::cout << "Bitte w\x84 \bhle eine andere Kategorie!" << std::endl;
        return false;
    } else {
        kategorienListe.at(kategorienNummer - 1)->punkteBerechnen(wuerfel);
        kategorieErledigt.at(kategorienNummer - 1) = true;
        std::cout << "Erreichte Punkte in Kategorie " << kategorienListe.at(kategorienNummer - 1)->getName() << " ";
        std::cout << kategorienListe.at(kategorienNummer - 1)->getPunktzahl() << std::endl;
        punktzahl += kategorienListe.at(kategorienNummer - 1)->getPunktzahl();
        return true;
    }
}

void Spieler::bonusErmitteln() {
    int punkteFuerBonus = 0;
    for (auto& kategorie : kategorienListe) {
        if (typeid (*kategorie) == typeid (EinerBisSechser)) {
            punkteFuerBonus += kategorie->getPunktzahl();
            if (punkteFuerBonus >= 63) {
                punktzahl += 35;
                break;
            }
        }
    }
}

const std::vector<Kategorie*>& Spieler::getKategorienListe() const {
    return kategorienListe;
}

void Spieler::printFreieKategorien() const {
    std::cout << std::endl << "Kategorien: " << std::endl;
    for (size_t i = 0; i < kategorienListe.size(); i++) {
        std::cout << i + 1 << ". " << kategorienListe.at(i)->getName() << ":\t";
        if (kategorieErledigt.at(i)) {
            std::cout << "Punktzahl: " << kategorienListe.at(i)->getPunktzahl();
        } else {
            std::cout << "offen";
        }
        std::cout << std::endl;
    }
}

/**
 * Bevor das Spielfeld aufgeraemt wird, muss die Kategorieliste freigesetzt werden,
 * damit keine "verwitweten" Objekte nach der Programmbeendung bleiben.
 *
 * @param kategorienListe
 */
void Spieler::kategorieFreisetzen(std::vector<Kategorie*> kategorienListe) {
	for (auto k : kategorienListe) {
		delete k;
	}
}
