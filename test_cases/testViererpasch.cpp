#include <gtest/gtest.h>
#include <vector>
#include "../header_files/viererpasch.h"

using namespace std;

TEST(ViererpaschTest, testZero) {
    vector<int> wuerfel{2, 4, 4, 4, 5};
    Viererpasch vp;
    vp.punkteBerechnen(wuerfel);
    EXPECT_EQ(0,vp.getPunktzahl());
}

TEST(ViererpaschTest, testViererpasch) {
    vector<int> wuerfel{2, 2, 2, 2, 5};
    Viererpasch vp;
    vp.punkteBerechnen(wuerfel);
    EXPECT_EQ(13,vp.getPunktzahl());
}

TEST(ViererpaschTest, testViererpaschUngeordnet) {
    vector<int> wuerfel{5, 5, 2, 5, 5};
    Viererpasch vp;
    vp.punkteBerechnen(wuerfel);
    EXPECT_EQ(22,vp.getPunktzahl());
}
