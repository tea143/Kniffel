#include "Spielfeld.h"
#include "Wuerfelbecher.h"

using namespace std;

SpielFeld::SpielFeld(size_t anzahl)
: spielerAnzahl {
    anzahl
}
{
}

const size_t SpielFeld::getSpielerAnzahl() const {
    return spielerAnzahl;
}

vector <Spieler> SpielFeld::spielerKreieren() {
    string name;
    for (size_t i = 0; i < spielerAnzahl; i++) {
        cout << "Geben Sie den Namen des " << i + 1 << ". Spielers ein: " << endl;
        cin >> name;
        Spieler spieler(name);
        spielerListe.push_back(spieler);
    }
    return spielerListe;
}

void SpielFeld::spielerAnzeigen() {
    for (auto& spieler : spielerListe) {
        cout << "Spieler: " << spieler.getName() << endl;
    }
}

const vector<Spieler>& SpielFeld::getSpielerListe() const {
    return spielerListe;
}

void SpielFeld::spielen() {
	int anzahl;
	int wiederholung;
	int nummer;
	vector<int> wuerfelNummer;
	char antwort;
	int versuch;

	for (size_t i = 0; i < SPIELRUNDEN; i++) {
        cout << endl << "###### RUNDE " << i + 1 << " ######:" << endl;
        for (auto& spieler : spielerListe) {
            cout << endl << "Spieler " << spieler.getName() << " ist an der Reihe!" << endl;
            spieler.printFreieKategorien();
            Wuerfelbecher becher;

            //wuerfel = {3, 3, 3, 3, 3};
            // 3 Mal w�rfeln
			for (versuch = 1; versuch < 4; versuch++){
				printf("Versuch %d\n",versuch);
				// W�rfelbecher leeren
				wuerfelNummer.clear();

				// Ben�tigt um die Anzahl der W�rfel zu pr�fen
				wiederholung = 6;
				// Beim ersten Versuch gleich alle 5 W�rfel schmei�en
				if (versuch == 1){
					anzahl = 5;
					becher.schuetteln(anzahl);
				}
				else{
					// Ob der Benutzer noch mal w�rfeln will?
					//printf("M\x94 \bchtest du weiter w\x81 \brfeln? j/n:");
					cout << "M\x94 \bchtest du weiter w\x81 \brfeln? j/n:" << endl;
					// Antwort lesen
					//scanf("%c", &antwort);
					cin >> antwort;
					// Speicher l�schen (sonst Fehler - die Eingabe wird beim n�chsten Durchlauf gespeichert)
					fflush(stdin);
					printf("\n");

					// Falls "Ja"
					if (antwort == 'j'){
						// Nicht mehr als 5 W�rfel
						while (wiederholung > 5){
							// Wie viele W�rfel
							printf("Wie viele W\x81 \brfel m\x94 \bchtest Sie w\x81 \brfeln?");
							scanf("%d", &wiederholung);
							fflush(stdin);

							printf("\n");
							// Fehler zeigen
							if (wiederholung > 5){
								printf("Du kannst nicht her als 5 W\x81 \brfel nehmen.\n");
								printf("\n");
							}
						}

						// Anzahl der W�rfeln im W�rfelbecher
						anzahl = wiederholung;

						// Array initialisieren, da steht, welche W�rfeln neu definiert werden
						//wuerfelNummer = new int[anzahl];

						// Nummern von W�rfen aufnehmen
						for (int a = 0; a < anzahl; a++){
							printf("Gib den W\x81 \brfelnummer ein:");
							scanf("%d", &nummer);
							wuerfelNummer.push_back(nummer);
							fflush(stdin);
							printf("\n");
						}
						// mit neuen Anzhal der W�rfen w�rfeln
						becher.schuetteln(anzahl);
					}
					else{
						// Falls der Benutzer nicht mehr w�rfeln will
						versuch = 5;
					}
				}

				// Auswertung
				if (versuch != 5){
					// Alle W�rfeln aus dem W�rfenbecher in Ergebnis schreiben
					// Beim ersten Versuch einfach alle nehmen
					if (versuch == 1){
						becher.ergebnis=becher.wuerfelbecher;
					}else{
						for (int i = 0; i < anzahl; i++){
							// Bei n�chsten Versuchen nur die W�rfeln austauschen, die der Benutzer ausgew�hlt hat
							// Element einf�gen
							becher.ergebnis.insert(becher.ergebnis.begin() + wuerfelNummer[i] - 1,(int)becher.wuerfelbecher[i]);
							// Element l�schen
							becher.ergebnis.erase(becher.ergebnis.begin() + wuerfelNummer[i]);
						}
					}

					// Anzeige
					// Wurfnummer
					printf("Wurfnummer: %d\n", versuch);
					// Welche Kombination gew�rfelt wurde - nicht sortiert
					printf("Gew\x81 \brfelt:\n");
					becher.ausgabe(becher.wuerfelbecher);
					printf("\n\n");
					// Was im Ergebnis steht - sortiert
					printf("Ergebnis:\n");
					becher.ausgabe(becher.ergebnis);
					printf("\n\n");

				}
			}




            wuerfel = becher.ergebnis;



            //cout << "Gebe Nummer der Würfel aus, die du wieder in der Würfelbecher werfen willst!" << endl;
            cout << "Waehle eine freie Kategorie (Zahl): " << endl;
            EinAusgabe io;
            size_t kategorie = io.readNumberBetween(0, SPIELRUNDEN - 1);
            spieler.punktzahlErmitteln(kategorie, wuerfel);
        }
    }
}

/*void wuerfeln() {

}*/

void SpielFeld::ergebnisErmitteln() {
    cout << endl << endl << "ERGEBNIS: " << endl;
    size_t gewinnerPunktzahl = 0;
    for (auto& spieler : spielerListe) {
        spieler.bonusErmitteln();
        cout << spieler.getName() << " hat " << spieler.getPunktzahl() << " Punkte erreicht." << endl;
        if (spieler.getPunktzahl() > gewinnerPunktzahl) {
            gewinnerPunktzahl = spieler.getPunktzahl();
        }
    }
    cout << endl << "GEWINNER: " << endl;
    for (auto& spieler : spielerListe) {
        if (gewinnerPunktzahl == spieler.getPunktzahl()) {
            cout << spieler.getName() << endl;
        }
    }
}
