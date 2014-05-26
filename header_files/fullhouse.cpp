#include "fullhouse.h"

Fullhouse::Fullhouse()
	:name {"Fullhouse"}{
		//std::cout << "Fullhouse-Objekt wurde erzeugt.\n";
}

Fullhouse::~Fullhouse(){
	//std::cout << "Fullhouse-Objekt wurde beendet.\n";
}

int Fullhouse::punkteBerechnen(const std::vector<int> &augen) {
    punktzahl = 0;
    std::vector<int> temp = augen;
    //sort(temp.begin(), temp.end(), greater<int>());
    sort(temp.begin(), temp.end());
    if ((temp[0] == temp[1] && temp[1] == temp[2] && temp[3] == temp[4]) ||
            (temp[0] == temp[1] && temp[2] == temp[3] && temp[3] == temp[4])) {
        std::cout << "Full House: ";
        return punktzahl = 25;
    } else {
        std::cout << "Kein Full House (Zweierpasch + Dreierpasch)" << std::endl;
    }

    return 0;
}

const std::string& Fullhouse::getName() const {
    return name;
}

void Fullhouse::setName(const std::string& name) {
    this->name = name;
}

void Fullhouse::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int Fullhouse::getPunktzahl() const {
    return punktzahl;
}
