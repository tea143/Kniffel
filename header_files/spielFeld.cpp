#include "spielFeld.h"

SpielFeld::SpielFeld(unsigned int anzahl)
: spielerAnzahl {
    anzahl
}
{
    //std::cout << "SpielFeld-Objekt wurde erzeugt.\n";
}

SpielFeld::~SpielFeld() {
    //std::cout << "SpielFeld-Objekt wurde beendet.\n";
}

unsigned int SpielFeld::getSpielerAnzahl() const {
    return spielerAnzahl;
}

void SpielFeld::spielerKreieren() {
    std::string name;
    for (size_t i = 0; i < spielerAnzahl; i++) {
        std::cout << "Geben Sie den Namen des " << i + 1 << ". Spielers ein: " << std::endl;
        std::cin >> name;
        spielerListe.push_back(std::unique_ptr<Spieler>(new Spieler(name)));
    }
}

void SpielFeld::spielerAnzeigen() const {
    for (const auto& spieler : spielerListe) {
        std::cout << "Spieler: " << spieler->getName() << std::endl;
    }
}

const std::vector<std::unique_ptr<Spieler>>& SpielFeld::getSpielerListe() const {
    return spielerListe;
}

void SpielFeld::spielen() {
    for (size_t i = 0; i < SPIELRUNDEN; i++) {
        std::cout << std::endl << "###### RUNDE " << i + 1 << " ######:" << std::endl;
        for (auto& spieler : spielerListe) {
            std::cout << std::endl << "Spieler " << spieler->getName() << " ist an der Reihe!" << std::endl;
            spieler->printFreieKategorien();
            Wuerfelbecher becher;
            becher.wuerfeln();
            std::cout << "W\x84 \bhle eine freie Kategorie (Zahl): " << std::endl;
            bool freieKategorie = false;
            while (!freieKategorie) {
                unsigned int kategorie = io.readNumberBetween(1, SPIELRUNDEN);
                freieKategorie = spieler->punktzahlErmitteln(kategorie, becher.getErgebnis());
            }
        }
    }
}

void SpielFeld::ergebnisErmitteln() {
    std::cout << std::endl << std::endl << "ERGEBNIS: " << std::endl;
    unsigned int gewinnerPunktzahl = 0;
    for (auto& spieler : spielerListe) {
        spieler->bonusErmitteln();
        std::cout << spieler->getName() << " hat " << spieler->getPunktzahl() << " Punkte erreicht." << std::endl;
        if (static_cast<unsigned> (spieler->getPunktzahl()) > gewinnerPunktzahl) {
            gewinnerPunktzahl = spieler->getPunktzahl();
        }
    }
    std::cout << std::endl << "GEWINNER: " << std::endl;
    for (const auto& spieler : spielerListe) {
        if (gewinnerPunktzahl == static_cast<unsigned> (spieler->getPunktzahl())) {
            std::cout << spieler->getName() << std::endl;
        }
    }
}

/**
 * Bevor das Programm beendet, muss das Spielfeld aufgeraeumt werden.
 *
 * @param spielerListe
 */
/*void SpielFeld::spielfeldAufraeumen() {

    for (auto& spieler : spielerListe) {
        spieler.kategorienFreisetzen();
    }
}*/
