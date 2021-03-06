#include <gtest/gtest.h>
#include <vector>
#include "../header_files/dreierpasch.h"

using namespace std;

TEST(DreierpaschTest, testZero) {
    vector<unsigned int> wuerfel{2, 3, 4, 4, 5};
    Dreierpasch dp;
    dp.punkteBerechnen(wuerfel);
    EXPECT_EQ(0,dp.getPunktzahl());
}

TEST(DreierpaschTest, testDreierpasch) {
    vector<unsigned int> wuerfel{3, 3, 3, 4, 5};
    Dreierpasch dp;
    dp.punkteBerechnen(wuerfel);
    EXPECT_EQ(18,dp.getPunktzahl());
}

TEST(DreierpaschTest, testDreierpaschUngeordnet) {
    vector<unsigned int> wuerfel{4, 3, 5, 4, 4};
    Dreierpasch dp;
    dp.punkteBerechnen(wuerfel);
    EXPECT_EQ(20,dp.getPunktzahl());
}

