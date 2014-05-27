#include "spielFeld.h"
#include "wuerfelbecher.h"
#include "spieler.h"

SpielFeld::SpielFeld(size_t anzahl)
: spielerAnzahl {
    anzahl
}
{
    //std::cout << "SpielFeld-Objekt wurde erzeugt.\n";
}

SpielFeld::~SpielFeld() {
    //std::cout << "SpielFeld-Objekt wurde beendet.\n";
}

const size_t SpielFeld::getSpielerAnzahl() const {
    return spielerAnzahl;
}

std::vector<Spieler>& SpielFeld::spielerKreieren() {
    std::string name;
    for (size_t i = 0; i < spielerAnzahl; i++) {
        std::cout << "Geben Sie den Namen des " << i + 1 << ". Spielers ein: " << std::endl;
        std::cin >> name;
        Spieler spieler(name);
        spielerListe.push_back(spieler);
    }
    return spielerListe;
}

void SpielFeld::spielerAnzeigen() {
    for (auto& spieler : spielerListe) {
        std::cout << "Spieler: " << spieler.getName() << std::endl;
    }
}

const std::vector<Spieler>& SpielFeld::getSpielerListe() const {
    return spielerListe;
}

void SpielFeld::spielen() {
    for (size_t i = 0; i < SPIELRUNDEN; i++) {
        std::cout << std::endl << "###### RUNDE " << i + 1 << " ######:" << std::endl;
        for (auto& spieler : spielerListe) {
            std::cout << std::endl << "Spieler " << spieler.getName() << " ist an der Reihe!" << std::endl;
            spieler.printFreieKategorien();
            Wuerfelbecher becher;
            becher.wuerfeln();
            //cout << "Gebe Nummer der Würfel aus, die du wieder in der Würfelbecher werfen willst!" << endl;
            std::cout << "W\x84 \bhle eine freie Kategorie (Zahl): " << std::endl;
            EinAusgabe io;
            bool freieKategorie = false;
            while (!freieKategorie) {
                size_t kategorie = io.readNumberBetween(0, SPIELRUNDEN - 1);
                freieKategorie = spieler.punktzahlErmitteln(kategorie, becher.getErgebnis());
            }
        }
    }
}

void SpielFeld::ergebnisErmitteln() {
    std::cout << std::endl << std::endl << "ERGEBNIS: " << std::endl;
    size_t gewinnerPunktzahl = 0;
    for (auto& spieler : spielerListe) {
        spieler.bonusErmitteln();
        std::cout << spieler.getName() << " hat " << spieler.getPunktzahl() << " Punkte erreicht." << std::endl;
        if (static_cast<unsigned> (spieler.getPunktzahl()) > gewinnerPunktzahl) {
            gewinnerPunktzahl = spieler.getPunktzahl();
        }
    }
    std::cout << std::endl << "GEWINNER: " << std::endl;
    for (auto& spieler : spielerListe) {
        if (gewinnerPunktzahl == static_cast<unsigned> (spieler.getPunktzahl())) {
            std::cout << spieler.getName() << std::endl;
        }
    }
}
