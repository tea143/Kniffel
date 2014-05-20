#include "grosseStrasse.h"

using namespace std;

GrosseStrasse::GrosseStrasse() : name {
    "GrosseStrasse"
}
{

}

int GrosseStrasse::punkteBerechnen(const vector<int> &augen) {
    punktzahl = 0;
    vector<int> temp = augen;
    sort(temp.begin(), temp.end());
    for (size_t i = 0; i < 4; i++) {
        if ((temp.at(i) + 1) != (temp.at(i + 1))) {
            cout << "Keine Grosse Strasse (1-2-3-4-5 / 2-3-4-5-6)" << endl;
            return 0;
        }
    }
    cout << "Grosse Strasse: ";
    return punktzahl = 40;
}

const string& GrosseStrasse::getName() const {
    return name;
}

void GrosseStrasse::setName(const string& name) {
    this->name = name;
}

void GrosseStrasse::setPunktzahl(int punktzahl) {
    this->punktzahl = punktzahl;
}

int GrosseStrasse::getPunktzahl() const {
    return punktzahl;
}
