#include <gtest/gtest.h>
#include <vector>
#include "chance.h"

using namespace std;

TEST(ChanceTest, testChance) {
    vector<int> wuerfel{4, 4, 4, 2, 5};
    Chance c;
    c.punkteBerechnen(wuerfel);
    EXPECT_EQ(19, c.getPunktzahl());
}

TEST(ChanceTest, testAndereZahlen) {
    vector<int> wuerfel{1, 4, 3, 2, 5};
    Chance c;
    c.punkteBerechnen(wuerfel);
    EXPECT_EQ(15, c.getPunktzahl());
}