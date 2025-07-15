#include "ShipStabilityLib/StabilityAPI.h"
#include "ShipStabilityLib/Version.h"

namespace Stability {

const char* StabilityAPI::version() {
    return SHIPSTABILITYLIB_VERSION;
}

GMCalculator::Result StabilityAPI::computeGM(const Vessel& vessel) {
    return GMCalculator::compute(vessel);
}

double StabilityAPI::computeFreeSurfaceCorrection(const Vessel& vessel) {
    return FreeSurfaceEffect::correction(vessel);
}

std::vector<GZCurveCalculator::Point>
StabilityAPI::computeGZCurve(const Vessel& vessel, double displacement) {
    return GZCurveCalculator::generate(vessel, displacement);
}

} // namespace Stability
