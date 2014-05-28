#include <gtest/gtest.h>
#include <vector>
#include "kniffel.h"

using namespace std;

TEST(KniffelTest, testZero) {
    vector<int> wuerfel{4, 4, 4, 2, 5};
    Kniffel k;
    k.punkteBerechnen(wuerfel);
    EXPECT_EQ(0, k.getPunktzahl());
}

TEST(KniffelTest, testKniffel) {
    vector<int> wuerfel{4, 4, 4, 4, 4};
    Kniffel k;
    k.punkteBerechnen(wuerfel);
    EXPECT_EQ(50, k.getPunktzahl());
}

TEST(KniffelTest, testKniffelAndereZahlen) {
    vector<int> wuerfel{1, 1, 1, 1, 1};
    Kniffel k;
    k.punkteBerechnen(wuerfel);
    EXPECT_EQ(50, k.getPunktzahl());
}