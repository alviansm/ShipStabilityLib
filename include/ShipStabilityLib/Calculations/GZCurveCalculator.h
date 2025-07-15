/**
 * @file GZCurveCalculator.h
 * @brief Generates GZ (righting arm) curves.
 */

 #pragma once

 #include <vector>
 #include "ShipStabilityLib/Domain/Vessel.h"
 
 namespace Stability {
 
 /**
  * @brief GZ curve calculation for a given displacement.
  */
 class GZCurveCalculator {
 public:
     /**
      * @brief Represents a single point on the GZ curve.
      */
     struct Point {
         double heel; ///< Heel angle (deg)
         double GZ;   ///< Righting arm (m)
     };
 
     /**
      * @brief Generate a GZ curve for the vessel.
      * @param vessel Vessel with hydrostatic data.
      * @param displacement Displacement in tons.
      * @return A vector of heel vs GZ points.
      */
     static std::vector<Point> generate(const Vessel& vessel, double displacement);
 };
 
 } // namespace Stability
 