/* 
 * File:   Spieler.cpp
 * Author: IFI
 * 
 * Created on 8. Mai 2014, 18:23
 */

#include "spieler.h"

Spieler::Spieler(const std::string& n)
	:name {n} {
	//std::cout << "Spieler-Objekt wurde erzeugt.\n";
    kategorienListe.push_back(new EinerBisSechser(1, "Einer"));
    kategorienListe.push_back(new EinerBisSechser(2, "Zweier"));
    kategorienListe.push_back(new EinerBisSechser(3, "Dreier"));
    kategorienListe.push_back(new EinerBisSechser(4, "Vierer"));
    kategorienListe.push_back(new EinerBisSechser(5, "Fünfer"));
    kategorienListe.push_back(new EinerBisSechser(6, "Sechser"));
    kategorienListe.push_back(new Dreierpasch());
    kategorienListe.push_back(new Viererpasch());
    kategorienListe.push_back(new Chance());
    kategorienListe.push_back(new Fullhouse());
    kategorienListe.push_back(new GrosseStrasse());
    kategorienListe.push_back(new KleineStrasse());
    kategorienListe.push_back(new Kniffel());
}

Spieler::~Spieler() {
	//std::cout << "Spieler-Objekt wurde beendet.\n";
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

void Spieler::punktzahlErmitteln(const int kategorienNummer, const std::vector<int> wuerfel) {
    kategorienListe.at(kategorienNummer)->punkteBerechnen(wuerfel);
    std::cout << "erreichte Punkte in Kategorie " << kategorienListe.at(kategorienNummer)->getName() << " ";
    std::cout << kategorienListe.at(kategorienNummer)->getPunktzahl() << std::endl;
    punktzahl += kategorienListe.at(kategorienNummer)->getPunktzahl();
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
        std::cout << i << ". " << kategorienListe.at(i)->getName() << ": Punktzahl: " << kategorienListe.at(i)->getPunktzahl() << std::endl;
    }
}
