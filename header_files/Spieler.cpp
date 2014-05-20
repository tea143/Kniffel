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
    cout << "Spieler erzeugt!" << endl;
    kategorienListe.push_back(new Dreierpasch());
    kategorienListe.push_back(new Viererpasch());

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
    cout << "erreichte Punkte in Kategorie " << kategorienListe.at(kategorienNummer)->getName() << " " ;
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