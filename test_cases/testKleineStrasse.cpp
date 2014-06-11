#include <gtest/gtest.h>
#include <vector>
#include "../header_files/kleineStrasse.h"

using namespace std;

TEST(KleineStrasseTest, testZero) {
    vector<unsigned int> wuerfel{4, 4, 4, 2, 5};
    KleineStrasse ks;
    ks.punkteBerechnen(wuerfel);
    EXPECT_EQ(0,ks.getPunktzahl());
}

TEST(KleineStrasseTest, testKsEinsBisVier) {
    vector<unsigned int> wuerfel{1, 4, 4, 2, 3};
    KleineStrasse ks;
    ks.punkteBerechnen(wuerfel);
    EXPECT_EQ(30,ks.getPunktzahl());
}

TEST(KleineStrasseTest, testKsZweiBisFuenf) {
    vector<unsigned int> wuerfel{5, 2, 4, 2, 3};
    KleineStrasse ks;
    ks.punkteBerechnen(wuerfel);
    EXPECT_EQ(30,ks.getPunktzahl());
}

TEST(KleineStrasseTest, testKsDreiBisSechs) {
    vector<unsigned int> wuerfel{5, 2, 4, 6, 3};
    KleineStrasse ks;
    ks.punkteBerechnen(wuerfel);
    EXPECT_EQ(30,ks.getPunktzahl());
}

