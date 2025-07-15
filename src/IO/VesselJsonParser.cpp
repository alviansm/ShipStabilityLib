#include "ShipStabilityLib/IO/VesselJsonParser.h"
// Later: include nlohmann/json or Qt JSON

namespace Stability {

Vessel VesselJsonParser::fromFile(const std::string& path) {
    Vessel v;
    // TODO: Implement JSON loading
    v.name = "Dummy Vessel";
    v.LBP = 50.0;
    v.beam = 10.0;
    v.depth = 5.0;
    return v;
}

void VesselJsonParser::toFile(const Vessel& vessel, const std::string& path) {
    // TODO: Implement JSON saving
}

} // namespace Stability
