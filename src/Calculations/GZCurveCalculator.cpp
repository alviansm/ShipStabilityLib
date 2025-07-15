#include "ShipStabilityLib/Calculations/GZCurveCalculator.h"

namespace Stability {

std::vector<GZCurveCalculator::Point> GZCurveCalculator::generate(const Vessel& vessel, double displacement) {
    std::vector<Point> curve;
    // Placeholder: later do real hydrostatic interpolation
    for (double heel = 0; heel <= 60; heel += 10.0) {
        curve.push_back({heel, 0.05 * heel}); // dummy linear GZ
    }
    return curve;
}

} // namespace Stability
