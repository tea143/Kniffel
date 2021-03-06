#include <gtest/gtest.h>
#include <vector>
#include "../header_files/fullHouse.h"

using namespace std;

TEST(FullhouseTest, testZero) {
    vector<unsigned int> wuerfel{4, 4, 4, 2, 5};
    Fullhouse fh;
    fh.punkteBerechnen(wuerfel);
    EXPECT_EQ(0,fh.getPunktzahl());
}

TEST(FullhouseTest, testFullhouse) {
    vector<unsigned int> wuerfel{4, 4, 4, 2, 2};
    Fullhouse fh;
    fh.punkteBerechnen(wuerfel);
    EXPECT_EQ(25,fh.getPunktzahl());
}

TEST(FullhouseTest, testFullhousePairFirst) {
    vector<unsigned int> wuerfel{1, 1, 3, 3, 3};
    Fullhouse fh;
    fh.punkteBerechnen(wuerfel);
    EXPECT_EQ(25,fh.getPunktzahl());
}

TEST(FullhouseTest, testFullhouseUngeordnet) {
    vector<unsigned int> wuerfel{6, 5, 5, 6, 6};
    Fullhouse fh;
    fh.punkteBerechnen(wuerfel);
    EXPECT_EQ(25,fh.getPunktzahl());
}

