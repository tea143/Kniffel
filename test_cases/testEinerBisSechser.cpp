#include "einerBisSechser.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(EinerBisSechserTest, testZero) {
    vector<unsigned int> wuerfel{2, 3, 4, 4, 5};
    EinerBisSechser ebs(6, "Sechser");
    ebs.punkteBerechnen(wuerfel);
    EXPECT_EQ(0, ebs.getPunktzahl());
}

TEST(EinerBisSechserTest, testOneEqualEiner) {
    vector<unsigned int> wuerfel{2, 1, 4, 5, 4};
    EinerBisSechser ebs(1, "Einer");
    ebs.punkteBerechnen(wuerfel);
    EXPECT_EQ(1, ebs.getPunktzahl());
} 

TEST(EinerBisSechserTest, testTwoEqualZweier) {
    vector<unsigned int> wuerfel{2, 2, 4, 1, 1};
    EinerBisSechser ebs(2, "Zweier");
    ebs.punkteBerechnen(wuerfel);
    EXPECT_EQ(4, ebs.getPunktzahl());
} 

TEST(EinerBisSechserTest, testThreeEqualDreier) {
    vector<unsigned int> wuerfel{3, 3, 4, 3, 1};
    EinerBisSechser ebs(3, "Dreier");
    ebs.punkteBerechnen(wuerfel);
    EXPECT_EQ(9, ebs.getPunktzahl());
} 

TEST(EinerBisSechserTest, testFourEqualVierer) {
    vector<unsigned int> wuerfel{4, 4, 4, 3, 4};
    EinerBisSechser ebs(4, "Vierer");
    ebs.punkteBerechnen(wuerfel);
    EXPECT_EQ(16, ebs.getPunktzahl());
} 

TEST(EinerBisSechserTest, testFiveEqualFuenfer) {
    vector<unsigned int> wuerfel{5, 5, 5, 5, 5};
    EinerBisSechser ebs(5, "Fünfer");
    ebs.punkteBerechnen(wuerfel);
    EXPECT_EQ(25, ebs.getPunktzahl());
} 