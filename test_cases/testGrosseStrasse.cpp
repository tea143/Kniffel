#include <gtest/gtest.h>
#include <vector>
#include "grosseStrasse.h"

using namespace std;

TEST(GrosseStrasseTest, testZero) {
    vector<unsigned int> wuerfel{4, 4, 4, 2, 5};
    GrosseStrasse gs;
    gs.punkteBerechnen(wuerfel);
    EXPECT_EQ(0,gs.getPunktzahl());
}

TEST(GrosseStrasseTest, testGsEinsBisFuenf) {
    vector<unsigned int> wuerfel{1, 4, 3, 2, 5};
    GrosseStrasse gs;
    gs.punkteBerechnen(wuerfel);
    EXPECT_EQ(40,gs.getPunktzahl());
}

TEST(GrosseStrasseTest, testGsZweiBisSechs) {
    vector<unsigned int> wuerfel{6, 4, 3, 2, 5};
    GrosseStrasse gs;
    gs.punkteBerechnen(wuerfel);
    EXPECT_EQ(40,gs.getPunktzahl());
}