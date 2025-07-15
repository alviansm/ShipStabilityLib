/**
 * @file FreeSurfaceEffect.h
 * @brief Computes free surface correction for tanks.
 */

 #pragma once

 #include "ShipStabilityLib/Domain/Vessel.h"
 
 namespace Stability {
 
 /**
  * @brief Calculator for free surface correction.
  */
 class FreeSurfaceEffect {
 public:
     /**
      * @brief Computes free surface correction for the vessel.
      * @param vessel Vessel with tanks defined.
      * @return Correction value (m) to be subtracted from GM.
      */
     static double correction(const Vessel& vessel);
 };
 
 } // namespace Stability
 