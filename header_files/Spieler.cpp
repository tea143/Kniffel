/* 
 * File:   Spieler.cpp
 * Author: ASUS
 * 
 * Created on 8. Mai 2014, 18:23
 */

#include "Spieler.h"
#include<vector>
#include<iostream>

using namespace std;

Spieler::Spieler(const string& n) : name {
    n
}
{
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

const string& Spieler::getName() const {
    return name;
}

void Spieler::setName(const string& name) {
    this->name = name;
}

const int Spieler::getPunktzahl() const {
    return punktzahl;
}

void Spieler::punktzahlErmitteln(const int kategorienNummer, const std::vector<int> wuerfel) {
    kategorienListe.at(kategorienNummer)->punkteBerechnen(wuerfel);
    cout << "erreichte Punkte in Kategorie " << kategorienListe.at(kategorienNummer)->getName() << " ";
    cout << kategorienListe.at(kategorienNummer)->getPunktzahl() << endl;
}

const std::vector<Kategorie*>& Spieler::getKategorienListe() const {
    return kategorienListe;
}

void Spieler::printFreieKategorien() const {
    cout << endl << "Kategorien: " << endl;
    for (size_t i = 0; i < kategorienListe.size(); i++) {
        cout << i << ". " << kategorienListe.at(i)->getName() << ": Punktzahl: " << kategorienListe.at(i)->getPunktzahl() << endl;
    }
}
