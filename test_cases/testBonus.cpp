#include <gtest/gtest.h>
#include <vector>
#include "../header_files/spieler.h"

using namespace std;

TEST(BonusTest, testBonus) {
    Spieler s("Testspieler");
    for (size_t i = 0; i < 6; i++) {
        unsigned int z = i + 1;
        vector<unsigned int> v {z, z, z, z, z};
        s.getKategorienListe().at(i)->punkteBerechnen(v);
    }
    s.bonusErmitteln();
    EXPECT_EQ(35, s.getPunktzahl());
}

TEST(BonusTest, testKeinBonus) {
    Spieler s("Testspieler");
    for (size_t i = 0; i < 6; i++) {
        unsigned int z = i + 1;
        vector<unsigned int> v {z, z, 0, 0, 0};
        s.getKategorienListe().at(i)->punkteBerechnen(v);
    }
    s.bonusErmitteln();
    EXPECT_EQ(0, s.getPunktzahl());
}
