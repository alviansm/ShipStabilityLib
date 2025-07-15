/**
 * @file GMCalculator.h
 * @brief Computes metacentric height (GM).
 */

 #pragma once

 #include "ShipStabilityLib/Domain/Vessel.h"
 
 namespace Stability {
 
 /**
  * @brief Calculator for basic transverse metacentric height.
  */
 class GMCalculator {
 public:
     /**
      * @brief GM result structure.
      */
     struct Result {
         double KG;  ///< Vertical CoG (m)
         double KM;  ///< Height of metacenter above keel (m)
         double GM;  ///< Metacentric height (m)
     };
 
     /**
      * @brief Compute GM for a given vessel.
      * @param vessel Vessel with hydrostatic data and weights.
      * @return Computed GM, KM, and KG.
      */
     static Result compute(const Vessel& vessel);
 };
 
 } // namespace Stability
 