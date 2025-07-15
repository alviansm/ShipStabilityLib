#include "ShipStabilityLib/Calculations/GMCalculator.h"

namespace Stability {

GMCalculator::Result GMCalculator::compute(const Vessel& vessel) {
    Result r{};

    // 1. Get KG from vessel weights
    r.KG = vessel.KG();

    // 2. Placeholder KM (later: compute BM + KB)
    r.KM = 5.0; // dummy value for now

    // 3. GM = KM - KG
    r.GM = r.KM - r.KG;
    return r;
}

} // namespace Stability
