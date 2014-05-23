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

// Erzeugt einen Array definierte Größe mit Zahlen
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
	// ASCII Code für obere Reihe - Würfelbegrenzung
	for (int a = 0; a < (int)name.size(); a++){
		printf("%c", 218);
		printf("%c", 196);
		printf("%c\t", 191);
	}
	printf("\n");
	// Mittlere Reihe - Würfelseiten + Zahl
	for (int a = 0; a < (int)name.size(); a++){
		printf("%c", 179);
		printf("%d", name[a]);
		printf("%c\t", 179);
	}
	printf("\n");
	// ASCII Code für untere Reihe - Würfelbegrenzung
	for (int a = 0; a < (int)name.size(); a++){
		printf("%c", 192);
		printf("%c", 196);
		printf("%c\t", 217);
	}
	printf("\n");
	// Würfelnummern
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

	// 3 Mal würfeln
	while (versuch < 4){
		// Würfelbecher leeren
		wuerfelNummer.clear();

		// Benötigt um die Anzahl der Würfel zu prüfen
		wiederholung = 6;
		// Beim ersten Versuch gleich alle 5 Würfel schmeißen
		if (versuch == 1){
			anzahl = 5;
			Wuerfelbecher::schuetteln(anzahl);
		}
		else{
			// Ob der Benutzer noch mal würfeln will?
			printf("M\x94 \bchten Sie weiter w\x81 \brfeln? j/n:");
			// Antwort lesen
			scanf("%c", &antwort);
			// Speicher löschen (sonst Fehler - die Eingabe wird beim nächsten Durchlauf gespeichert)
			fflush(stdin);
			printf("\n");

			// Falls "Ja"
			if (antwort == 'j'){
				// Nicht mehr als 5 Würfel
				while (wiederholung > 5){
					// Wie viele Würfel
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

				// Anzahl der Würfeln im Würfelbecher
				anzahl = wiederholung;

				// Array initialisieren, da steht, welche Würfeln neu definiert werden
				//wuerfelNummer = new int[anzahl];

				// Nummern von Würfen aufnehmen
				for (int a = 0; a < anzahl; a++){
					printf("Geben Sie den W\x81 \brfelnummer ein:");
					scanf("%d", &nummer);
					wuerfelNummer.push_back(nummer);
					fflush(stdin);
					printf("\n");
				}
				// mit neuen Anzhal der Würfen würfeln
				Wuerfelbecher::schuetteln(anzahl);
			}
			else{
				// Falls der Benutzer nicht mehr würfeln will
				versuch = 5;
			}
		}

		// Auswertung
		if (versuch != 5){
			// Alle Würfeln aus dem Würfenbecher in Ergebnis schreiben
			// Beim ersten Versuch einfach alle nehmen
			if (versuch == 1){
				Wuerfelbecher::ergebnis=Wuerfelbecher::wuerfelbecher;
			}else{
				for (int i = 0; i < anzahl; i++){
					// Bei nächsten Versuchen nur die Würfeln austauschen, die der Benutzer ausgewählt hat
					// Element einfügen
					Wuerfelbecher::ergebnis.insert(Wuerfelbecher::ergebnis.begin() + wuerfelNummer[i] - 1,(int)Wuerfelbecher::wuerfelbecher[i]);
					// Element löschen
					Wuerfelbecher::ergebnis.erase(Wuerfelbecher::ergebnis.begin() + wuerfelNummer[i]);
				}
			}

			// Anzeige
			// Wurfnummer
			printf("Wurfnummer: %d\n", versuch);
			// Welche Kombination gewürfelt wurde - nicht sortiert
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
