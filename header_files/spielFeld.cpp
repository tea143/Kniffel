#include "spielFeld.h"

SpielFeld::SpielFeld() {
    //std::cout << "SpielFeld-Objekt wurde erzeugt.\n";
}

SpielFeld::~SpielFeld() {
    //std::cout << "SpielFeld-Objekt wurde beendet.\n";
}

/**
 * Methode erfragt Anzahl von Spielern, erfragt den Namen fuer jeden und uebergibt Zeiger
 * auf die Spieler an den Vector spielerListe
 */
void SpielFeld::spielerKreieren() {
    std::string name;
    std::cout << "Das Kniffel-Spiel f\x84 \bngt an:\n" << std::endl;
    std::cout << "Wie viele Spieler spielen mit? " << std::endl;
    unsigned int spielerAnzahl = io.readNumberBetween(1, 5);
    for (size_t i = 0; i < spielerAnzahl; i++) {
        std::cout << "Geben Sie den Namen des " << i + 1 << ". Spielers ein: " << std::endl;
        std::cin >> name;
        spielerListe.push_back(std::unique_ptr<Spieler>(new Spieler(name)));
    }
}

/**
 * Steuerung des Spiels:
 * Es gibt 13 Spielrunden und innerhalb dieser 13 Spielrunden
 */
void SpielFeld::spielen() {
    for (size_t i = 0; i < SPIELRUNDEN; i++) {
        std::cout << std::endl << "###### RUNDE " << i + 1 << " ######:" << std::endl;
        for (const auto& spieler : spielerListe) {
            std::cout << std::endl << std::endl << "SPIELER " << spieler->getName() << " IST AN DER REIHE!" << std::endl;
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

/**
 * Methode veranlasst, dass der Bonus und Gesamtpunktzahl fuer jeden Spieler ermittelt werden
 */
void SpielFeld::ergebnisErmitteln() {
    std::cout << std::endl << std::endl << "ERGEBNIS: " << std::endl;
    unsigned int gewinnerPunktzahl = 0;
    for (const auto& spieler : spielerListe) {
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
