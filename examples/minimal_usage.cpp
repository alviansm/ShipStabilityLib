#include <iostream>
#include "ShipStabilityLib/Version.h"
#include "ShipStabilityLib/StabilityAPI.h"

using namespace Stability;

int main() {
    std::cout << "ShipStabilityLib version: " << SHIPSTABILITYLIB_VERSION << "\n";

    Vessel v;
    v.name = "Demo Barge";
    v.LBP = 50.0;
    v.beam = 10.0;
    v.depth = 5.0;
    v.addWeight(Weight("Cargo", 100.0, 25.0, 0.0, 2.5));

    auto gm = StabilityAPI::computeGM(v);
    std::cout << "KG: " << gm.KG << " m, "
              << "KM: " << gm.KM << " m, "
              << "GM: " << gm.GM << " m\n";

    return 0;
}
