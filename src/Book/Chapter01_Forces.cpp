#include "ShipStabilityLib/Book/Chapter01_Forces.h"
#include <cmath>

namespace Stability::Book::Chapter01 {

double buoyantForce(double displacedVolume, double waterDensity) {
    return displacedVolume * waterDensity;
}

double equilibriumDifference(double weightShip, double displacedVolume, double waterDensity) {
    return buoyantForce(displacedVolume, waterDensity) - weightShip;
}

bool isInEquilibrium(double weightShip, double displacedVolume, double waterDensity) {
    double diff = equilibriumDifference(weightShip, displacedVolume, waterDensity);
    return std::fabs(diff) < 1e-6;
}

} // namespace Stability::Book::Chapter01
