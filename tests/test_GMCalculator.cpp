#include <gtest/gtest.h>
#include "ShipStabilityLib/StabilityAPI.h"

using namespace Stability;

/**
 * @brief Creates a simple test vessel with 2 weights.
 */
static Vessel createTestVessel() {
    Vessel v;
    v.name = "Test Vessel";
    v.LBP = 50.0;
    v.beam = 10.0;
    v.depth = 5.0;

    // Add two weights
    v.addWeight(Weight("Cargo", 100.0, 25.0, 0.0, 2.0)); // at 2 m above baseline
    v.addWeight(Weight("Ballast", 50.0, 10.0, 0.0, 1.0)); // at 1 m above baseline

    return v;
}

TEST(GMCalculatorTest, BasicGMComputation) {
    Vessel v = createTestVessel();

    // Call the API
    auto gm = StabilityAPI::computeGM(v);

    // Check KG
    // total moment = (100*2.0 + 50*1.0) = 250
    // total mass = 150 tons → KG = 250/150 = 1.666...
    EXPECT_NEAR(gm.KG, 1.666, 1e-3);

    // KM is a dummy 5.0 (hardcoded in GMCalculator for now)
    EXPECT_DOUBLE_EQ(gm.KM, 5.0);

    // GM = KM - KG = 5.0 - 1.666 = 3.333
    EXPECT_NEAR(gm.GM, 3.333, 1e-3);
}
