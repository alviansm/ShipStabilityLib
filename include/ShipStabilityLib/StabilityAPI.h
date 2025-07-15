/**
 * @file StabilityAPI.h
 * @brief High-level facade for all stability calculations.
 */

 #pragma once

 #include "ShipStabilityLib/Domain/Vessel.h"
 #include "ShipStabilityLib/Calculations/GMCalculator.h"
 #include "ShipStabilityLib/Calculations/FreeSurfaceEffect.h"
 #include "ShipStabilityLib/Calculations/GZCurveCalculator.h"
 
 namespace Stability {
 
 /**
  * @brief Facade providing a simple API for stability calculations.
  */
 class StabilityAPI {
 public:
    static const char* version();

     /**
      * @brief Compute GM for a given vessel.
      */
     static GMCalculator::Result computeGM(const Vessel& vessel);
 
     /**
      * @brief Compute free surface correction for a vessel.
      */
     static double computeFreeSurfaceCorrection(const Vessel& vessel);
 
     /**
      * @brief Generate a GZ curve for a vessel at a given displacement.
      */
     static std::vector<GZCurveCalculator::Point> computeGZCurve(
         const Vessel& vessel, double displacement);
 };
 
 } // namespace Stability
 