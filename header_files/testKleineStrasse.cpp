#include <gtest/gtest.h>
#include <vector>
#include "kleineStrasse.h"

using namespace std;

TEST(KleineStrasseTest, testZero) {
    vector<int> wuerfel{4, 4, 4, 2, 5};
    KleineStrasse ks;
    ks.punkteBerechnen(wuerfel);
    EXPECT_EQ(0,ks.getPunktzahl());
}

TEST(KleineStrasseTest, testKsEinsBisVier) {
    vector<int> wuerfel{1, 4, 4, 2, 3};
    KleineStrasse ks;
    ks.punkteBerechnen(wuerfel);
    EXPECT_EQ(30,ks.getPunktzahl());
}

TEST(KleineStrasseTest, testKsZweiBisFuenf) {
    vector<int> wuerfel{5, 2, 4, 2, 3};
    KleineStrasse ks;
    ks.punkteBerechnen(wuerfel);
    EXPECT_EQ(30,ks.getPunktzahl());
}

TEST(KleineStrasseTest, testKsDreiBisSechs) {
    vector<int> wuerfel{5, 2, 4, 6, 3};
    KleineStrasse ks;
    ks.punkteBerechnen(wuerfel);
    EXPECT_EQ(30,ks.getPunktzahl());
}
