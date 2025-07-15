#include <gtest/gtest.h>
#include "ShipStabilityLib/Book/Chapter01_Forces.h"

using namespace Stability::Book::Chapter01;

TEST(Book_Chapter01_Forces, BuoyantForceSeawater) {
    EXPECT_NEAR(buoyantForce(1000.0, 1.025), 1025.0, 1e-6);
}

TEST(Book_Chapter01_Forces, EquilibriumDifference) {
    double diff = equilibriumDifference(1025.0, 1000.0, 1.025);
    EXPECT_NEAR(diff, 0.0, 1e-6);

    EXPECT_GT(equilibriumDifference(900.0, 1000.0, 1.025), 0.0);
    EXPECT_LT(equilibriumDifference(1200.0, 1000.0, 1.025), 0.0);
}

TEST(Book_Chapter01_Forces, IsInEquilibrium) {
    EXPECT_TRUE(isInEquilibrium(1025.0, 1000.0, 1.025));
    EXPECT_FALSE(isInEquilibrium(1000.0, 1000.0, 1.025));
}
