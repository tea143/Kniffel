/*
 * Wuerfelbecher.cpp
 *
 *  Created on: 21.05.2014
 *      Author: Irina Fress
 */

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>


#include "Wuerfelbecher.h"
using namespace std;

Wuerfelbecher::Wuerfelbecher(){

}

Wuerfelbecher::~Wuerfelbecher(){

}

// Erzeugt einen Array definierte Gr��e mit Zahlen
int Wuerfelbecher::schuetteln(int anzahlWuerfel){
	// Becher leeren
	Wuerfelbecher::wuerfelbecher.clear();
	//wuerfelbecher = new int[anzahlWuerfel];
	for (int i = 0; i < anzahlWuerfel; i++){
		wuerfelbecher.push_back(Zufallszahl::rnd(1, 6));
	}
	return 0;
}

// Gibt der Array aus
void Wuerfelbecher::ausgabe(vector<int> name){
	//Ergebnis sortieren
	sort(Wuerfelbecher::ergebnis.begin(), Wuerfelbecher::ergebnis.end());
	// ASCII Code f�r obere Reihe - W�rfelbegrenzung
	for (int a = 0; a < (int)name.size(); a++){
		printf("%c", 218);
		printf("%c", 196);
		printf("%c\t", 191);
	}
	printf("\n");
	// Mittlere Reihe - W�rfelseiten + Zahl
	for (int a = 0; a < (int)name.size(); a++){
		printf("%c", 179);
		printf("%d", name[a]);
		printf("%c\t", 179);
	}
	printf("\n");
	// ASCII Code f�r untere Reihe - W�rfelbegrenzung
	for (int a = 0; a < (int)name.size(); a++){
		printf("%c", 192);
		printf("%c", 196);
		printf("%c\t", 217);
	}
	printf("\n");
	// W�rfelnummern
	printf("Nummern\n");
	for (int a = 0; a < (int)name.size(); a++){
		printf(" %d \t", a + 1);
	}
}

void Wuerfelbecher::wuerfeln(){
	int anzahl;
	int wiederholung;
	int nummer;
	vector<int> wuerfelNummer;
	char antwort;
	int versuch = 1;

	// 3 Mal w�rfeln
	while (versuch < 4){
		// W�rfelbecher leeren
		wuerfelNummer.clear();

		// Ben�tigt um die Anzahl der W�rfel zu pr�fen
		wiederholung = 6;
		// Beim ersten Versuch gleich alle 5 W�rfel schmei�en
		if (versuch == 1){
			anzahl = 5;
			Wuerfelbecher::schuetteln(anzahl);
		}
		else{
			// Ob der Benutzer noch mal w�rfeln will?
			printf("M\x94 \bchten Sie weiter w\x81 \brfeln? j/n:");
			// Antwort lesen
			scanf("%c", &antwort);
			// Speicher l�schen (sonst Fehler - die Eingabe wird beim n�chsten Durchlauf gespeichert)
			fflush(stdin);
			printf("\n");

			// Falls "Ja"
			if (antwort == 'j'){
				// Nicht mehr als 5 W�rfel
				while (wiederholung > 5){
					// Wie viele W�rfel
					printf("Wie viele W\x81 \brfel m\x94 \bchten Sie w\x81 \brfeln?");
					scanf("%d", &wiederholung);
					fflush(stdin);

					printf("\n");
					// Fehler zeigen
					if (wiederholung > 5){
						printf("Sie k\x94 \bnnen nicht her als 5 W\x81 \brfel nehmen.\n");
						printf("\n");
					}
				}

				// Anzahl der W�rfeln im W�rfelbecher
				anzahl = wiederholung;

				// Array initialisieren, da steht, welche W�rfeln neu definiert werden
				//wuerfelNummer = new int[anzahl];

				// Nummern von W�rfen aufnehmen
				for (int a = 0; a < anzahl; a++){
					printf("Geben Sie den W\x81 \brfelnummer ein:");
					scanf("%d", &nummer);
					wuerfelNummer.push_back(nummer);
					fflush(stdin);
					printf("\n");
				}
				// mit neuen Anzhal der W�rfen w�rfeln
				Wuerfelbecher::schuetteln(anzahl);
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
				Wuerfelbecher::ergebnis=Wuerfelbecher::wuerfelbecher;
			}else{
				for (int i = 0; i < anzahl; i++){
					// Bei n�chsten Versuchen nur die W�rfeln austauschen, die der Benutzer ausgew�hlt hat
					// Element einf�gen
					Wuerfelbecher::ergebnis.insert(Wuerfelbecher::ergebnis.begin() + wuerfelNummer[i] - 1,(int)Wuerfelbecher::wuerfelbecher[i]);
					// Element l�schen
					Wuerfelbecher::ergebnis.erase(Wuerfelbecher::ergebnis.begin() + wuerfelNummer[i]);
				}
			}

			// Anzeige
			// Wurfnummer
			printf("Wurfnummer: %d\n", versuch);
			// Welche Kombination gew�rfelt wurde - nicht sortiert
			printf("Gew\x81 \brfelt:\n");
			Wuerfelbecher::ausgabe(Wuerfelbecher::wuerfelbecher);
			printf("\n\n");
			// Was im Ergebnis steht - sortiert
			printf("Ergebnis:\n");
			Wuerfelbecher::ausgabe(Wuerfelbecher::ergebnis);
			printf("\n\n");
			versuch++;
		}
	}
}
